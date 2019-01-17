/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** server
*/

#include <ifaddrs.h>
#include "zappy.h"
#include "client.h"

int	init_socket(void)
{
	int	server_fd;
	int	opt = 1;

	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd == 0) {
		perror("socket failed");
		exit(EXIT_FAILURE);
	}
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
			&opt, sizeof(opt))) {
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	return (server_fd);
}

int	start_listen(t_zappy *this, int port)
{
	int			server_fd;

	server_fd = init_socket();
	this->address.sin_family = AF_INET;
	this->address.sin_addr.s_addr = INADDR_ANY;
	this->address.sin_port = htons(port);

	if (bind(server_fd, (struct sockaddr *)&this->address,
			sizeof(this->address)) < 0) {
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	if (listen(server_fd, 3) < 0) {
		perror("listen");
		exit(EXIT_FAILURE);
	}
	return (server_fd);
}

int		update_read_fds(t_zappy *this)
{
	int	maxSd = this->server_socket;
	int	s;

	FD_ZERO(&this->read_fds);
	FD_SET(this->server_socket, &this->read_fds);
	for (int i = 0; i < vector_total(&this->clients); i++) {
		s = ((t_client*)vector_get(&this->clients, i))->socket;
		if (s > 0)
			FD_SET(s, &this->read_fds);
		if (s > maxSd)
			maxSd = s;
	}
	for (int i = 0; i < vector_total(&this->timer_manager->timers); i++) {
		s = ((t_timer*)vector_get(&this->timer_manager->timers, i))->fd;
		if (s > 0)
			FD_SET(s, &this->read_fds);
		if (s > maxSd)
			maxSd = s;
	}
	return (maxSd);
}

int	incoming_connection(t_zappy *this)
{
	int		new_socket;
	t_client	*client;
	int		addrlen = sizeof(this->address);

	if (FD_ISSET(this->server_socket, &this->read_fds)) {
		new_socket = accept(this->server_socket,
					(struct sockaddr *)&this->address,
					(socklen_t *)&addrlen);
		if (new_socket < 0)
			exit(84);
		client = malloc(sizeof(t_client));
		client_init(client, new_socket, this);
		client->hostname = get_connection_hostname(new_socket);
		vector_add(&this->clients, client);
		++this->last_client_uid;
		printf("ZAPPY socket : connection on socket %d\n", new_socket);
		return 1;
	}
	return 0;
}

char	*get_connection_hostname(int socket)
{
	struct sockaddr_in	addr;
	struct ifaddrs		*ifaddr;
	struct ifaddrs		*ifa;
	struct sockaddr_in	*inaddr;
	socklen_t		addr_len;
	char			*hostname = NULL;

	addr_len = sizeof(addr);
	getsockname(socket, (struct sockaddr*)&addr, &addr_len);
	getifaddrs(&ifaddr);
	for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
		if (ifa->ifa_addr && AF_INET == ifa->ifa_addr->sa_family) {
			inaddr = (struct sockaddr_in*)ifa->ifa_addr;
			if (inaddr->sin_addr.s_addr == addr.sin_addr.s_addr &&
				ifa->ifa_name)
				hostname = inet_ntoa(inaddr->sin_addr);
		}
	}
	freeifaddrs(ifaddr);
	return (hostname);
}