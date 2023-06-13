CC = gcc
SRC = shell.c helpers1.c
OBJ = ${SRC:.c=.o}
NAME = hsh
HEAD = shell.h
CFLAGS = -Wall -Werror -Wextra -pedantic
all: ${SRC:.c=.o}
	${CC} ${OBJ} -o ${NAME}