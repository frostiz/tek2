/*
** EPITECH PROJECT, 2018
** ai
** File description:
** main
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Ai.hpp"
#include "Parser.hpp"
#include "CommandHandler.hpp"
#include "Algorithm.hpp"

static	void print_help(char *str)
{
	printf("USAGE:\t%s -p port -n name -h machine\n\t", str);
	printf("port\tis the port number\n\t");
	printf("name\tis the name of the team\n\t");
	printf("machine\tis the name of the machine; localhost by default\n");
	exit(0);
}

static	void check_usage(int ac, char **av)
{
	int i = 0;

	if (ac < 5)
		print_help(av[0]);
	while (av[i] != NULL) {
		if ((strcasecmp(av[i], "--help") == 0) ||
			(strcasecmp(av[i], "-help") == 0))
			print_help(av[0]);
		i++;
	}
}

int	main(int ac, char **av)
{
	Parser	parse;
	check_usage(ac, av);
	parse.initialize(av);
	Ai *ai = new Ai(parse.getMachine(), parse.getPort(), parse.getName());
	Algorithm *algo = new Algorithm(ai);
	algo->live();
	return 0;
}