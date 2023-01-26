NAME:=fractol

##############################
#### compilation settings ####
##############################

CC=cc
CFLAGS= -Wall -Wextra -Werror -Ofast
ifdef FSANITIZE
	CFLAGS+= -g3 -fsanitize=address
endif

#######################
#### project files ####
#######################

COMPLEX_SRC:= \
	complex/arithematic.c \
	complex/complex.c \
	complex/equation.c \
	complex/distance_estimator.c
VIEWPORT_SRC:= \
	viewport/viewport.c \
	viewport/viewport_setter.c
PAINTER_SRC:= \
	painter/translation.c \
	painter/pixel_copier.c \
	painter/mandelbrot.c
SRC:= \
	main.c \
	hooks.c
OBJS=${COMPLEX_SRC:.c=.o} ${VIEWPORT_SRC:.c=.o} ${PAINTER_SRC:.c=.o} ${SRC:.c=.o}

########################
####   debug files  ####
########################

OBJS+=${if ${findstring -g3,${CFLAGS}},${DEBUG_OBJS},}

########################
####    libaries    ####
########################

GLFW:=glfw-3.3.8/lib-universal/libglfw3.a
MLX:=MLX42/libmlx42.a

########################
####  dependencies  ####
########################

DEPS:= ${GLFW} ${MLX} ${OBJS}
INCLUDE:= \
	MLX42/include \
	complex \
	viewport \
	painter \
	${DEBUG_LIB}

all: ${NAME}

${NAME}: ${DEPS}
	@${CC} ${CFLAGS} ${DEPS} -framework Cocoa -framework OpenGL -framework IOKit -o ${NAME} && \
		echo "Compilation successful"

${MLX}:
	@make ${if ${findstring -g3,${CFLAGS}},DEBUG=1,} HEADERS='-I ../glfw-3.3.8/include/' -C MLX42/

%.o: %.c
	@${CC} ${CFLAGS} ${addprefix -I ,${INCLUDE}} -c $< -o $@

clean:
	@make clean -C MLX42/
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${NAME} ${MLX}

re: fclean all

bonus: re