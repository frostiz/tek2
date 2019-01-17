/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Team manager
*/

#ifndef TEAM_MANAGER_H_
# define TEAM_MANAGER_H_

#include "team.h"
#include "myvector.h"

typedef struct		s_team_manager
{
	t_vector	teams;
	void		(*add)(struct s_team_manager *this,
				char *team, int limit);
	t_team		*(*find_by_name)(struct s_team_manager *this,
				const char *name);
}			t_team_manager;

void			team_manager_init(t_team_manager *this,
					char **teams, int limit);
void			team_manager_add(t_team_manager *this,
					char *team, int limit);
t_team			*team_manager_find_by_name(t_team_manager *this,
					const char *name);

#endif //TEAM_MANAGER_H_
