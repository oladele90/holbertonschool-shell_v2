CC = gcc
SRC = shell.c helpers1.c
OBJ = ${SRC:.c=.o}
NAME = hsh
HEAD = shell.h
CFLAGS = -Wall -Werror -Wextra -pedantic
all: ${SRC:.c=.o}
	${CC} ${OBJ} -o ${NAME}
.PHONY: clean
clean:
	${RM} -f *~ ${NAME}
.PHONY: oclean
oclean:3
	${RM} -f ${OBJ}
fclean: clean oclean
.PHONY: re
re: oclean all 
${OBJ}: ${HEAD}