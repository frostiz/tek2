/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#include "packet_manager.h"

static void	rpl_look_cell_up_fill_item(t_string *response,
	const char *item_name, int amount)
{
	int i = 0;

	while (i < amount) {
		response->append_c(response, item_name);
		++i;
	}
}

static void	rpl_look_cell_up(t_client *client, int x, int y,
	t_string *response)
{
	t_cell *cell = client->zappy->map_manager.get_cell(
		&client->zappy->map_manager, x, y);
	int client_amount = find_client_amount_on_cell(client, x, y);

	rpl_look_cell_up_fill_item(response, " player", client_amount);
	rpl_look_cell_up_fill_item(response, " food", cell->items.food);
	rpl_look_cell_up_fill_item(response, " linemate", cell->items.linemate);
	rpl_look_cell_up_fill_item(response, " deraumere",
		cell->items.deraumere);
	rpl_look_cell_up_fill_item(response, " sibur", cell->items.sibur);
	rpl_look_cell_up_fill_item(response, " mendiane", cell->items.mendiane);
	rpl_look_cell_up_fill_item(response, " phiras", cell->items.phiras);
	rpl_look_cell_up_fill_item(response, " thystame", cell->items.thystame);
}

static void	rpl_look_line_up(t_client *client, t_pos position,
	t_string *response, int depth)
{
	int range = position.x + depth + 1;
	int x = position.x - depth;
	int y = position.y;
	int save;

	if (range > client->zappy->map_manager.width - 1)
		range -= 10;
	if (x < 0) {
		save = x * (-1);
		x = client->zappy->map_manager.width - save;
	}
	while (x != range) {
		if (depth != 0)
			response->append_c(response, ",");
		rpl_look_cell_up(client, x, y, response);
		++x;
		if (x > client->zappy->map_manager.width - 1)
			x = 0;
	}
}

void	rpl_look_up(t_client *client)
{
	int i = 0;
	t_pos position;
	t_string response;

	position.x = client->position.x;
	position.y = client->position.y;
	position.look_to = client->position.look_to;
	string_init(&response, "[");
	while (i < client->incantation_level + 1) {
		if (position.y < 0)
			position.y = client->zappy->map_manager.height - 1;
		rpl_look_line_up(client, position, &response, i);
		--position.y;
		++i;
	}
	response.append_c(&response, " ]");
	client->send_data(client, response.c_str(&response));
	string_destroy(&response);
}