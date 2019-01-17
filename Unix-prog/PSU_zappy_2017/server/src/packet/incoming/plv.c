/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** plv command
*/

#include "packet_manager.h"

int	plv_check_id(t_client *client, int uid)
{
	t_client *target;
	int total = vector_total(&client->zappy->clients);
	int i = 0;

	while (i < total) {
		target = vector_get(&client->zappy->clients, i);
		if (target->uid	== uid)
			return (1);
		++i;
	}
	return (0);
}

void	plv_command(t_client *client, t_zappy_packet packet)
{
	char *value;
	int uid;

	strtok(strdup(packet.raw), " ");
	value = strtok(NULL, " ");
	if (value == NULL) {
		rpl_sbp(client);
		return;
	}
	uid = atoi(value);
	if (plv_check_id(client, uid) == 0) {
		rpl_sbp(client);
		return;
	}
	rpl_plv(client, uid, 0);
}