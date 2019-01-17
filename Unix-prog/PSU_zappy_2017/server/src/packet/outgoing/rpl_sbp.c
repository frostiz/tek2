/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#include "packet_manager.h"

void	rpl_sbp(t_client *client)
{
	char response[1024];

	sprintf(response, "sbp");
	client->send_data(client, response);
}