/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#include "map_manager.h"

void 	map_manager_generate_first(t_cell *cell, t_minerals *minerals)
{
	switch ((rand() % 3) + 1) {
	case 1:
		minerals->type = LINEMATE;
		++cell->items.linemate;
		break;
	case 2:
		minerals->type = DERAUMERE;
		++cell->items.deraumere;
		break;
	case 3:
		minerals->type = SIBUR;
		++cell->items.sibur;
		break;
	}
}

void	map_manager_generate_second(t_cell *cell, t_minerals *minerals)
{
	switch ((rand() % 3) + 1) {
	case 1:
		minerals->type = MENDIANE;
		++cell->items.mendiane;
		break;
	case 2:
		minerals->type = PHIRAS;
		++cell->items.phiras;
		break;
	case 3:
		minerals->type = THYSTAME;
		++cell->items.thystame;
		break;
	}
}

void	map_manager_generate_mineral(t_cell *cell, t_minerals *minerals)
{
	switch ((rand() % 2) + 1) {
	case 1:
		map_manager_generate_first(cell, minerals);
		break;
	case 2:
		map_manager_generate_second(cell, minerals);
		break;
	}
}

void	map_manager_generate_items(t_cell *cell, int x, int y)
{
	t_food *food;
	t_minerals *minerals;

	switch (rand() % 50) {
	case 0:
		minerals = malloc(sizeof(t_minerals));
		minerals->x = x;
		minerals->y = y;
		map_manager_generate_mineral(cell, minerals);
		vector_add(&cell->minerals_list, minerals);
		break;
	case 1:
		food = malloc(sizeof(t_food));
		food->x = x;
		food->y = y;
		++cell->items.food;
		vector_add(&cell->food_list, food);
		break;
	default:
		break;
	}
}

void 	map_manager_init_items_amount(t_cell *cell)
{
	cell->items.food = 0;
	cell->items.linemate = 0;
	cell->items.deraumere = 0;
	cell->items.sibur = 0;
	cell->items.mendiane = 0;
	cell->items.phiras = 0;
	cell->items.thystame = 0;
}