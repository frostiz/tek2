/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#ifndef PSU_ZAPPY_2017_INVENTORY_MANAGER_H
# define PSU_ZAPPY_2017_INVENTORY_MANAGER_H

#include "t_item_quantity.h"

typedef struct		s_inventory_manager {
	t_item_quantity	items;
	void		(*take_item)(struct s_inventory_manager *this,
				int object_id);
	void		(*set_item)(struct s_inventory_manager *this,
				int object_id);
	int		(*check_item)(struct s_inventory_manager *this,
				int object_id);
}			t_inventory_manager;

void			inventory_manager_init(t_inventory_manager *this);
void			inventory_manager_take_item(
			t_inventory_manager *this, int object_id);
void			inventory_manager_set_item(
			t_inventory_manager *this, int object_id);
int			inventory_manager_check_item(
			t_inventory_manager *this, int object_id);

#endif //PSU_ZAPPY_2017_INVENTORY_MANAGER_H
