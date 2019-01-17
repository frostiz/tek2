/*
** EPITECH PROJECT, 2018
** ServerMessage.hpp
** File description:
** Zappy
*/

#include <iostream>
#include <vector>

#ifndef SERVERMESSAGE_H_
# define SERVERMESSAGE_H_

class ServerMessage
{
	public:
		ServerMessage(const char *header);
		std::string getHeader();
		std::string getBody();
		ServerMessage &operator<<(std::string &obj);
		ServerMessage &operator<<(int &obj);
		void debug();

	private:
		std::string _header;
		std::string _body;
		int _index;

};


#endif /* SERVERMESSAGE_H_ */