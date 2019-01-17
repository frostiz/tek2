/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** RPL_WELCOME
*/

#include "packet_manager.h"
#include "mystring.h"

void	rpl_welcome(t_client *client)
{
	t_string	response;

	string_init(&response, "");
	response.append_c(&response, "WELCOME");
	client->send_data(client, response.c_str(&response));
	string_destroy(&response);
}