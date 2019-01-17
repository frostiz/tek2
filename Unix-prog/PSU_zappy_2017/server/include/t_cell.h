/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#ifndef PSU_ZAPPY_2017_T_CELL_H
# define PSU_ZAPPY_2017_T_CELL_H

#include "t_item_quantity.h"
#include "myvector.h"

typedef struct		s_cell {
	int		x;
	int		y;
	int		height;
	int		width;
	t_item_quantity	items;
	t_vector	food_list;
	t_vector	minerals_list;
}			t_cell;

#endif //PSU_ZAPPY_2017_T_CELL_H
