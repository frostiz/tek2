/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** incantation command
*/

#include "packet_manager.h"

void	incantation_first_call(t_client *client)
{
	t_map_manager *map_manager = &client->zappy->map_manager;
	t_incantation_manager *incantation = client->zappy->incantation_manager;
	t_pos pos = client->position;
	t_cell *cell = map_manager->get_cell(map_manager, pos.x, pos.y);
	int status;

	status = incantation->check_cell(incantation, cell,
		client->incantation_level);
	if (status == 1) {
		client->send_data(client, "Elevation underway");
	} else {
		client->send_data(client, "ko");
	}
}

void	start_incantation_reply(t_client *client, t_cell *cell)
{
	t_client *target;
	int total = vector_total(&client->zappy->clients);
	int i = 0;
	t_vector client_list;

	vector_init(&client_list);
	while (i < total) {
		target = vector_get(&client->zappy->clients, i);
		if (target->position.x == cell->x
			&& target->position.y == cell->y
			&& target->incantation_level
			== client->incantation_level)
			vector_add(&client_list, &target->uid);
		++i;
	}
	rpl_pic(client, client_list);
}

void	incantation_command(t_client *client, t_zappy_packet packet)
{
	char response[1024];
	t_map_manager *map_manager = &client->zappy->map_manager;
	t_incantation_manager *incantation = client->zappy->incantation_manager;
	t_pos pos = client->position;
	t_cell *cell = map_manager->get_cell(map_manager, pos.x, pos.y);
	int status;

	(void)packet;
	start_incantation_reply(client, cell);
	status = incantation->check_cell(incantation, cell,
		client->incantation_level);
	if (status == 1) {
		incantation->upgrade_level(incantation, cell,
			client->incantation_level);
		sprintf(response, "Current level: %d",
			client->incantation_level);
		client->send_data(client, response);
		rpl_plv(client, client->uid, 1);
	} else {
		client->send_data(client, "ko");
	}
	rpl_pie(client, client->uid);
	rpl_bct(client, cell->x, cell->y, 1);
}