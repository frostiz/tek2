##
## EPITECH PROJECT, 2018
## client
## File description:
## Makefile
##

NAME	=	zappy_client

SRC	=	src/Core.cpp			\
		src/EventManager.cpp		\
		src/MapManager.cpp		\
		src/PacketManager.cpp		\
		src/TeamManager.cpp		\
		src/GraphicManager.cpp		\
		src/AssetsManager.cpp		\
		src/Tile.cpp			\
		src/Player.cpp			\
		src/Egg.cpp			\
		src/Element.cpp			\
		src/MouseManager.cpp		\
		src/Ressource.cpp		\
		src/GUI.cpp			\
		src/CircularBuffer.cpp		\
		src/main.cpp			\

OBJ	=	$(SRC:.cpp=.o)

CXXFLAGS  =	-Iinclude/ -W -Wall -Wextra -std=c++11

ifeq		($(DEBUG), 1)
		CXXFLAGS += -g
endif

RM	=	rm -f

CC	=	g++

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(CC) -o $(NAME) -lsfml-window -lsfml-graphics -lsfml-system $(OBJ)

clean:
		@$(RM) $(OBJ)
		@echo "Cleaning" $(NAME)

fclean:		clean
		@$(RM) $(NAME)
		@echo "Deleting" $(NAME)

re:		fclean all

.PHONY:		re all clean fclean
