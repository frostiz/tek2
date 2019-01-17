/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Packets queue utils
*/

#include "client.h"
#include "packets_queue.h"
#include "packet_manager.h"
#include "utils.h"

t_packet_info	*get_packet_info(t_packets_queue *this, char *packet)
{
	t_zappy_packet parsed_packet;
	t_packet_info *packet_info;

	parsed_packet = parse_zappy_packet(packet);
	if (parsed_packet.command == NULL) {
		this->client->send_data(this->client, "ko");
		destroy_packet(parsed_packet);
		return NULL;
	}
	if (strcmp(parsed_packet.command, "Incantation") == 0)
		incantation_first_call(this->client);
	packet_info = get_packet_info_by_header(parsed_packet.command);
	destroy_packet(parsed_packet);
	if (packet_info == NULL) {
		this->client->send_data(this->client, "ko");
		return NULL;
	}
	return packet_info;
}