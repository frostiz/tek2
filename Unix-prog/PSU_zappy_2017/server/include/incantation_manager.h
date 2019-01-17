/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#ifndef PSU_ZAPPY_2017_INCANTATION_MANAGER_H
# define PSU_ZAPPY_2017_INCANTATION_MANAGER_H

#include "t_cell.h"

struct s_zappy;

struct s_client;

typedef struct		s_incantation_manager {
	struct s_zappy	*zappy;
	int 		(*check_cell)(struct s_incantation_manager *this,
				t_cell *cell, int level);
	void		(*upgrade_level)(struct s_incantation_manager *this,
				t_cell *cell, int level);
}			t_incantation_manager;

void	incantation_manager_init(t_incantation_manager *this,
		struct s_zappy *zappy);
int	incantation_manager_check_cell(t_incantation_manager *this,
		t_cell *cell, int level);
void 	incantation_manager_update_level(t_incantation_manager *this,
		t_cell *cell, int level);

#endif //PSU_ZAPPY_2017_INCANTATION_MANAGER_H
