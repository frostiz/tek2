##
## EPITECH PROJECT, 2018
## games
## File description:
## Games 
##

CC			=	g++

CXXFLAGS	=	-I../../include -Wall -Wextra -W -fPIC

SNAKESRC	=	Snake/Snake.cpp	\
			../Map.cpp

SNAKENAME	=	lib_arcade_nibbler.so

SNAKEOBJ	=	$(SNAKESRC:.cpp=.o)

QIXSRC		=	Qix/Qix.cpp	\
			../Map.cpp

QIXNAME		=	lib_arcade_qix.so

QIXOBJ		=	$(QIXSRC:.cpp=.o)

RM		=	rm -rf

all:	$(SNAKENAME) $(QIXNAME)

$(SNAKENAME): $(SNAKEOBJ)
	g++ -shared $(SNAKEOBJ) -fPIC -o $(SNAKENAME)
	@mv $(SNAKENAME) ../../games/

$(QIXNAME): $(QIXOBJ)
	g++ -shared $(QIXOBJ) -fPIC -o $(QIXNAME)
	@mv $(QIXNAME) ../../games/

clean:
	@$(RM) $(SNAKEOBJ)
	@$(RM) $(QIXOBJ)
	@echo "Cleaning" $(SNAKENAME)
	@echo "Cleaning" $(QIXNAME)

fclean: clean
	@$(RM) ../../games/$(SNAKENAME)
	@$(RM) ../../games/$(QIXNAME)
	@echo "Deleting" $(SNAKENAME)
	@echo "Deleting" $(QIXNAME)

re:     fclean all
