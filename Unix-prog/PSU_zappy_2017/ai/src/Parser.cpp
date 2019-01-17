/*
** EPITECH PROJECT, 2018
** ai
** File description:
** Parser.cpp
*/

#include <cstdlib>
#include <cstring>
#include "Parser.hpp"

Parser::Parser()
{
}

void	Parser::setPort(const char *str)
{
	if (str != NULL)
		_port = atoi(str);
}

void	Parser::setName(const char *str)
{
	if (str != NULL)
		_name = str;
}

void	Parser::setMachine(const char *str)
{
	if (str != NULL)
		_machine = str;
}

void	Parser::checkError()
{
	if (_port == 0)
		exit(84);
	std::cout << "Port = " << _port << std::endl;
	if (_name.empty())
		exit(84);
	std::cout << "Name = " << _name << std::endl;
	if (_machine.empty())
		_machine = "127.0.0.1";
	std::cout << "Machine = " << _machine << std::endl;
}

void	Parser::initialize(char **av)
{
	int i = 0;

	while (av[i] != NULL) {
		if (strcmp(av[i], "-p") == 0)
			setPort(av[i + 1]);
		else if (strcmp(av[i], "-n") == 0)
			setName(av[i + 1]);
		else if (strcmp(av[i], "-h") == 0)
			setMachine(av[i + 1]);
		i++;
	}
	checkError();
}
int	Parser::getPort() const
{
	return _port;
}
const std::string &Parser::getName() const
{
	return _name;
}

const std::string &Parser::getMachine() const
{
	return _machine;
}