/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#include "packet_manager.h"

void	rpl_pdi(t_client *client, int uid)
{
	char response[1024];

	sprintf(response, "pdi %d", uid);
	client->zappy->send_graphic(client, response, 1);
}