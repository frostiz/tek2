/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#include "packet_manager.h"

void	rpl_smg(t_client *client, char *message)
{
	char response[1024];

	sprintf(response, "smg %s", message);
	client->zappy->send_graphic(client, response, 1);
}