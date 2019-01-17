/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Packet manager utils
*/

#include "packet_manager.h"

void destroy_packet(t_zappy_packet packet)
{
	if (packet.command != NULL)
		free(packet.command);
}