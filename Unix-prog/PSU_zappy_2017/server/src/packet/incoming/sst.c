/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** sst command
*/

#include "packet_manager.h"

void	sst_command(t_client *client, t_zappy_packet packet)
{
	char *value;
	long int frequency;

	strtok(strdup(packet.raw), " ");
	value = strtok(NULL, " ");
	if (value == NULL) {
		rpl_sbp(client);
		return;
	}
	frequency = atoi(value);
	rpl_sst(client, frequency, 0);
}