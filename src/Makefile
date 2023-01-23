NAME:=fractol
COMPLEX_SRC:= \
	complex/arithematic.c \
	complex/complex.c \
	complex/equation.c \
	complex/distance_estimator.c
SRC:= main.c
OBJS=${SRC:.c=.o} ${COMPLEX_SRC:.c=.o} ${MLX}

GLFW:=glfw-3.3.8/lib-x86_64/libglfw3.a
MLX:=MLX42/libmlx42.a

INCLUDE:= \
	MLX42/include \
	complex

CC=cc
FLAGS= -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${GLFW} ${OBJS}
	@${CC} ${GLFW} ${OBJS} -framework Cocoa -framework OpenGL -framework IOKit -o ${NAME} && \
		echo "Compilation successful"

%.o: %.c
	@${CC} ${CFLAGS} -I ${INCLUDE} -c $< -o $@

${MLX}:
	@make HEADERS='-I ../glfw-3.3.8/include/' -C MLX42/

clean: 
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean all

bonus: re