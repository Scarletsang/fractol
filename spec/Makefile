# Please only change the following line

NAME:=debug.out
TARGET_DIR:=../src
TESTS:=$(shell find tests -name '*.c')
TARGETS=${addprefix ${TARGET_DIR},${TARGET_NAMES}}
TARGETS_OBJ=${TARGETS:.c=.o}
TESTS_OBJS=${TESTS:.c=.o}
CC:=cc
CFLAGS=-Wall -Wextra -Wformat
CFLAGS+= -fsanitize=address -g3

define create_test
${1}: LIB=$${addprefix $${TARGET_DIR}, /${1}}
${1}: TARGETS=$$(shell find $${LIB} -name '*.c')
${1}: targetobjects $${TESTS_OBJS}
	@$${CC} $${CFLAGS} -I $${LIB} main.c $${TESTS_OBJS} $${TARGETS_OBJ} -o $${NAME} && \
	echo "Success compiling $${TARGETS}!"
endef

# Test rules

$(eval $(call create_test,complex))

# Basic rules

%.o: %.c
	@${CC} ${CFLAGS} -I ${LIB} -c $< -o $@

clean: targetclean
	@rm -f ${TESTS_OBJS}

fclean: targetfclean clean
	@rm -f ${NAME}

re: fclean all

# Target rules

targetobjects:
	@make CFLAGS="${CFLAGS}" ${TARGETS_OBJ} -C ${TARGET_DIR}

targetclean:
	@make clean -C ${TARGET_DIR}

targetfclean:
	@make fclean -C ${TARGET_DIR}