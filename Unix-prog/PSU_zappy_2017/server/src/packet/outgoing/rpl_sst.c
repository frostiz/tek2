/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#include "packet_manager.h"

void	rpl_sst(t_client *client, long int frequency, int broadcast)
{
	char response[1024];

	client->zappy->startup_info.frequency = frequency;
	sprintf(response, "sst %ld", client->zappy->startup_info.frequency);
	client->zappy->send_graphic(client, response, broadcast);
}