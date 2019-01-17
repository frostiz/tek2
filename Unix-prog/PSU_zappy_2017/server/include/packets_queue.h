/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Team manager
*/

#ifndef PACKET_QUEUE_H_
# define PACKET_QUEUE_H_

#include "myvector.h"

struct s_client;
struct s_packet_info;

typedef struct		s_packets_queue
{
	t_vector	packets;
	struct s_client	*client;
	void		(*add)(struct s_packets_queue *this, char *packet);
	void		(*process)(struct s_packets_queue *this);
	long long	(*last_timestamp)(struct s_packets_queue *this);
}			t_packets_queue;

typedef struct		s_packet_delay
{
	char		*packet;
	long long	execute_at;
}			t_packet_delay;

void			packets_queue_init(t_packets_queue *this,
					struct s_client *client);
void			packets_queue_add(t_packets_queue *this,
					char *packet);
void			packets_queue_process(t_packets_queue *this);
long long		packets_queue_last_timestamp(t_packets_queue *this);
struct s_packet_info	*get_packet_info(t_packets_queue *this,
					char *packet);

#endif //PACKET_QUEUE_H_
