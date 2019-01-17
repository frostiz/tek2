/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Packet parser
*/

#include "packet/packet_parser.h"
#include "myvector.h"


t_zappy_packet	parse_zappy_packet(const char *data)
{
	t_zappy_packet	packet;
	t_string	tmp;
	char		**splitted;


	string_init(&tmp, data);
	packet.raw = data;
	splitted = tmp.split_c(&tmp, ' ');
	packet.command = splitted[0];
	string_destroy(&tmp);

	return (packet);
}