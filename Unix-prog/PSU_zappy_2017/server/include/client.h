/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Client
*/

#ifndef CLIENT_H_
# define CLIENT_H_

#include "t_pos.h"
#include "zappy.h"
#include "mystring.h"
#include "team.h"
#include "packets_queue.h"
#include "inventory_manager.h"

#define FOOD_FREQUENCY 126

typedef struct			s_client
{
	t_zappy			*zappy;
	int			socket;
	int			uid;
	int 			incantation_level;
	int			authenticated;
	int 			is_ai;
	t_team			*team;
	t_string		buffer;
	char			*hostname;
	t_pos			position;
	int			lifetime;
	t_packets_queue		*packets_queue;
	t_inventory_manager	inventory;
	long long		next_food_timestamp;
	void			(*send_data)(struct s_client *this,
						const char *data);
	int			(*receive_data)(struct s_client *this);
	void			(*check_alive)(struct s_client *this);
	void			(*food_timer)(struct s_client *this);
}				t_client;

void			client_init(t_client *this, int socket,
					t_zappy *zappy);
void			client_init_position(t_pos *position,
				t_map_manager map_manager);
void			client_destroy(t_client *this);
void			send_data(struct s_client *this, const char *data);
int			receive_data(struct s_client *this);
int			find_client_amount_on_cell(t_client *client, int x,
				int y);
void			client_check_alive(t_client *this);
void			client_food_timer(t_client *this);

#endif /* CLIENT_H_ */