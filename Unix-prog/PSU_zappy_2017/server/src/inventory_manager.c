/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#include "inventory_manager.h"

void	inventory_manager_init(t_inventory_manager *this)
{
	this->items.food = 10;
	this->items.linemate = 0;
	this->items.deraumere = 0;
	this->items.sibur = 0;
	this->items.mendiane = 0;
	this->items.phiras = 0;
	this->items.thystame = 0;
	this->take_item = &inventory_manager_take_item;
	this->set_item = &inventory_manager_set_item;
	this->check_item = &inventory_manager_check_item;
}

void	inventory_manager_take_item_next(t_inventory_manager *this,
						int object_id)
{
	switch (object_id) {
	case 4:
		--this->items.mendiane;
		break;
	case 5:
		--this->items.phiras;
		break;
	case 6:
		--this->items.thystame;
		break;
	}
}

void	inventory_manager_take_item(t_inventory_manager *this,
						int object_id)
{
	switch (object_id) {
	case 0:
		--this->items.food;
		break;
	case 1:
		--this->items.linemate;
		break;
	case 2:
		--this->items.deraumere;
		break;
	case 3:
		--this->items.sibur;
		break;
	case 4:
	case 5:
	case 6:
		inventory_manager_take_item_next(this, object_id);
		break;
	}
}

void	inventory_manager_set_item_next(t_inventory_manager *this,
						int object_id)
{
	switch (object_id) {
	case 4:
		++this->items.mendiane;
		break;
	case 5:
		++this->items.phiras;
		break;
	case 6:
		++this->items.thystame;
		break;
	}
}

void	inventory_manager_set_item(t_inventory_manager *this, int object_id)
{
	switch (object_id) {
	case 0:
		++this->items.food;
		break;
	case 1:
		++this->items.linemate;
		break;
	case 2:
		++this->items.deraumere;
		break;
	case 3:
		++this->items.sibur;
		break;
	case 4:
	case 5:
	case 6:
		inventory_manager_set_item_next(this, object_id);
		break;
	}
}
