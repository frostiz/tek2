/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#include "packet_manager.h"

void	rpl_suc(t_client *client)
{
	char response[1024];

	sprintf(response, "suc");
	client->send_data(client, response);
}