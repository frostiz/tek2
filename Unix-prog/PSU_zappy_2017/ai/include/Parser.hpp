/*
** EPITECH PROJECT, 2018
** ai
** File description:
** Parser.hpp
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <iostream>

class Parser {
public:
	Parser();
	~Parser() = default;
	int getPort() const;
	const std::string &getName() const;
	const std::string &getMachine() const;
	void initialize(char **);
	void setPort(const char *);
	void setName(const char *);
	void setMachine(const char *);
	void checkError();

private:
	int		_port;
	std::string	_name;
	std::string	_machine;
};

#endif /*PARSER_HPP_*/