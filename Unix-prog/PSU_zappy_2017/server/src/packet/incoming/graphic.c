/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** graphic command
*/

#include "packet_manager.h"

void	graphic_print_connected_ai(t_client *client)
{
	t_client *target;

	for (int i = 0; i < vector_total(&client->zappy->clients); i++) {
		target = ((t_client *)vector_get(&client->zappy->clients, i));
		printf("send pnw for %d client\n", target->socket);
		rpl_pnw(target, client, 0);
	}
}

void	graphic_command(t_client *client, t_zappy_packet packet)
{
	int i = 0;
	int j;

	(void)packet;
	rpl_msz(client, 0);
	rpl_sgt(client, 0);
	while (i < client->zappy->map_manager.height) {
		j = 0;
		while (j < client->zappy->map_manager.width) {
			rpl_bct(client, j, i, 0);
			++j;
		}
		++i;
	}
	i = 0;
	while (client->zappy->startup_info.names[i] != NULL) {
		rpl_tna(client, client->zappy->startup_info.names[i], 0);
		++i;
	}
	graphic_print_connected_ai(client);
}