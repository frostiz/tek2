/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#include "packet_manager.h"

void	rpl_pin(t_client *client, int uid, int broadcast)
{
	t_client *target = client->zappy->find_client_by_id(client->zappy, uid);
	char response[1024];

	sprintf(response, "pin %d %d %d %d %d %d %d %d %d %d", uid,
		target->position.x, target->position.y,
		target->inventory.items.food, target->inventory.items.linemate,
		target->inventory.items.deraumere,
		target->inventory.items.sibur,
		target->inventory.items.mendiane,
		target->inventory.items.phiras,
		target->inventory.items.thystame);
	client->zappy->send_graphic(client, response, broadcast);
}