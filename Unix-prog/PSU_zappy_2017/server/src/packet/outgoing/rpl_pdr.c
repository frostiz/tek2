/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#include "packet_manager.h"

void	rpl_pdr(t_client *client, int uid, int resource)
{
	char response[1024];

	sprintf(response, "pdr %d %d", uid, resource);
	client->zappy->send_graphic(client, response, 1);
}