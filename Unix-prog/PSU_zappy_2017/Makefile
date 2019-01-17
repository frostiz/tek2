##
## EPITECH PROJECT, 2018
## zappy
## File description:
## Makefile
##

DIR1	=	server

DIR2	=	ai

DIR3	=	client

DEST	=	.

RM	=	rm -f

all:
	@$(MAKE) -C $(DIR1); mv $(DIR1)/zappy_server $(DEST)
	@$(MAKE) -C $(DIR2); mv $(DIR2)/zappy_ai $(DEST)
	@$(MAKE) -C $(DIR3); mv $(DIR3)/zappy_client $(DEST)

zappy_server:
	@$(MAKE) -C $(DIR1); mv $(DIR1)/zappy_server $(DEST)

zappy_ai:
	@$(MAKE) -C $(DIR2); mv $(DIR2)/zappy_ai $(DEST)

zappy_client:
	@$(MAKE) -C $(DIR3); mv $(DIR3)/zappy_client $(DEST)

clean:
	@(cd $(DIR1) && $(MAKE) $@)
	@(cd $(DIR2) && $(MAKE) $@)
	@(cd $(DIR3) && $(MAKE) $@)

fclean:
	@($(RM) zappy_server)
	@($(RM) zappy_ai)
	@($(RM) zappy_client)
	@(cd $(DIR1) && $(MAKE) $@)
	@(cd $(DIR2) && $(MAKE) $@)
	@(cd $(DIR3) && $(MAKE) $@)

re:	fclean all

.PHONY: fclean re all zappy_server zappy_ai zappy_client
