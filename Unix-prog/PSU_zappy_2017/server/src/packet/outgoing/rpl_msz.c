/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#include "packet_manager.h"

void	rpl_msz(t_client *client, int broadcast)
{
	char response[1024];

	sprintf(response, "msz %d %d", client->zappy->startup_info.width,
		client->zappy->startup_info.height);
	client->zappy->send_graphic(client, response, broadcast);
}