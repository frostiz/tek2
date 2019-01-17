/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** inventory command
*/

#include "packet_manager.h"

void	inventory_command(t_client *client, t_zappy_packet packet)
{
	t_item_quantity items = client->inventory.items;
	char response[1024];

	(void)packet;
	sprintf(response, "[ food %d, linemate %d, deraumere %d, sibur %d,"
		" mendiane %d, phiras %d, thystame %d ]", items.food,
		items.linemate, items.deraumere, items.sibur, items.mendiane,
		items.phiras, items.thystame);
	client->send_data(client, response);
}