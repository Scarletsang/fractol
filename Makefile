NAME:=fractol

##############################
#### compilation settings ####
##############################

CC=cc
CFLAGS= -Wall -Wextra -Werror
LDFLAGS=-lm
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
	complex/distance_estimator.c \
	complex/fractal_func.c
CANVAS_SRC:= \
	canvas/canvas.c \
	canvas/color_controls.c \
	canvas/viewport.c \
	canvas/distance_map.c
BORDER_TRACER_SRC:= \
	painter/border_tracer/border_tracer.c \
	painter/border_tracer/tracer.c
PAINTER_SRC:= \
	painter/painter.c \
	painter/fractal_painter.c \
	painter/color.c
CONTEXT_SRC:= \
	context/controls.c \
	context/effects.c
CLI_SRC:= \
	cli/parser.c \
	cli/parser_utils.c \
	cli/error_printer.c
ANIMATION_SRC:= \
	animation/animation.c \
	animation/animation_controller.c
TRANSLATION_SRC:= \
	translation/copier.c \
	translation/copier_func.c \
	translation/translation_calculator.c \
	translation/translation.c
SRC:= \
	main.c \
	hooks.c
OBJS=${addprefix src/,${COMPLEX_SRC:.c=.o} ${CANVAS_SRC:.c=.o} ${BORDER_TRACER_SRC:.c=.o} ${PAINTER_SRC:.c=.o} ${CONTEXT_SRC:.c=.o} ${TRANSLATION_SRC:.c=.o} ${ANIMATION_SRC:.c=.o} ${CLI_SRC:.c=.o} ${SRC:.c=.o}}

########################
####   debug files  ####
########################

OBJS+=${if ${findstring -g3,${CFLAGS}},${DEBUG_OBJS},}

########################
####    libaries    ####
########################

ifeq (${shell uname}, Darwin)
	LDFLAGS+= -L ./lib/glfw-3.3.8/lib-universal/ -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
else
	LDFLAGS+= -L ./lib/glfw-3.3.8/lib-x86_64/ -lglfw3 -ldl
endif
LDFLAGS+= -L ./lib/MLX42/ -lmlx42

########################
####  dependencies  ####
########################

DEPS:= ${OBJS}
INCLUDE:= \
	lib/MLX42/include \
	include

all: ${NAME}

${NAME}: MLX ${DEPS}
	@${CC} ${DEPS} -o ${NAME} ${LDFLAGS} && \
		echo "Compilation successful"

MLX:
	@make ${if ${findstring -g3,${CFLAGS}},DEBUG=1,} HEADERS='-I ../glfw-3.3.8/include/' -C lib/MLX42/

%.o: %.c
	@${CC} ${CFLAGS} ${addprefix -I ,${INCLUDE}} -c $< -o $@

clean:
	@make clean -C lib/MLX42/
	@rm -f ${OBJS}

fclean: clean
	@make fclean -C lib/MLX42/
	@rm -f ${NAME}

re: fclean all

bonus: re

.PHONY: clean fclean re bonus