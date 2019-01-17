/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** team
*/

#include "team.h"
#include "client.h"

void	team_init(t_team *this, char *team_name, int limit)
{
	if (!this)
		return;
	string_init(&this->team_name, team_name);
	vector_init(&this->clients);

	this->max_clients = limit;
	this->add = &team_add_client;
	this->slot_remaining = &team_slot_remaining;
	this->remove = &team_remove_client;

	printf("init team %s\n", team_name);
}

void	team_destroy(t_team *this)
{
	string_destroy(&this->team_name);
	vector_free(&this->clients);
}

int	team_add_client(t_team *this, t_client *client)
{
	if (vector_total(&this->clients) < this->max_clients) {
		vector_add(&this->clients, client);
		printf("Added a client to %s team\n", this->team_name.str);
		return (1);
	}
	return (0);
}

void	team_remove_client(t_team *this, struct s_client *client)
{
	t_client *current;

	for (int i = 0; i < vector_total(&this->clients); i++) {
		current = ((t_client *)vector_get(&this->clients, i));
		if (current->uid == client->uid) {
			vector_delete(&this->clients, i);
			return;
		}
	}
}

int	team_slot_remaining(t_team *this)
{
	int	result;

	result = this->max_clients - vector_total(&this->clients);
	if (result <= 0)
		result = 0;
	return (result);
}