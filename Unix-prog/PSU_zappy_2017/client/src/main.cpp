/*
** EPITECH PROJECT, 2018
** client
** File description:
** main
*/

#include "Core.hpp"

int	main(int ac, const char **av)
{
	Core *core = new Core(ac, &av[1]);

	core->initialize();
	return (0);
}
