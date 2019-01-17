##
## EPITECH PROJECT, 2018
## myString
## File description:
## myString
##

CFLAGS	= -Wall -Wextra -Iinclude

SRC	=	src/mystring.c			\
		src/mystring_append.c		\
		src/mystring_compare.c		\
		src/mystring_insert.c		\
		src/mystring_join.c		\
		src/mystring_split.c		\
		src/mystring_utils_two.c	\
		src/mystring_utils.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmystring.a

all:		$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(OBJ)
	rm -f $(NAME)

re: fclean all