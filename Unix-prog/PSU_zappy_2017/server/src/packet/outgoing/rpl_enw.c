/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#include "packet_manager.h"

void	rpl_enw(t_client *client, int egg_uid, int uid)
{
	t_client *target = client->zappy->find_client_by_id(client->zappy, uid);
	char response[1024];

	sprintf(response, "enw %d %d %d %d", egg_uid, uid,
		target->position.x, target->position.y);
	client->zappy->send_graphic(client, response, 1);
}