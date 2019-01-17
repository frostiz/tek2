/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#include "packet_manager.h"

void	rpl_pbc(t_client *client, int uid, char *broadcast)
{
	char response[1024];

	sprintf(response, "pbc %d %s", uid, broadcast);
	client->zappy->send_graphic(client, response, 1);

}
