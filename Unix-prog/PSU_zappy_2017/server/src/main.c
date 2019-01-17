/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** main
*/

#include <stdio.h>
#include "main.h"

static	void print_help(char *str)
{
	printf("USAGE:\t%s -p port -x width -y height -n name1 name2", str);
	printf(" ... -c clientsNb\n-f freq\n\t");
	printf("port\t\tis the port number\n\t");
	printf("width\t\tis the widht of the world\n\t");
	printf("height\t\tis the height of the world\n\t");
	printf("nameX\t\tis the name of the team X\n\t");
	printf("clientNb\tis the number if authorized clients per team\n\t");
	printf("freq\t\t");
	printf("is the reciprocal of time unit for execution of actions\n");
	exit(0);
}

static	void check_usage(int ac, char **av)
{
	int i = 0;

	(void)ac;
	while (av[i] != NULL) {
		if ((strcasecmp(av[i], "--help") == 0) ||
			(strcasecmp(av[i], "-help") == 0))
			print_help(av[0]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_zappy zappy;

	srand(time(NULL));
	check_usage(ac, av);
	zappy.startup_info = parsing(av, ac);
	map_manager_init(&zappy.map_manager, zappy.startup_info.height,
		zappy.startup_info.width);
	zappy_init(&zappy, zappy.startup_info.names);
	zappy.start_server(&zappy);
	return (0);
}
