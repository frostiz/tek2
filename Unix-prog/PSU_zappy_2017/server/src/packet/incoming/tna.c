/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** tna command
*/

#include "packet_manager.h"

void	tna_command(t_client *client, t_zappy_packet packet)
{
	t_server_info server_info = client->zappy->startup_info;
	int i = 0;

	(void)packet;
	while (server_info.names[i] != NULL) {
		rpl_tna(client, server_info.names[i], 0);
		++i;
	}
}