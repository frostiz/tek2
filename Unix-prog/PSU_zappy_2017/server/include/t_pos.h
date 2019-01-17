/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#ifndef PSU_ZAPPY_2017_T_POS_H
# define PSU_ZAPPY_2017_T_POS_H

typedef enum	direction {
	SOUTH = 1,
	EAST,
	NORTH,
	WEST
}		direction;

typedef struct		s_pos {
	direction	look_to;
	int 		x;
	int 		y;
}			t_pos;

#endif //PSU_ZAPPY_2017_T_POS_H
