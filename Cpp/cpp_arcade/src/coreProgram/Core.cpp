//
// EPITECH PROJECT, 2018
// Core.cpp
// File description:
// Core
//

#include "coreProgram/Core.hpp"

ar::Core::Core(const char *arg) : _arg(arg)
{
}

ar::Core::~Core()
{
}

bool ar::Core::CoreFunction()
{
	ar::Event lastEvent = AR_UNKNOWN;
	while (lastEvent != AR_EXIT) {
		lastEvent = Menu();
		if (!Game(lastEvent)) {
			return false;
		};
	}
	return true;
}

ar::Event ar::Core::Menu()
{
	try {
		if (_game.GetDisplay() == nullptr)
			_menu.SetLibraries(_arg);
		else
			_menu.SetMenu(_game.GetLastGameIndex(), _game.GetDisplay(),
				_game.GetOpenLib(), _game.GetCurrentUser());
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return AR_UNKNOWN;
	}
	_menu.SetUsers(_game.GetCurrentUser().username);
	return _menu.Start();
}

bool ar::Core::Game(ar::Event &event)
{
	switch (event) {
	case AR_EXIT:
		return true;
	case AR_VALIDATE:
		if (!_game.SetGame(_menu.GetCurrentLib(), _menu.GetLibs(),
			_menu.GetGames(), _menu.GetSelectedGame())) {
			event = AR_EXIT;
			return false;
		};
		_game.SetCurrentUser(_menu.GetCurrentUser());
		_game.SetCurrentLib(_menu.GetSelectedLib());
		_game.SetOpenLib(_menu.GetOpenLib());
		_game.Start();
		return true;
	default:
		event = AR_EXIT;
		return false;
	}
}
