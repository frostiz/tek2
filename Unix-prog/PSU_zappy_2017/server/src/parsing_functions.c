/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#include "parsing.h"

void 	parse_fill_names_array(t_server_info *startup_info, char **av,
		int index, int index_max)
{
	int i = 0;

	while (index != index_max) {
		startup_info->names[i] = strdup(av[index]);
		++i;
		++index;
	}
	startup_info->names[i] = NULL;
}

int 	parse_get_names_amount(char **av, int ac, int *index)
{
	int name_amount = 0;

	while ((*index) < ac && av[(*index)][0] != '-') {
		++name_amount;
		++(*index);
	}
	return (name_amount);
}

void	parse_names(t_server_info *startup_info, char **av, int ac)
{
	int index = 1;
	int save_index;

	while (index < ac) {
		if (strcmp(av[index], "-n") == 0 && (index + 1) < ac) {
			++index;
			save_index = index;
			startup_info->names = malloc(sizeof(char *) *
				(parse_get_names_amount(av, ac, &index) + 1));
			parse_fill_names_array(startup_info, av, save_index,
				index);
		}
		++index;
	}
}

void	parse_client_amount(t_server_info *startup_info, char **av, int ac)
{
	int index = 1;

	while (index < ac) {
		if (strcmp(av[index], "-c") == 0 && (index + 1) < ac)
			startup_info->client_amount = atoi(av[index + 1]);
		++index;
	}
	if (startup_info->client_amount <= 0) {
		printf("Error: client amount must be greater than 0\n");
		exit(84);
	}
}

void	parse_frequency(t_server_info *startup_info, char **av, int ac)
{
	int index = 1;

	while (index < ac) {
		if (strcmp(av[index], "-f") == 0 && (index + 1) < ac)
			startup_info->frequency = atof(av[index + 1]);
		++index;
	}
	if (startup_info->frequency < 1 || startup_info->frequency > 1000) {
		printf("Error: frequency must be between 1 and 1000\n");
		exit(84);
	}
}