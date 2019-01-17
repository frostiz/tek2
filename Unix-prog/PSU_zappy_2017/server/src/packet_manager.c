/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** PacketManager
*/

#include <string.h>
#include "packet_manager.h"
#include "packet/packet_parser.h"

static char *header_id[] = { FORWARD, RIGHT, LEFT, INVENTORY, LOOK,
				CONNECT_NBR, TAKE, SET, INCANTATION,
				BROADCAST, MSZ, BCT, MCT, TNA,
				PPO, PLV, PIN, SGT, SST, NULL };

static handler *p[] = { forward_command, right_command, left_command,
	inventory_command, look_command, connect_nbr_command, take_command,
	set_command, incantation_command, broadcast_command, msz_command,
	bct_command, mct_command, tna_command, ppo_command, plv_command,
	pin_command, sgt_command, sst_command };

void	parse_packet(t_client *client, const char *data)
{
	t_zappy_packet	packet;

	packet = parse_zappy_packet(data);

	printf("raw : '%s'\n", packet.raw);
	printf("command : '%s'\n", packet.command);

	if (client->authenticated == 0) {
		handshake_command(client, packet);
		destroy_packet(packet);
		return;
	}

	if (packet.command != NULL)
		process_packet(client, packet);
	else
		client->send_data(client, "ko");
	destroy_packet(packet);
}

void	process_packet(t_client *client, t_zappy_packet packet)
{
	int	packet_id = -1;

	packet_id = get_packet_id(packet.command);
	if (packet_id >= 0 && packet_id <= 9 && client->is_ai == 0) {
		rpl_suc(client);
		return;
	} else if (packet_id > 9 && client->is_ai == 1) {
		client->send_data(client, "ko");
		return;
	}
	if (packet_id != -1)
		p[packet_id](client, packet);
	else {
		printf("server: unhandled packet header: '%s'\n",
			packet.command);
		if (client->is_ai == 1)
			client->send_data(client, "ko");
		else
			rpl_suc(client);
	}
}

int	get_packet_id(char *header)
{
	t_packet_info	*info;

	if (header == NULL)
		return (-1);
	for (int i = 0; header_id[i] != NULL; i++) {
		info = get_header_info(header_id[i]);
		if (strcmp(info->header, header) == 0) {
			printf("packet time unit : %d\n", info->time_unit);
			free(info->header);
			free(info);
			return (i);
		}
		free(info->header);
		free(info);
	}
	return (-1);
}

t_packet_info	*get_header_info(char *header)
{
	t_string	tmp;
	t_packet_info	*info;
	char		**splitted;

	string_init(&tmp, header);
	splitted = tmp.split_c(&tmp, '|');
	info = malloc(sizeof(t_packet_info));
	info->header = NULL;
	info->time_unit = -1;
	for (size_t i = 0; splitted[i] != NULL; i++) {
		if (i == 0)
			info->header = strdup(splitted[i]);
		else if (i == 1)
			info->time_unit = atoi(splitted[i]);
	}
	string_destroy(&tmp);
	return (info);
}

t_packet_info	*get_packet_info_by_header(char *header)
{
	t_string	tmp;
	t_packet_info	*info;
	char		**splitted;

	for (int i = 0; header_id[i] != NULL; i++) {
		string_init(&tmp, header_id[i]);
		splitted = tmp.split_c(&tmp, '|');
		info = malloc(sizeof(t_packet_info));
		info->header = NULL;
		info->time_unit = -1;
		for (size_t i = 0; splitted[i] != NULL; i++) {
			if (i == 0)
				info->header = strdup(splitted[i]);
			else if (i == 1)
				info->time_unit = atoi(splitted[i]);
		}
		string_destroy(&tmp);
		if (strcmp(info->header, header) == 0)
			return (info);
		free(info->header);
		free(info);
	}
	return (NULL);
}