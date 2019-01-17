/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#include "packet_manager.h"

void	rpl_sgt(t_client *client, int broadcast)
{
	char response[1024];

	sprintf(response, "sgt %ld", client->zappy->startup_info.frequency);
	client->zappy->send_graphic(client, response, broadcast);
}