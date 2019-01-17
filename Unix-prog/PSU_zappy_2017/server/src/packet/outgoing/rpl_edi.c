/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#include "packet_manager.h"

void	rpl_edi(t_client *client, int egg_uid)
{
	char response[1024];

	sprintf(response, "edi %d", egg_uid);
	client->zappy->send_graphic(client, response, 1);
}