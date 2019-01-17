/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** cpp_nanotekspice file
*/

#include <Circuit.hpp>
#include <Parser.hpp>
#include <CLI.hpp>
#include "Engine.hpp"

nts::Engine::Engine(char **args)
	: _args(args)
{

}

nts::Engine::~Engine()
{

}

void	nts::Engine::start()
{
	nts::Circuit	circuit;
	Parser	parser(_args[1], &circuit, &_args[2]);
	CLI	command(&circuit);

	try {
		parser.parse();
		circuit.simulate();
		circuit.setSortedOutputs();
		circuit.displayOutputs();
		command.read();
	} catch (NtsError &e) {
		std::cout << e.what() << std::endl;
	}
}
