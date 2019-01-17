//
// EPITECH PROJECT, 2018
// Menu.cpp
// File description:
// Menu
//

#include <exception>
#include <stdexcept>
#include <coreProgram/LaunchLibraries.hpp>
#include <dlfcn.h>
#include "coreProgram/ParseLibs.hpp"
#include "coreProgram/Menu.hpp"

ar::Menu::Menu()
{
	_menuFunctions[AR_NEXT_GRAPH_LIB] = &ar::Menu::NextLib;
	_menuFunctions[AR_PREV_GRAPH_LIB] = &ar::Menu::PrevLib;
}

ar::Menu::~Menu()
{
}

bool ar::Menu::SetLibraries(const std::string &arg)
{
	try {
		_libs = ParseLibs::getGraphs();
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return false;
	}
	_games = ParseLibs::getGames();
	_gamesName = ParseLibs::GetName(_games);
	_libsName = ParseLibs::GetName(_libs);

	if (_graphic == nullptr) {
		bool find = false;
		int i = 0;
		for (auto it = _libs.begin(); it != _libs.end(); ++it) {
			if ("./lib/" + *it == arg || "lib/" + *it == arg) {
				_currentLib = (i - 1);
				find = true;
			}
			i++;
		}
		if (!find) {
			throw std::invalid_argument(
				"Library " + arg + " not found.");
		}
	}
	_user.username = "Unknown";
	_user.score = 0;
	_user.time = 0;
	for (auto it = _games.begin(); it != _games.end(); ++it) {
		_users.push_back(_user);
	}
	return false;
}

bool ar::Menu::SetMenu(int lastGameLaunch, ar::IDisplay *&graphic,
	void *&openLib, const userInterface &lastScores
)
{
	_graphic = graphic;
	_graphic->initMenu(_gamesName, "", _libsName);
	_openLib = openLib;
	if (_users[lastGameLaunch].score < lastScores.score ||
		(_users[lastGameLaunch].score == lastScores.score &&
			_users[lastGameLaunch].time > lastScores.score)) {
		_users[lastGameLaunch].username = lastScores.username;
		_users[lastGameLaunch].score = lastScores.score;
		_users[lastGameLaunch].time = lastScores.time;
	}
	return false;
}

bool ar::Menu::SetUsers(std::string &name)
{

	_user.username = name;
	return true;
}

ar::Event ar::Menu::Start()
{
	int input = -1;

	_event = AR_UNKNOWN;
	if (_graphic == nullptr) {
		try {
			NextLib();
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
			return AR_UNKNOWN;
		}
	}
	while (_event != ar::Event::AR_EXIT) {
		if (_menuFunctions.find(_event) != _menuFunctions.end()) {
			try {
				(this->*(_menuFunctions[_event]))();
			} catch (const std::exception &e) {
				std::cout << e.what() << std::endl;
				return AR_UNKNOWN;
			}
		} else if (_event == AR_VALIDATE) {
			_graphic->destroyMenu();
			return AR_VALIDATE;
		} else {
			_graphic->refreshUsername(_user.username, input);
			_currentGame = _graphic->refreshMenu(_event, _users);
		}
		_event = _graphic->getEvent(input);
	}
	_graphic->destroyMenu();
	delete _graphic;
	return AR_EXIT;
}

void ar::Menu::NextLib()
{
	_currentLib += 1;
	if (_currentLib >= static_cast<int>(_libs.size())) {
		_currentLib = 0;
	}
	delete _graphic;

	_graphic = LaunchLibraries::LaunchLibs(_libs[_currentLib], _openLib);
	_graphic->initMenu(_gamesName, "", _libsName);
}

void ar::Menu::PrevLib()
{
	_currentLib -= 1;
	if (_currentLib < 0) {
		_currentLib = static_cast<int>(_libs.size() - 1);
	}
	delete _graphic;
	_graphic = LaunchLibraries::LaunchLibs(_libs[_currentLib], _openLib);
	_graphic->initMenu(_gamesName, "", _libsName);
}

ar::userInterface &ar::Menu::GetCurrentUser()
{
	return _user;
}

ar::IDisplay *&ar::Menu::GetCurrentLib()
{
	return _graphic;
}

std::vector<std::string> &ar::Menu::GetLibs()
{
	return _libs;
}

std::vector<std::string> &ar::Menu::GetGames()
{
	return _games;
}

int &ar::Menu::GetSelectedGame()
{
	return _currentGame;
}

int &ar::Menu::GetSelectedLib()
{
	return _currentLib;
}

void *&ar::Menu::GetOpenLib()
{
	return _openLib;
}
