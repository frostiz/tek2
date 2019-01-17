##
## EPITECH PROJECT, 2018
## server
## File description:
## Makefile
##

NAME	=	zappy_server

SRC	=	src/main.c								\
		src/utils.c								\
		src/zappy.c								\
		src/zappy_utils.c						\
		src/team.c								\
		src/packets_queue.c						\
		src/packets_queue_utils.c						\
		src/timer_manager.c						\
		src/team_manager.c						\
		src/server.c							\
		src/client.c							\
		src/client_utils.c						\
		src/find_client.c						\
		src/parsing.c							\
		src/parsing_functions.c					\
		src/map_manager.c						\
		src/map_manager_utils.c					\
		src/map_manager_items.c					\
		src/inventory_manager.c					\
		src/incantation_manager.c				\
		src/packet_manager.c					\
		src/packet_manager_utils.c					\
		src/packet/packet_parser.c				\
		src/packet/outgoing/rpl_handshake.c		\
		src/packet/outgoing/rpl_welcome.c		\
		src/packet/outgoing/rpl_msz.c			\
		src/packet/outgoing/rpl_bct.c			\
		src/packet/outgoing/rpl_tna.c			\
		src/packet/outgoing/rpl_ppo.c			\
		src/packet/outgoing/rpl_pnw.c			\
		src/packet/outgoing/rpl_plv.c			\
		src/packet/outgoing/rpl_pin.c			\
		src/packet/outgoing/rpl_pex.c			\
		src/packet/outgoing/rpl_pbc.c			\
		src/packet/outgoing/rpl_pic.c			\
		src/packet/outgoing/rpl_pie.c			\
		src/packet/outgoing/rpl_pfk.c			\
		src/packet/outgoing/rpl_pdr.c			\
		src/packet/outgoing/rpl_pgt.c			\
		src/packet/outgoing/rpl_pdi.c			\
		src/packet/outgoing/rpl_enw.c			\
		src/packet/outgoing/rpl_eht.c			\
		src/packet/outgoing/rpl_ebo.c			\
		src/packet/outgoing/rpl_edi.c			\
		src/packet/outgoing/rpl_sgt.c			\
		src/packet/outgoing/rpl_sst.c			\
		src/packet/outgoing/rpl_seg.c			\
		src/packet/outgoing/rpl_smg.c			\
		src/packet/outgoing/rpl_suc.c			\
		src/packet/outgoing/rpl_sbp.c			\
		src/packet/outgoing/rpl_look_up.c		\
		src/packet/outgoing/rpl_look_down.c		\
		src/packet/outgoing/rpl_look_left.c		\
		src/packet/outgoing/rpl_look_right.c	\
		src/packet/outgoing/rpl_dead.c			\
		src/packet/incoming/handshake.c			\
		src/packet/incoming/msz.c				\
		src/packet/incoming/bct.c				\
		src/packet/incoming/mct.c				\
		src/packet/incoming/tna.c				\
		src/packet/incoming/ppo.c				\
		src/packet/incoming/plv.c				\
		src/packet/incoming/pin.c				\
		src/packet/incoming/sgt.c				\
		src/packet/incoming/sst.c				\
		src/packet/incoming/forward.c			\
		src/packet/incoming/graphic.c			\
		src/packet/incoming/right.c				\
		src/packet/incoming/left.c				\
		src/packet/incoming/inventory.c			\
		src/packet/incoming/look.c				\
		src/packet/incoming/connect_nbr.c		\
		src/packet/incoming/take.c				\
		src/packet/incoming/set.c				\
		src/packet/incoming/incantation.c		\
		src/packet/incoming/broadcast.c				\

OBJ	=	$(SRC:.c=.o)

CFLAGS  =	-Iinclude/ -I./lib/mystring/include -I./lib/myvector/include -W -Wall -Wextra

ifeq		($(DEBUG), 1)
		CFLAGS += -g
endif

RM	=	rm -f

CC	=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C ./lib/mystring/
		make -C ./lib/myvector/
		@$(CC) -o $(NAME) $(OBJ) -L./lib/mystring -lmystring -L./lib/myvector -lmyvector

clean:
		make -C ./lib/mystring/ clean
		make -C ./lib/myvector/ clean
		@$(RM) $(OBJ)
		@echo "Cleaning" $(NAME)

fclean:		clean
		make -C ./lib/mystring/ fclean
		make -C ./lib/myvector/ fclean
		@$(RM) $(NAME)
		@echo "Deleting" $(NAME)

re:		fclean all

.PHONY:		re all clean fclean
