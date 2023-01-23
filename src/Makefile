NAME:=fractol
COMPLEX_SRC:= \
	complex/arithematic.c \
	complex/complex.c \
	complex/equation.c \
	complex/distance_estimator.c
PAINTER_SRC:= \
	painter/painter.c
SRC:= main.c
OBJS=${SRC:.c=.o} ${COMPLEX_SRC:.c=.o} ${PAINTER_SRC:.c=.o} ${MLX}

GLFW:=glfw-3.3.8/lib-x86_64/libglfw3.a
MLX:=MLX42/libmlx42.a

INCLUDE:= \
	MLX42/include \
	complex \
	painter

CC=cc
CFLAGS= -Wall -Wextra -Werror
CFLAGS+= -g3 -fsanitize=address

all: ${NAME}

${NAME}: ${GLFW} ${OBJS}
	@${CC} ${CFLAGS} ${GLFW} ${OBJS} -framework Cocoa -framework OpenGL -framework IOKit -o ${NAME} && \
		echo "Compilation successful"

%.o: %.c
	${CC} ${CFLAGS} ${addprefix -I ,${INCLUDE}} -c $< -o $@

${MLX}:
	@make --debug HEADERS='-I ../glfw-3.3.8/include/' -C MLX42/

clean: 
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean all

bonus: re