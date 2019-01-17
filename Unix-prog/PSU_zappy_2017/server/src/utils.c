/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** utils
*/

#include "inventory_manager.h"
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

const char *args_list[] = { "-p", "-x", "-y", "-n", "-c", "-f" };

int		inventory_manager_check_item(t_inventory_manager *this,
			int object_id)
{
	switch (object_id) {
	case 0:
		return ((this->items.food > 0) ? 1 : 0);
	case 1:
		return ((this->items.linemate > 0) ? 1 : 0);
	case 2:
		return ((this->items.deraumere > 0) ? 1 : 0);
	case 3:
		return ((this->items.sibur > 0) ? 1 : 0);
	case 4:
		return ((this->items.mendiane > 0) ? 1 : 0);
	case 5:
		return ((this->items.phiras > 0) ? 1 : 0);
	case 6:
		return ((this->items.thystame > 0) ? 1 : 0);
	}
	return (0);
}

void		check_used_flags(char **av, int ac)
{
	int check = 0;
	int i = 0;
	int j;

	while (i < ac) {
		j = 0;
		while (j < 6) {
			if (av[i][0] == '-')
				if (strcmp(args_list[j], av[i]) == 0)
					check += 1;
			++j;
		}
		++i;
	}
	if (check == 0)
		exit(84);
}

long long current_timestamp(void)
{
	struct timeval	te;

	gettimeofday(&te, NULL);
	long long milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000;

	return (milliseconds);
}