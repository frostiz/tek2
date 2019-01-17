/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** client
*/

#include <stdlib.h>
#include <unistd.h>
#include "client.h"
#include "packet_manager.h"
#include "utils.h"

void	client_init(t_client *this, int socket, t_zappy *zappy)
{
	if (this == NULL)
		return;
	if (socket != -1)
		this->socket = socket;
	this->uid = zappy->last_client_uid;
	this->team = NULL;
	this->zappy = zappy;
	this->send_data = &send_data;
	this->receive_data = &receive_data;
	this->check_alive = &client_check_alive;
	this->food_timer = &client_food_timer;
	this->authenticated = 0;
	this->is_ai = 1;
	string_init(&this->buffer, "");
	rpl_welcome(this);
	this->incantation_level = 1;
	inventory_manager_init(&this->inventory);
	client_init_position(&this->position, this->zappy->map_manager);
	this->packets_queue = malloc(sizeof(t_packets_queue));
	packets_queue_init(this->packets_queue, this);
}

void	client_destroy(t_client *this)
{
	if (this == NULL)
		return;
	if (shutdown(this->socket, 2) == 0)
		close(this->socket);
	if (this->team != NULL)
		this->team->remove(this->team, this);
	this->zappy->delete_client(this->zappy, this);
	string_destroy(&this->buffer);
}

void	send_data(t_client *this, const char *data)
{
	t_string	tmp;

	string_init(&tmp, data);
	tmp.append_c(&tmp, "\n");
	data = tmp.c_str(&tmp);
	if (write(this->socket, data, strlen(data)) == -1)
		perror("error while sending data\n");
	string_destroy(&tmp);
}

static void	execute_packet(t_client *this, char *packet)
{
	if (this->authenticated == 0 ||
		(this->authenticated == 1 && this->is_ai == 0)) {
		parse_packet(this, packet);
	} else {
		this->packets_queue->add(this->packets_queue, packet);
	}
}

int	receive_data(t_client *this)
{
	char		buffer[1024] = {0};
	t_string	tmp;
	char		*data;
	char		*tmp_buffer;
	int		valread;
	int		clrf;

	valread = read(this->socket, buffer, 1023);
	string_init(&tmp, this->buffer.str);
	tmp.append_c(&tmp, buffer);
	while ((clrf = tmp.find_c(&tmp, "\n", 0)) != -1) {
		data = calloc(clrf + 1, 1);
		tmp.copy(&tmp, data, clrf, 0);
		tmp_buffer = calloc(strlen(tmp.str) - clrf, 1);
		if (strlen(tmp.str) > (size_t)(clrf + 2))
			tmp.copy(&tmp, tmp_buffer, strlen(tmp.str), clrf + 2);
		printf("server: received '%s'\n", data);
		execute_packet(this, strdup(data));
		tmp.assign_c(&tmp, tmp_buffer);
		free(data);
		free(tmp_buffer);
	}
	this->buffer.assign_c(&this->buffer, tmp.str);
	string_destroy(&tmp);
	return (valread);
}