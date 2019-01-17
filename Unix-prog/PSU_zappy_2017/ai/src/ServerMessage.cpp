/*
** EPITECH PROJECT, 2018
** ServerMessage.cpp
** File description:
** Zappy
*/

#include <fstream>
#include <sstream>
#include "ServerMessage.hpp"

ServerMessage::ServerMessage(const char *header) : _header(std::string(header))
{
	this->_body.append(this->_header);
}

std::string ServerMessage::getHeader()
{
	return this->_header;
}

std::string ServerMessage::getBody()
{
	return this->_body;
}

ServerMessage &ServerMessage::operator<<(std::string &obj)
{
	this->_body.append(" " + obj);
	return *this;
}

ServerMessage &ServerMessage::operator<<(int &obj)
{
	this->_body.append(" " + std::to_string(obj));
	return *this;
}

void ServerMessage::debug() {
	std::cout << this->_body << std::endl;
}