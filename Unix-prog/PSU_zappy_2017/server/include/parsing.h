/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez
*/

#ifndef PSU_ZAPPY_2017_PARSING_H
# define PSU_ZAPPY_2017_PARSING_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_server_info {
	int port;
	int width;
	int height;
	char **names;
	int client_amount;
	time_t frequency;
} t_server_info;

t_server_info	parsing(char **av, int ac);
void		parse_port(t_server_info *startup_info, char **av,
							int ac);
void		parse_width(t_server_info *startup_info, char **av,
							int ac);
void		parse_height(t_server_info *startup_info, char **av,
							int ac);
void		parse_names(t_server_info *startup_info, char **av,
							int ac);
void		parse_client_amount(t_server_info *startup_info, char **av,
							int ac);
void		parse_frequency(t_server_info *startup_info, char **av,
							int ac);
void		check_used_flags(char **av, int ac);

#endif //PSU_ZAPPY_2017_PARSING_H
