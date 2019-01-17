/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#include "packet_manager.h"

void	rpl_eht(t_client *client, int egg_uid)
{
	char response[1024];

	sprintf(response, "eht %d", egg_uid);
	client->zappy->send_graphic(client, response, 1);
}