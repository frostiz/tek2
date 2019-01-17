##
## EPITECH PROJECT, 2018
## cpp_rush3
## File description:
## Makefile
##

CC			=	g++

CXXFLAGS	=	-I../../include -Wall -Wextra -W -fPIC

### SFML ###

SFMLSRC		=	sfmllib.cpp	\
			../Map.cpp

SFML		=	-lsfml-graphics -lsfml-window -lsfml-system

SFMLNAME	=	lib_arcade_sfml.so

SFMLOBJECTS	=	$(SFMLSRC:.cpp=.o)

### NCURSES ###


NCURSESSRC	=	NcursesLib.cpp	\
			../Map.cpp

NCURSES		=	-lncurses

NCURSESNAME =		lib_arcade_ncurses.so

NCURSESOBJECTS	=	$(NCURSESSRC:.cpp=.o)

### SDL ###

SDLSRC	=		sdllib.cpp	\
			../Map.cpp

SDL		=	-lSDL2 -lSDL2_image -lSDL2_ttf

SDLNAME =		lib_arcade_sdl.so

SDLOBJECTS	=	$(SDLSRC:.cpp=.o)

all:	$(SFMLNAME) $(NCURSESNAME) $(SDLNAME)

$(SFMLNAME): $(SFMLOBJECTS)
	g++ -shared $(SFMLOBJECTS) -fPIC -o $(SFMLNAME) $(SFML)
	@mv $(SFMLNAME) ../../lib/

$(NCURSESNAME): $(NCURSESOBJECTS)
	g++ -shared $(NCURSESOBJECTS) -fPIC -o $(NCURSESNAME) $(NCURSES)
	@mv $(NCURSESNAME) ../../lib/

$(SDLNAME): $(SDLOBJECTS)
	g++ -shared $(SDLOBJECTS) -fPIC -o $(SDLNAME) $(SDL)
	@mv $(SDLNAME) ../../lib/

clean:
	@$(RM) $(SFMLOBJECTS)
	@$(RM) $(NCURSESOBJECTS)
	@$(RM) $(SDLOBJECTS)
	@echo "Cleaning" $(SFMLNAME)
	@echo "Cleaning" $(NCURSESNAME)
	@echo "Cleaning" $(SDLNAME)

fclean: clean
	@$(RM) ../../lib/$(SFMLNAME)
	@$(RM) ../../lib/$(NCURSESNAME)
	@$(RM) ../../lib/$(SDLNAME)
	@echo "Deleting" $(SFMLNAME)
	@echo "Deleting" $(NCURSESNAME)
	@echo "Deleting" $(SDLNAME)

re:     fclean all
