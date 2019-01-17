/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** forward command
*/

#include "packet_manager.h"

void	forward_up(t_client *client)
{
	if (client->position.y == 0)
		client->position.y = client->zappy->map_manager.height - 1;
	else
		--client->position.y;
}

void	forward_down(t_client *client)
{
	if (client->position.y == client->zappy->map_manager.height - 1)
		client->position.y = 0;
	else
		++client->position.y;
}

void	forward_left(t_client *client)
{
	if (client->position.x == 0)
		client->position.x = client->zappy->map_manager.width - 1;
	else
		--client->position.x;
}

void	forward_right(t_client *client)
{
	if (client->position.x == client->zappy->map_manager.width - 1)
		client->position.x = 0;
	else
		++client->position.x;
}

void	forward_command(t_client *client, t_zappy_packet packet)
{
	(void)packet;
	switch (client->position.look_to) {
	case NORTH:
		forward_up(client);
		break;
	case SOUTH:
		forward_down(client);
		break;
	case WEST:
		forward_left(client);
		break;
	case EAST:
		forward_right(client);
		break;
	}
	client->send_data(client, "ok");
	rpl_ppo(client, client->uid, 1);
}