/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#include "packet_manager.h"

void	rpl_pic(t_client *client, t_vector uid_list)
{
	t_client *target;
	int i = 1;
	char response[1024];
	char *save;
	int *uid;

	uid = vector_get(&uid_list, 0);
	target = client->zappy->find_client_by_id(client->zappy, (*uid));
	if (target == NULL)
		return;
	sprintf(response, "pic %d %d %d %d", target->position.x,
		target->position.y, target->incantation_level, (*uid));
	save = strdup(response);
	while (i < vector_total(&uid_list)) {
		uid = vector_get(&uid_list, i);
		sprintf(response, "%s %d", save, (*uid));
		save = strdup(response);
		++i;
	}
	client->zappy->send_graphic(client, response, 1);
}