/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#ifndef PSU_ZAPPY_2017_T_MINERALS_H
# define PSU_ZAPPY_2017_T_MINERALS_H

typedef enum	mineral {
	LINEMATE,
	DERAUMERE,
	SIBUR,
	MENDIANE,
	PHIRAS,
	THYSTAME
}		mineral;

typedef struct	s_minerals {
	mineral type;
	int	x;
	int 	y;
}		t_minerals;

#endif //PSU_ZAPPY_2017_T_MINERALS_H
