/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#include "zappy.h"
#include "client.h"

t_client	*find_client_by_id(t_zappy *this, int uid)
{
	t_client *client;
	int i = 0;
	int total = vector_total(&this->clients);

	while (i < total) {
		client = vector_get(&this->clients, i);
		if (client->uid == uid)
			return (client);
		++i;
	}
	return (NULL);
}