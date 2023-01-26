NAME:=debug.out

CC:=cc
CFLAGS=-Wall -Wextra -Wformat -Ofast
# CFLAGS+= -fsanitize=address -g3

TARGET_DIR:=../src
TARGETS=${addprefix ${TARGET_DIR},${TARGET_NAMES}}
TARGETS_OBJ=${TARGETS:.c=.o}

TESTS:=$(shell find tests -name '*.c')
TESTS_OBJS=${TESTS:.c=.o}

ifneq (,$(findstring -g,$(CFLAGS)))
	DEBUG_SRC:=${addprefix ${shell pwd}/,$(shell find debug -name '*.c')}
	DEBUG_LIB:=${addprefix ${shell pwd}/,debug}
	GFLAG:=yes
endif

define create_test
${1}: LIB=$${addprefix -I $${TARGET_DIR}, /${1}}
${1}: TARGETS=$$(shell find $${LIB} -name '*.c')
${1}: targetobjects $${TESTS_OBJS}
	@$${CC} $${CFLAGS} -I $${LIB} main.c $${TESTS_OBJS} $${TARGETS_OBJ} -o $${NAME} && \
	echo "Success compiling $${TARGETS}!"
endef

# Test rules

$(eval $(call create_test,complex))

# Basic rules

%.o: %.c
	@${CC} ${CFLAGS} ${LIB} -c $< -o $@

clean: targetclean
	@rm -f ${TESTS_OBJS} ${DEBUG_SRC:.c=.o}

fclean: targetfclean clean
	@rm -f ${NAME}

re: fclean all

# Target rules

fractol: targetall
	${TARGET_DIR}/fractol

targetall: LIB=${addprefix -I ${TARGET_DIR}, /painter/ /MLX42/include/ /complex/}
targetall: ${DEBUG_SRC:.c=.o}
	@make GFLAG=${GFLAG} DEBUG_LIB="${DEBUG_LIB}" DEBUG_OBJS="${DEBUG_SRC:.c=.o}" -C ${TARGET_DIR}

targetobjects: ${DEBUG_SRC:.c=.o}
	@make GFLAG=${GFLAG} DEBUG_LIB="${DEBUG_LIB}" DEBUG_OBJS="${DEBUG_SRC:.c=.o}" ${TARGETS_OBJ} -C ${TARGET_DIR}

targetclean:
	@make clean -C ${TARGET_DIR}

targetfclean:
	@make fclean -C ${TARGET_DIR}