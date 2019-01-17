/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** look command
*/

#include "packet_manager.h"

void	look_command(t_client *client, t_zappy_packet packet)
{
	(void)packet;
	switch (client->position.look_to) {
	case NORTH:
		rpl_look_up(client);
		break;
	case SOUTH:
		rpl_look_down(client);
		break;
	case WEST:
		rpl_look_left(client);
		break;
	case EAST:
		rpl_look_right(client);
		break;
	}
}