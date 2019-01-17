//
// EPITECH PROJECT, 2018
// LaunchLibraries
// File description:
// LaunchLibraries
//

#include <iostream>
#include <dlfcn.h>
#include "coreProgram/LaunchLibraries.hpp"

ar::IDisplay *ar::LaunchLibraries::LaunchLibs(const std::string &currentLib,
	void *&open)
{
	if (open != nullptr) {
		open = nullptr;
	}
	std::string file = "./lib/" + currentLib;

	open = dlopen(file.c_str(), RTLD_NOW);
	if (!open) {
		throw std::invalid_argument("Cannot open library");
	}
	ar::createDisplay *create_graphic = (ar::createDisplay *)dlsym(open,
		"createDisplay");
	const char *dlsym_error = dlerror();
	if (dlsym_error) {
		dlclose(open);
		open = nullptr;
		throw std::runtime_error("Unknown symbol");
	}
	return create_graphic();
}

ar::IGame *ar::LaunchLibraries::LaunchGame(const std::string &currentGame,
	std::vector<void *> &open)
{
	std::string file = "./games/" + currentGame;

	open.insert(open.begin(), dlopen(file.c_str(), RTLD_NOW));
	if (!open[0]) {
		throw std::invalid_argument("Cannot open library");
	}
	ar::createGame *create_game = (ar::createGame *)dlsym(open[0],
		"createGame");
	const char *dlsym_error = dlerror();
	if (dlsym_error) {
		dlclose(open[0]);
		throw std::runtime_error("Unknown symbol");
	}
	return create_game();
}
