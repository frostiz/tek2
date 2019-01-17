/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Team manager
*/

#include "team.h"
#include "team_manager.h"

void	team_manager_init(t_team_manager *this, char **teams, int limit)
{
	if (!this)
		return;
	vector_init(&this->teams);
	this->add = &team_manager_add;
	this->find_by_name = &team_manager_find_by_name;

	for (size_t i = 0; teams[i] != NULL; i++)
		this->add(this, teams[i], limit);
}

void	team_manager_add(t_team_manager *this, char *team_name, int limit)
{
	t_team *team;

	team = malloc(sizeof(t_team));
	team_init(team, team_name, limit);
	vector_add(&this->teams, team);
}

t_team	*team_manager_find_by_name(t_team_manager *this, const char *name)
{
	t_team *team;

	for (int i = 0; i < vector_total(&this->teams); i++) {
		team = ((t_team *)vector_get(&this->teams, i));
		if (team->team_name.compare_c(&team->team_name, name) == 0) {
			return (team);
		}
	}
	return (NULL);
}