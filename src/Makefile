NAME:=fractol

#######################
#### project files ####
#######################

COMPLEX_SRC:= \
	complex/arithematic.c \
	complex/complex.c \
	complex/equation.c \
	complex/distance_estimator.c
PAINTER_SRC:= \
	painter/painter.c \
	painter/viewport.c
SRC:= \
	main.c \
	hooks.c
OBJS=${SRC:.c=.o} ${COMPLEX_SRC:.c=.o} ${PAINTER_SRC:.c=.o}

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
	painter

##############################
#### compilation settings ####
##############################

CC=cc
CFLAGS= -Wall -Wextra -Werror -Ofast
# CFLAGS+= -g3 -fsanitize=address

all: ${NAME}

${NAME}: ${DEPS}
	@${CC} ${CFLAGS} ${DEPS} -framework Cocoa -framework OpenGL -framework IOKit -o ${NAME} && \
		echo "Compilation successful"

${MLX}:
	make ${if ${findstring -g3,${CFLAGS}},--debug,} HEADERS='-I ../glfw-3.3.8/include/' -C MLX42/

%.o: %.c
	@${CC} ${CFLAGS} ${addprefix -I ,${INCLUDE}} -c $< -o $@

clean:
	@make clean -C MLX42/
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${NAME} ${MLX}

re: fclean all

bonus: re