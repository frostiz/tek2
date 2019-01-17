/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** set command
*/

#include "packet_manager.h"

static const char *object_list[] = {
	"food", "linemate", "deraumere", "sibur", "mendiane", "phiras",
	"thystame"
};

static int 	check_object_exist(char *object)
{
	int i = 0;

	while (i < 7) {
		if (strcmp(object_list[i], object) == 0)
			return (i);
		++i;
	}
	return (-1);
}

static int 	is_valid_argument(t_client *client, t_zappy_packet packet)
{
	char *object = strtok(strdup(packet.raw), " ");
	int object_id;

	object = strtok(NULL, " ");
	if (object == NULL) {
		client->send_data(client, "ko");
		return (-1);
	}
	object_id = check_object_exist(object);
	if (object_id < 0) {
		client->send_data(client, "ko");
		return (-1);
	}
	return (object_id);
}

void		set_command(t_client *client, t_zappy_packet packet)
{
	t_map_manager *map_manager = &client->zappy->map_manager;
	t_inventory_manager *inventory = &client->inventory;
	t_pos pos = client->position;
	int object_id;

	object_id = is_valid_argument(client, packet);
	if (object_id < 0)
		return;
	if (inventory->check_item(inventory, object_id)) {
		inventory->take_item(inventory, object_id);
		map_manager->set_item(map_manager, pos.x, pos.y, object_id);
		client->send_data(client, "ok");
		rpl_pin(client, client->uid, 1);
		rpl_pdr(client, client->uid, object_id);
	} else {
		client->send_data(client, "ko");
	}
}