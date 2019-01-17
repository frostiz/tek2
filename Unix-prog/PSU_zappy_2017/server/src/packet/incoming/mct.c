/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** mct command
*/

#include "packet_manager.h"

void	mct_command(t_client *client, t_zappy_packet packet)
{
	int i = 0;
	int j;

	(void)packet;
	while (i < client->zappy->map_manager.height) {
		j = 0;
		while (j < client->zappy->map_manager.width) {
			rpl_bct(client, j, i, 0);
			++j;
		}
		++i;
	}
}