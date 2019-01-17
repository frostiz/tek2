/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** rpl_handshake
*/

#include "packet_manager.h"

void	rpl_handshake(t_client *client)
{
	char	response[1024];
	int	slot_remaining;
	int	map_size_x;
	int	map_size_y;

	slot_remaining = client->team->slot_remaining(client->team);
	map_size_x = client->zappy->map_manager.width;
	map_size_y = client->zappy->map_manager.height;
	sprintf(response, "%d\n%d %d", slot_remaining, map_size_x, map_size_y);
	client->send_data(client, response);
}