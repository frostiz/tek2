/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#ifndef PSU_ZAPPY_2017_MAP_MANAGER_H
# define PSU_ZAPPY_2017_MAP_MANAGER_H

#include "t_cell.h"
#include "t_food.h"
#include "myvector.h"
#include "t_minerals.h"

typedef struct		s_map_manager
{
	int		height;
	int		width;
	t_vector	cells;
	t_cell		*(*get_cell)(struct s_map_manager *this,
					int x, int y);
	void 		(*take_item)(struct s_map_manager *this,
					int x, int y,
				int object_id);
	void 		(*set_item)(struct s_map_manager *this,
					int x, int y,
				int object_id);
	int		(*item_available)(struct s_map_manager *this,
				int x, int y, int object_id);
	t_cell		*(*new_item)(struct s_map_manager *this);
}			t_map_manager;

void			map_manager_init(t_map_manager *this, int height,
				int width);
void			map_manager_generate_mineral(t_cell *cell,
				t_minerals *minerals);
void			map_manager_generate_items(t_cell *cell,
						int x, int y);
void			map_manager_init_items_amount(t_cell *cell);
void			map_manager_take_item(t_map_manager *this,
					int x, int y, int object_id);
void			map_manager_set_item(t_map_manager *this,
					int x, int y, int object_id);
int			map_manager_item_available(t_map_manager *this,
					int x, int y, int object_id);
t_cell			*map_manager_new_item(t_map_manager *this);

#endif //PSU_ZAPPY_2017_MAP_MANAGER_H
