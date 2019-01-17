##
## EPITECH PROJECT, 2018
## ai
## File description:
## Makefile
##

NAME	=	zappy_ai

SRC	=	src/main.cpp			\
		src/Ai.cpp			\
		src/Parser.cpp			\
		src/Packet.cpp			\
		src/ServerMessage.cpp		\
		src/ParseUtils.cpp		\
		src/IncomingPackets.cpp		\
		src/OutgoingPackets.cpp		\
		src/Algorithm.cpp		\
		src/CommandHandler.cpp		\
		src/CommandReturn.cpp		\
		src/Moves.cpp			\
		src/SoundMove.cpp		\

OBJ	=	$(SRC:.cpp=.o)

CXXFLAGS  =	-Iinclude/ -W -Wall -Wextra

ifeq		($(DEBUG), 1)
		CXXFLAGS += -g
endif

RM	=	rm -f

CC	=	g++

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(CC) -o $(NAME) $(OBJ)

clean:
		@$(RM) $(OBJ)
		@echo "Cleaning" $(NAME)

fclean:		clean
		@$(RM) $(NAME)
		@echo "Deleting" $(NAME)

re:		fclean all

.PHONY:		re all clean fclean
