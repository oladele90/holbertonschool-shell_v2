CC = gcc
SRC = shell.c helpers1.c
OBJ = ${SRC:.c=.o}
NAME = hsh
CFLAGS = -Wall -Werror -Wextra -pedantic

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${OBJ} -o ${NAME}

%.o: %.c ${HEAD}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} -f ${OBJ} ${NAME}

.PHONY: all clean
