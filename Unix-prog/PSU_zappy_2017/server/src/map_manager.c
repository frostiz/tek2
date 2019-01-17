/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#include "map_manager.h"

t_cell *get_cell(t_map_manager *this, int x, int y)
{
	t_cell *cell;
	int i = 0;

	while (i < this->height * this->width) {
		cell = vector_get(&this->cells, i);
		if (cell->x == x && cell->y == y)
			return (cell);
		++i;
	}
	return (NULL);
}

t_cell	*map_manager_new_item(t_map_manager *this)
{
	t_cell *cell = this->get_cell(this, rand() % this->width,
		rand() % this->height);

	map_manager_generate_items(cell, rand() % 10, rand() % 10);
	return (cell);
}

void	map_manager_init_cell(t_cell *cell, int x, int y)
{
	int i = 0;
	int j;

	cell->width = 10;
	cell->height = 10;
	cell->x = x;
	cell->y = y;
	vector_init(&cell->food_list);
	vector_init(&cell->minerals_list);
	map_manager_init_items_amount(cell);
	while (i < 10) {
		j = 0;
		while (j < 10) {
			map_manager_generate_items(cell, j, i);
			++j;
		}
		++i;
	}
}

void	map_manager_set_map(t_map_manager *this)
{
	t_cell *cell;
	int i = 0;
	int j;

	while (i < this->height) {
		j = 0;
		while (j < this->width) {
			cell = malloc(sizeof(t_cell));
			map_manager_init_cell(cell, j, i);
			vector_add(&this->cells, cell);
			++j;
		}
		++i;
	}
}

void	map_manager_init(t_map_manager *this, int height, int width)
{
	if (!this)
		return;
	this->height = height;
	this->width = width;
	vector_init(&this->cells);
	map_manager_set_map(this);
	this->get_cell = &get_cell;
	this->take_item = &map_manager_take_item;
	this->set_item = &map_manager_set_item;
	this->item_available = &map_manager_item_available;
	this->new_item = &map_manager_new_item;
}