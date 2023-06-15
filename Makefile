CC = gcc
SRC = shell.c helpers1.c string_funcs.c
OBJ = ${SRC:.c=.o}
NAME = hsh
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c11

all: ${NAME}

${NAME}: ${OBJ}
	${CC} $(CFLAGS) ${OBJ} -o ${NAME}

%.o: %.c ${HEAD}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} -f ${OBJ} ${NAME}

.PHONY: all clean
