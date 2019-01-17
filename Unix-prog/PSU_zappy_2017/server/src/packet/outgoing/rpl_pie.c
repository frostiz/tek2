/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#include "packet_manager.h"

void	rpl_pie(t_client *client, int uid)
{
	t_client *target = client->zappy->find_client_by_id(client->zappy, uid);
	char response[1024];

	if (target == NULL)
		return;
	sprintf(response, "pie %d %d %d", target->position.x,
		target->position.y, target->incantation_level);
	client->zappy->send_graphic(client, response, 1);
}