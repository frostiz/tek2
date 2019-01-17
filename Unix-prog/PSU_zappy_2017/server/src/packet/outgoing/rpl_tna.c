/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#include "packet_manager.h"

void 	rpl_tna(t_client *client, char *team_name, int broadcast)
{
	char response[1024];

	sprintf(response, "tna %s", team_name);
	client->zappy->send_graphic(client, response, broadcast);
}