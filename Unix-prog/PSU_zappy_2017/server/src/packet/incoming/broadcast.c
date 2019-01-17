/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** broadcast command
*/

#include "packet_manager.h"

void	broadcast_command(t_client *client, t_zappy_packet packet)
{
	(void) packet;

	client->send_data(client, "ko");
}