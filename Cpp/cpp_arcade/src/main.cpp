/*
** EPITECH PROJECT, 2018
** Created by victor on 09/03/18
** File description:
** main.cpp
*/

#include <signal.h>
#include "coreProgram/Core.hpp"
#include "interfaces/IGame.hpp"
#include "coreProgram/Menu.hpp"
#include "libs/sfmllib.hpp"
#include "games/Snake.hpp"

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Wrong number of argument" << std::endl;
		return 84;
	}
	ar::Core core(av[1]);
	if (!core.CoreFunction()) {
		return 84;
	}
	return 0;
}
