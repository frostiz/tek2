//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// main
//

#include <iostream>
#include "Engine.hpp"
#include "CLI.hpp"
#include "Parser.hpp"

int	main(int ac, char **av)
{
	(void)ac;
	if (av[1]) {
		nts::Engine	engine(av);

		engine.start();
	}
	else
		std::cout << "Usage: " << av[0] << " file.nts [input=value]" << std::endl;

	return (0);
}
