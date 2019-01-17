/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#include "packet_manager.h"

void	rpl_seg(t_client *client, char *team)
{
	char response[1024];

	sprintf(response, "seg %s", team);
	client->zappy->send_graphic(client, response, 1);
}