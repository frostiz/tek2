/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#include "packet_manager.h"

void	rpl_pnw(t_client *client, t_client *target, int broadcast)
{
	char response[1024];

	if (client->is_ai == 1 && client->authenticated == 1) {
		sprintf(response, "pnw %d %d %d %d %d %s", client->uid,
			client->position.x, client->position.y,
			client->position.look_to, client->incantation_level,
			client->team->team_name.str);
		client->zappy->send_graphic(target, response, broadcast);
	}
}