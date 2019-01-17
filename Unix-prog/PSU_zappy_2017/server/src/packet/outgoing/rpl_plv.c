/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#include "packet_manager.h"

void	rpl_plv(t_client *client, int uid, int broadcast)
{
	t_client *target = client->zappy->find_client_by_id(client->zappy, uid);
	char response[1024];

	sprintf(response, "plv %d %d", uid, target->incantation_level);
	client->zappy->send_graphic(client, response, broadcast);
}