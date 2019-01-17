##
## EPITECH PROJECT, 2018
## Minilibc
## File description:
## Makefile
##

NAME		=	libasm.so

SRC		=	src/strlen.asm		\
			src/strchr.asm		\
			src/memset.asm		\
			src/memcpy.asm		\
			src/memmove.asm		\
			src/strcmp.asm		\
			src/strncmp.asm		\
			src/strcasecmp.asm	\
			src/rindex.asm		\
			src/strstr.asm		\
			src/strpbrk.asm		\
			src/strcspn.asm		\
			src/read.asm		\
			src/write.asm		\

ASM		=	nasm

LD		=	gcc

ASMFLAGS	=	-f elf64

LDFLAGS		=	-shared -static -nostdlib

OBJECTS		=	$(SRC:.asm=.o)

TESTER		=	tester

all:	$(NAME) $(TESTER)

%.o: %.asm
	$(ASM) -o $@ $< $(ASMFLAGS)

$(TESTER): $(NAME)
	gcc -L. -lasm -o tester main.c

$(NAME): $(OBJECTS)
	$(LD) $(LDFLAGS) $(OBJECTS) -o $(NAME)

clean:
	@$(RM) $(OBJECTS)
	@echo "Cleaning" $(NAME)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(TESTER)
	@echo "Deleting" $(NAME)
	@echo "Deleting" $(TESTER)

re:     fclean all

.PHONY:	all re clean fclean
