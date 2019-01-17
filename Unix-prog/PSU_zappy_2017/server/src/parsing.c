/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#include "parsing.h"

void		parse_height(t_server_info *startup_info, char **av, int ac)
{
	int index = 1;

	while (index < ac) {
		if (strcmp(av[index], "-y") == 0 && (index + 1) < ac)
			startup_info->height = atoi(av[index + 1]);
		++index;
	}
	if (startup_info->height < 25) {
		printf("Error: width must be equal or greater than 25");
		exit(84);
	}
}

void		parse_width(t_server_info *startup_info, char **av, int ac)
{
	int index = 1;

	while (index < ac) {
		if (strcmp(av[index], "-x") == 0 && (index + 1) < ac)
			startup_info->width = atoi(av[index + 1]);
		++index;
	}
	if (startup_info->width < 25) {
		printf("Error: width must be equal or greater than 25");
		exit(84);
	}
}

void		parse_port(t_server_info *startup_info, char **av, int ac)
{
	int index = 1;

	while (index < ac) {
		if (strcmp(av[index], "-p") == 0 && (index + 1) < ac)
			startup_info->port = atoi(av[index + 1]);
		++index;
	}
	if (startup_info->port <= 0) {
		printf("Error: port must be greater than 0");
		exit(84);
	}
}

void		init_server_info(t_server_info *startup_info)
{
	char *str = malloc(sizeof(char) * 6);
	int i = 0;

	startup_info->port = 4242;
	startup_info->width = 25;
	startup_info->height = 25;
	startup_info->names = malloc(sizeof(char *) * 5);
	while (i < 4) {
		sprintf(str, "Team%d", i + 1);
		startup_info->names[i] = strdup(str);
		++i;
	}
	startup_info->names[i] = NULL;
	startup_info->client_amount = 3;
	startup_info->frequency = 100;
}

t_server_info	parsing(char **av, int ac)
{
	int i = 0;
	t_server_info startup_info;
	void (*func_ptr[6])(t_server_info *, char **, int) = {
		&parse_port,
		&parse_width,
		&parse_height,
		&parse_names,
		&parse_client_amount,
		&parse_frequency
	};

	if (ac > 1)
		check_used_flags(av, ac);
	init_server_info(&startup_info);
	while (i < 6) {
		(func_ptr[i])(&startup_info, av, ac);
		++i;
	}
	return (startup_info);
}