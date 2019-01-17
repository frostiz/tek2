/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Team
*/

#ifndef TEAM_H_
# define TEAM_H_

#include "mystring.h"
#include "myvector.h"

struct s_client;

typedef struct			s_team
{
	t_string		team_name;
	t_vector		clients;
	int			max_clients;
	int			(*add)(struct s_team *this,
					struct s_client *client);
	void			(*remove)(struct s_team *this,
					struct s_client *client);
	int			(*slot_remaining)(struct s_team *this);
}				t_team;

void			team_init(t_team *this, char *team_name,
						int limit);
void			team_destroy(t_team *this);
int			team_add_client(t_team *this,
				struct s_client *client);
void			team_remove_client(t_team *this,
				struct s_client *client);
int			team_slot_remaining(t_team *this);

#endif /* TEAM_H_ */