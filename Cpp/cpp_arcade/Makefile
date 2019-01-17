##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.cpp				\
		src/Map.cpp				\
		src/coreProgram/ParseLibs.cpp		\
		src/coreProgram/Menu.cpp		\
		src/coreProgram/Game.cpp		\
		src/coreProgram/Core.cpp		\
		src/coreProgram/LaunchLibraries.cpp	\
		src/ArcadeException.cpp

CXXFLAGS	=	-Iinclude/ -Wall -Wextra -W -fPIC

CC	=	g++

NAME	=	arcade

OBJECTS	=	$(SRC:.cpp=.o)

GAME	=	src/games/

GRAPH	=	src/libs/

all:	core games graphicals

core:	$(NAME)

games:
	$(MAKE) -C $(GAME)

graphicals:
	$(MAKE) -C $(GRAPH)

$(NAME): $(OBJECTS)
	 @$(CC) -o $(NAME) $(OBJECTS) $(CXXFLAGS) -ldl

clean:
	@$(RM) $(OBJECTS)
	@$(MAKE) -C src/libs clean
	@$(MAKE) -C $(GAME) clean
	@echo "Cleaning" $(NAME)

fclean: clean
	@$(RM) $(NAME)
	$(MAKE) -C src/libs/ fclean
	$(MAKE) -C src/games/ fclean
	@echo "Deleting" $(NAME)

re:     fclean all

.PHONY: games graphicals core all re clean fclean $(NAME)
