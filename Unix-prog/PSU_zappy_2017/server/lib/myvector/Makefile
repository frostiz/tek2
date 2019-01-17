##
## EPITECH PROJECT, 2018
## myvector
## File description:
## Makefile for myvector
##

CFLAGS	= -Wall -Wextra -Iinclude

SRC	=	src/vector.c		\
		src/vector_utils.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmyvector.a

all:		$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(OBJ)
	rm -f $(NAME)

re:		fclean all