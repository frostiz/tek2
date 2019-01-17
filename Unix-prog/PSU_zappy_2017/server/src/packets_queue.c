/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Packets queue
*/

#include "client.h"
#include "packets_queue.h"
#include "packet_manager.h"
#include "utils.h"

static t_packet_delay	*packet_delay_init(long long delay, char *packet)
{
	t_packet_delay	*packet_delay;

	packet_delay = malloc(sizeof(t_packet_delay));
	packet_delay->packet = packet;
	packet_delay->execute_at = delay;
	return (packet_delay);
}

void	packets_queue_init(t_packets_queue *this, t_client *client)
{
	if (!this)
		return;
	vector_init(&this->packets);
	this->client = client;
	this->add = &packets_queue_add;
	this->process = &packets_queue_process;
	this->last_timestamp = &packets_queue_last_timestamp;
	printf("initialized packet queue\n");
}

void	packets_queue_add(t_packets_queue *this, char *packet)
{
	t_packet_delay	*packet_delay;
	t_packet_info	*packet_info;
	int		frequency;
	float		time_unit;
	long long	ms;

	packet_info = get_packet_info(this, packet);
	if (packet_info == NULL)
		return;
	frequency = this->client->zappy->startup_info.frequency;
	time_unit = ((float)packet_info->time_unit / (float)frequency) * 1000.f;
	packet_delay = packet_delay_init(this->last_timestamp(this) +
						(int)time_unit, packet);
	ms = (this->last_timestamp(this) + (int)time_unit) -
					current_timestamp();
	this->client->zappy->timer_manager->start(
				this->client->zappy->timer_manager, ms);
	free(packet_info->header);
	free(packet_info);
	vector_add(&this->packets, packet_delay);
}

void	packets_queue_process(t_packets_queue *this)
{
	t_packet_delay	*packet_delay;

	if (vector_total(&this->packets) <= 0)
		return;
	packet_delay = (t_packet_delay *)(vector_get(&this->packets, 0));
	if (current_timestamp() >= packet_delay->execute_at) {
		printf("execute packet\n");
		parse_packet(this->client, packet_delay->packet);
		vector_delete(&this->packets, 0);
		free(packet_delay->packet);
		free(packet_delay);
	}
}

long long	packets_queue_last_timestamp(t_packets_queue *this)
{
	t_packet_delay	*packet_delay;
	int		queue_size;
	long long	result;

	if (vector_total(&this->packets) <= 0)
		return (current_timestamp());
	queue_size = vector_total(&this->packets);
	packet_delay = (t_packet_delay *)(vector_get(&this->packets,
						queue_size - 1));
	result = packet_delay->execute_at;
	return (result);
}