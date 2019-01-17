/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** Packet parser
*/

#ifndef PACKET_PARSER_H_
# define PACKET_PARSER_H_

#include "mystring.h"
#include "myvector.h"

typedef struct		s_zappy_packet
{
	const char	*raw;
	char		*command;
}			t_zappy_packet;

t_zappy_packet parse_zappy_packet(const char *data);

#endif /* PACKET_PARSER_H_ */