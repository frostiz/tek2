/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Zappy
*/

#include "server.h"
#include "zappy.h"
#include "client.h"

void	zappy_init(t_zappy *this, char **teams)
{
	if (this == NULL)
		return;
	this->server_socket = -1;
	this->last_client_uid = 1;
	vector_init(&this->clients);
	this->start_server = &start_server;
	this->update_read_fds = &update_read_fds;
	this->start_accept = &start_accept;
	this->incoming_connection = &incoming_connection;
	this->handle_receive = &handle_receive;
	this->delete_client = &delete_client;
	this->find_client_by_id = &find_client_by_id;
	this->send_graphic = &send_graphic;
	this->team_manager = malloc(sizeof(t_team_manager));
	team_manager_init(this->team_manager, teams,
		this->startup_info.client_amount);
	this->timer_manager = malloc(sizeof(t_timer_manager));
	timer_manager_init(this->timer_manager);
	this->incantation_manager = malloc(sizeof(t_incantation_manager));
	incantation_manager_init(this->incantation_manager, this);
}

void	start_server(t_zappy *this)
{
	this->server_socket = start_listen(this, this->startup_info.port);
	if (this->server_socket != -1)
		this->start_accept(this);
}

void	start_accept(t_zappy *this)
{
	int maxSd;
	int activity;
	t_client *client;

	printf("Waiting for connections ...\n");
	while (1) {
		maxSd = this->update_read_fds(this);
		activity = select(maxSd + 1, &this->read_fds, NULL, NULL, NULL);
		if ((activity < 0) && (errno != EINTR))
			printf("ZAPPY socket : error during select\n");
		if (this->incoming_connection(this) == 0)
			this->handle_receive(this);
		this->timer_manager->process(this->timer_manager,
			this->read_fds);
		for (int i = 0; i < vector_total(&this->clients); i++) {
			client = (t_client*)vector_get(&this->clients, i);
			client->packets_queue->process(client->packets_queue);
			client->check_alive(client);
		}
	}
}

void	handle_receive(t_zappy *this)
{
	int		valread;
	t_client	*client;

	for (int i = 0; i < vector_total(&this->clients); i++) {
		client = (t_client*)vector_get(&this->clients, i);
		if (FD_ISSET(client->socket, &this->read_fds)) {
			valread = client->receive_data(client);
			if (valread == 0) {
				printf("ZAPPY socket : client disconnect\n");
				client_destroy(client);
			}
			break;
		}
	}
}

void	delete_client(t_zappy *this, t_client *client)
{
	for (int i = 0; i < vector_total(&this->clients); i++) {
		t_client *tmp = (t_client *)vector_get(&this->clients, i);
		if (tmp == client) {
			vector_delete(&this->clients, i);
			break;
		}
	}
}