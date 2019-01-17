/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#include "map_manager.h"

void	map_manager_take_item_next(t_cell *cell, int object_id)
{
	switch (object_id) {
	case 4:
		--cell->items.mendiane;
		break;
	case 5:
		--cell->items.phiras;
		break;
	case 6:
		--cell->items.thystame;
		break;
	}
}

void	map_manager_take_item(t_map_manager *this, int x, int y,
						int object_id)
{
	t_cell *cell = this->get_cell(this, x, y);

	switch (object_id) {
	case 0:
		--cell->items.food;
		break;
	case 1:
		--cell->items.linemate;
		break;
	case 2:
		--cell->items.deraumere;
		break;
	case 3:
		--cell->items.sibur;
		break;
	case 4:
	case 5:
	case 6:
		map_manager_take_item_next(cell, object_id);
		break;
	}
}

void	map_manager_set_item_next(t_cell *cell, int object_id)
{
	switch (object_id) {
	case 4:
		++cell->items.mendiane;
		break;
	case 5:
		++cell->items.phiras;
		break;
	case 6:
		++cell->items.thystame;
		break;
	}
}

void	map_manager_set_item(t_map_manager *this, int x, int y,
					int object_id)
{
	t_cell *cell = this->get_cell(this, x, y);

	switch (object_id) {
	case 0:
		++cell->items.food;
		break;
	case 1:
		++cell->items.linemate;
		break;
	case 2:
		++cell->items.deraumere;
		break;
	case 3:
		++cell->items.sibur;
		break;
	case 4:
	case 5:
	case 6:
		map_manager_set_item_next(cell, object_id);
		break;
	}
}

int	map_manager_item_available(t_map_manager *this, int x, int y,
		int object_id)
{
	t_cell *cell = this->get_cell(this, x, y);

	switch (object_id) {
	case 0:
		return ((cell->items.food > 0) ? 1 : 0);
	case 1:
		return ((cell->items.linemate > 0) ? 1 : 0);
	case 2:
		return ((cell->items.deraumere > 0) ? 1 : 0);
	case 3:
		return ((cell->items.sibur > 0) ? 1 : 0);
	case 4:
		return ((cell->items.mendiane > 0) ? 1 : 0);
	case 5:
		return ((cell->items.phiras > 0) ? 1 : 0);
	case 6:
		return ((cell->items.thystame > 0) ? 1 : 0);
	}
	return (0);
}