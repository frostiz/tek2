/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** User command
*/

#include "packet_manager.h"
#include "utils.h"

void	handshake_command(t_client *client, t_zappy_packet packet)
{
	t_team_manager *team_manager;
	t_team		*team;

	team_manager = client->zappy->team_manager;
	team = team_manager->find_by_name(team_manager, packet.raw);
	if (strcasecmp(packet.raw, "graphic") == 0) {
		graphic_command(client, packet);
		client->authenticated = 1;
		client->is_ai = 0;
		return;
	}
	if (team == NULL) {
		client->send_data(client, "ko");
		return;
	}
	if (team->add(team, client)) {
		client->team = team;
		client->authenticated = 1;
		client->food_timer(client);
		rpl_handshake(client);
		rpl_pnw(client, client, 1);
	} else
		client->send_data(client, "ko");
}