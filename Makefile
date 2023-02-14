NAME:=fractol

##############################
#### compilation settings ####
##############################

CC=cc
CFLAGS= -Wall -Wextra -Werror
ifdef FSANITIZE
	CFLAGS+= -g3 -fsanitize=address
else
	CFLAGS+= -flto -O3
endif

#######################
#### project files ####
#######################

COMPLEX_SRC:= \
	complex/complex.c \
	complex/arithematic.c \
	complex/equation.c \
	complex/distance_estimator.c
CANVAS_SRC:= \
	canvas/canvas.c \
	canvas/canvas_setters.c \
	canvas/viewport.c \
	canvas/translation_calculator.c \
	canvas/distance_map.c
BORDER_TRACER_SRC:= \
	painter/border_tracer/border_tracer.c \
	painter/border_tracer/tracer.c
PAINTER_SRC:= \
	painter/painter.c \
	painter/fractal_painter.c \
	painter/animation.c \
	painter/color.c \
	painter/pixel_copier.c
CONTEXT_SRC:= \
	context/context.c \
	context/controls.c \
	context/animation_controller.c \
	context/translation.c \
	context/zoom_calculator.c
SRC:= \
	main.c \
	hooks.c \
	cli.c \
	error_printer.c
OBJS=${COMPLEX_SRC:.c=.o} ${CANVAS_SRC:.c=.o} ${BORDER_TRACER_SRC:.c=.o} ${PAINTER_SRC:.c=.o} ${CONTEXT_SRC:.c=.o} ${SRC:.c=.o}
OBJS=${addprefix src/,${OBJS}}

########################
####   debug files  ####
########################

OBJS+=${if ${findstring -g3,${CFLAGS}},${DEBUG_OBJS},}

########################
####    libaries    ####
########################

GLFW:=lib/glfw-3.3.8/lib-universal/libglfw3.a
MLX:=lib/MLX42/libmlx42.a

########################
####  dependencies  ####
########################

DEPS:= ${GLFW} ${MLX} ${OBJS}
INCLUDE:= \
	lib/MLX42/include \
	include \
	${DEBUG_LIB}

all: ${NAME}

${NAME}: ${DEPS}
	@${CC} ${CFLAGS} ${DEPS} -framework Cocoa -framework OpenGL -framework IOKit -o ${NAME} && \
		echo "Compilation successful"

${MLX}:
	@make ${if ${findstring -g3,${CFLAGS}},DEBUG=1,} HEADERS='-I ../glfw-3.3.8/include/' -C lib/MLX42/

%.o: %.c
	@${CC} ${CFLAGS} ${addprefix -I ,${INCLUDE}} -c $< -o $@

clean:
	@make clean -C MLX42/
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${NAME} ${MLX}

re: fclean all

bonus: re