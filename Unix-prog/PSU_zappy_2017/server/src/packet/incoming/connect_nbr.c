/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** connect_nbr command
*/

#include "packet_manager.h"

void	connect_nbr_command(t_client *client, t_zappy_packet packet)
{
	char response[1024];

	(void)packet;
	sprintf(response, "%d", client->team->slot_remaining(client->team));
	client->send_data(client, response);
}