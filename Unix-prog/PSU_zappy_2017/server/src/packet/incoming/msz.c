/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** msz command
*/

#include "packet_manager.h"

void	msz_command(t_client *client, t_zappy_packet packet)
{
	(void)packet;
	rpl_msz(client, 0);
}