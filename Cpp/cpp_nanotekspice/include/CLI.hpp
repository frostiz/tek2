/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** cpp_nanotekspice file
*/

#ifndef CPP_NANOTEKSPICE_CLI_HPP
#define CPP_NANOTEKSPICE_CLI_HPP

#include <iostream>
#include <functional>
#include <unordered_map>
#include "Circuit.hpp"

class CLI
{
	public:
	explicit CLI(nts::Circuit *);
	~CLI();

	void	changeInputValue(const std::string &);
	void	read();
	void	my_exit();
	void	display();
	void	simulate();
	void	loop();
	void	dump();

	private:
	nts::Circuit							*_circuit;
	std::unordered_map<std::string, std::function<void(void)>>	_actions;
};

#endif //CPP_NANOTEKSPICE_CLI_HPP
