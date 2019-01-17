/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#include "zappy.h"
#include "client.h"
#include "incantation_manager.h"

const int elevation_list[7][9] = {
	{ 1, 1, 0, 0, 0, 0, 0 },
	{ 2, 1, 1, 1, 0, 0, 0 },
	{ 2, 2, 0, 1, 0, 2, 0 },
	{ 4, 1, 1, 2, 0, 1, 0 },
	{ 4, 1, 2, 1, 3, 0, 0 },
	{ 6, 1, 2, 3, 0, 1, 0 },
	{ 6, 2, 2, 2, 2, 2, 1 }
};

void	incantation_manager_reset_cell(t_cell *cell)
{
	cell->items.linemate = 0;
	cell->items.deraumere = 0;
	cell->items.sibur = 0;
	cell->items.mendiane = 0;
	cell->items.phiras = 0;
	cell->items.thystame = 0;
}

void 	incantation_manager_upgrade_level(t_incantation_manager *this,
		t_cell *cell, int level)
{
	int i = 0;
	int total = vector_total(&this->zappy->clients);
	t_client *client;

	while (i < total) {
		client = vector_get(&this->zappy->clients, i);
		if (client->is_ai == 1 && client->position.x == cell->x
			&& client->position.y == cell->y
			&& client->incantation_level == level)
			++client->incantation_level;
		++i;
	}
	incantation_manager_reset_cell(cell);
}

int	incantation_manager_ai_amount(t_incantation_manager *this,
					t_cell *cell, int level)
{
	int i = 0;
	int total = vector_total(&this->zappy->clients);
	t_client *client;
	int ai_amount = 0;

	while (i < total) {
		client = vector_get(&this->zappy->clients, i);
		if (client->is_ai == 1 && client->position.x == cell->x
			&& client->position.y == cell->y
			&& client->incantation_level == level)
			++ai_amount;
		++i;
	}
	return (ai_amount);
}

int	incantation_manager_check_cell(t_incantation_manager *this,
		t_cell *cell, int level)
{
	int i = level - 1;
	int ai_amount = incantation_manager_ai_amount(this, cell, level);

	if (ai_amount == elevation_list[i][0]
		&& cell->items.linemate == elevation_list[i][1]
		&& cell->items.deraumere == elevation_list[i][2]
		&& cell->items.sibur == elevation_list[i][3]
		&& cell->items.mendiane == elevation_list[i][4]
		&& cell->items.phiras == elevation_list[i][5]
		&& cell->items.thystame == elevation_list[i][6])
		return (1);
	return (0);
}

void	incantation_manager_init(t_incantation_manager *this,
					t_zappy *zappy)
{
	this->zappy = zappy;
	this->check_cell = &incantation_manager_check_cell;
	this->upgrade_level = &incantation_manager_upgrade_level;
}