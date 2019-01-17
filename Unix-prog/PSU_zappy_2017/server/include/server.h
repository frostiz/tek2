/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** server.h
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <sys/time.h>

int	init_socket(void);
char	*get_connection_hostname(int socket);

#endif /* SERVER_H_ */