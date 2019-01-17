/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** bct command
*/

#include "packet_manager.h"
t_pos	bct_check_args(t_zappy_packet packet, t_pos pos)
{
	char *value;

	strtok(strdup(packet.raw), " ");
	value = strtok(NULL, " ");
	if (value == NULL)
		return (pos);
	pos.x = atoi(value);
	value = strtok(NULL, " ");
	if (value == NULL)
		return (pos);
	pos.y = atoi(value);
	return (pos);
}

void	bct_command(t_client *client, t_zappy_packet packet)
{
	t_pos pos;

	pos.x = -1;
	pos.y = -1;
	pos = bct_check_args(packet, pos);
	if ((pos.x < 0 || pos.x > client->zappy->map_manager.width - 1) ||
		(pos.y < 0 || pos.y > client->zappy->map_manager.height - 1)) {
		rpl_sbp(client);
		return;
	}
	rpl_bct(client, pos.x, pos.y, 0);
}