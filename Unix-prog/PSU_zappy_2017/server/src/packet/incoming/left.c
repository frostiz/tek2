/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** left command
*/

#include "packet_manager.h"

void	left_command(t_client *client, t_zappy_packet packet)
{
	(void)packet;
	switch (client->position.look_to) {
	case NORTH:
		client->position.look_to = WEST;
		break;
	case SOUTH:
		client->position.look_to = EAST;
		break;
	case WEST:
		client->position.look_to = SOUTH;
		break;
	case EAST:
		client->position.look_to = NORTH;
		break;
	}
	client->send_data(client, "ok");
	rpl_ppo(client, client->uid, 1);
}