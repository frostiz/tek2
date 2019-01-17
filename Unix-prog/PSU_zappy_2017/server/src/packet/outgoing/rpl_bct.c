/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#include "packet_manager.h"

void	rpl_bct(t_client *client, int x, int y, int broadcast)
{
	char response[1024];
	t_map_manager map_manager = client->zappy->map_manager;
	t_cell *cell = map_manager.get_cell(&map_manager, x, y);

	sprintf(response, "bct %d %d %d %d %d %d %d %d %d", x, y,
		cell->items.food, cell->items.linemate,
		cell->items.deraumere, cell->items.sibur,
		cell->items.mendiane, cell->items.phiras,
		cell->items.thystame);
	client->zappy->send_graphic(client, response, broadcast);
}