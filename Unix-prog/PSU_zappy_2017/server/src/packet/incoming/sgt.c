/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** sgt command
*/

#include "packet_manager.h"

void	sgt_command(t_client *client, t_zappy_packet packet)
{
	(void)packet;
	rpl_sgt(client, 0);
}