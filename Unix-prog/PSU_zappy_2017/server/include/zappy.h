/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Zappy
*/

#ifndef ZAPPY_H_
# define ZAPPY_H_

#include "server.h"
#include "parsing.h"
#include "myvector.h"
#include "team_manager.h"
#include "map_manager.h"
#include "incantation_manager.h"
#include "timer_manager.h"

struct s_client;

typedef struct			s_zappy
{
	int				server_socket;
	struct sockaddr_in		address;
	fd_set				read_fds;
	t_vector			clients;
	t_server_info			startup_info;
	t_team_manager			*team_manager;
	t_timer_manager			*timer_manager;
	t_map_manager			map_manager;
	t_incantation_manager		*incantation_manager;
	int 				last_client_uid;
	void		(*start_server)(struct s_zappy *this);
	int		(*update_read_fds)(struct s_zappy *this);
	void		(*start_listen)(struct s_zappy *this, int port);
	void		(*start_accept)(struct s_zappy *this);
	int		(*incoming_connection)(struct s_zappy *this);
	void		(*handle_receive)(struct s_zappy *this);
	void		(*delete_client)(struct s_zappy *this,
					struct s_client *client);
	struct s_client	*(*find_client_by_id)(struct s_zappy *this,
						int uid);
	void 		(*send_graphic)(struct s_client *client, char *str,
				int broadcast);
}				t_zappy;

void			zappy_init(t_zappy *this, char **teams);
void			start_server(t_zappy *this);
int			start_listen(t_zappy *this, int port);
void			start_accept(t_zappy *this);
int			update_read_fds(t_zappy *this);
int			incoming_connection(t_zappy *this);
void			handle_receive(t_zappy *this);
void			delete_client(t_zappy *this,
				struct s_client *client);
struct s_client		*find_client_by_id(t_zappy *this, int uid);
void			send_graphic(struct s_client *client, char *str,
				int broadcast);

#endif /* ZAPPY_H_ */