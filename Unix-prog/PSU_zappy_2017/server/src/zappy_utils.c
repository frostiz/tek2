/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#include "zappy.h"
#include "client.h"

void	send_graphic(t_client *client, char *str, int broadcast)
{
	t_client *target;
	int total = vector_total(&client->zappy->clients);
	int i = 0;

	if (broadcast)
		while (i < total) {
			target = vector_get(&client->zappy->clients, i);
			if (target->is_ai == 0)
				target->send_data(target, str);
			++i;
		}
	else
		client->send_data(client, str);
}