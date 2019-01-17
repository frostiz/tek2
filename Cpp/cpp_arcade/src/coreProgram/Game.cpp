//
// EPITECH PROJECT, 2018
// Core.cpp
// File description:
// core
//

#include <iostream>
#include "coreProgram/LaunchLibraries.hpp"
#include "coreProgram/Game.hpp"

ar::Game::Game() : _currentLoadGame(0)
{
	_currentLib = nullptr;
	_currentUser.username = "";
	_currentUser.time = 0;
	_currentUser.score = 0;

	_gameFunctions[AR_NEXT_GRAPH_LIB] = &ar::Game::NextLib;
	_gameFunctions[AR_PREV_GRAPH_LIB] = &ar::Game::PrevLib;
	_gameFunctions[AR_NEXT_GAME] = &ar::Game::NextGame;
	_gameFunctions[AR_PREV_GAME] = &ar::Game::PrevGame;
	_gameFunctions[AR_RESTART] = &ar::Game::Restart;
}

bool ar::Game::SetGame(ar::IDisplay *&currentGraphique,
	std::vector<std::string> &lib, std::vector<std::string> &game,
	int &selectedGame
)
{
	_currentLib = currentGraphique;
	_libs = lib;
	_games = game;
	_currentLoadGame = selectedGame;
	_event = AR_UNKNOWN;

	for (const auto &it : _games) {
		try {
			_launchGames.push_back(
				LaunchLibraries::LaunchGame(it, _openGames));
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
			return false;
		}
	}
	InitSprites();
	return true;
}

void ar::Game::Start()
{
	bool end = false;

	int input = 0;
	while (!end && _event != AR_MENU) {
		_event = _currentLib->getEvent(input);
		if (!CheckEvent(_event))
			_launchGames[_currentLoadGame]->manageKey(_event);
		_launchGames[_currentLoadGame]->loop();
		_currentLib->displayGame(_currentUser,
			_launchGames[_currentLoadGame]->getMap());
		_currentUser.score = _launchGames[_currentLoadGame]->refreshScore();
		_currentUser.time = _launchGames[_currentLoadGame]->refreshTimer();
		end = _launchGames[_currentLoadGame]->isGameOver();
	}
	_launchGames.clear();
}

bool ar::Game::CheckEvent(const ar::Event &event)
{
	if (_gameFunctions.find(event) != _gameFunctions.end()) {
		return (this->*(_gameFunctions[event]))();
	} else if (event == AR_MENU) {
		return true;
	} else if (event == AR_EXIT) {
		exit(0);
	}
	return false;
}

void ar::Game::InitSprites()
{
	if (_currentLib->canHandleSprites() && _launchGames.size() != 0 &&
		_launchGames[_currentLoadGame] != nullptr) {
		_currentLib->loadResources(
			_launchGames[_currentLoadGame]->getSpritesPath(),
			_launchGames[_currentLoadGame]->getSprites());
	} else if (_launchGames.size() != 0 &&
		_launchGames[_currentLoadGame] != nullptr) {
		_currentLib->loadResources(
			_launchGames[_currentLoadGame]->getColors());
	}
}

void ar::Game::SetCurrentUser(ar::userInterface &user)
{
	_currentUser = user;
}

void ar::Game::SetCurrentLib(int &current)
{
	_selectedLib = current;
}

ar::Game::~Game()
{
}

ar::IDisplay *&ar::Game::GetDisplay()
{
	return _currentLib;
}

void ar::Game::SetOpenLib(void *&openLib)
{
	_openLib = openLib;
}

void *&ar::Game::GetOpenLib()
{
	return _openLib;
}

ar::userInterface &ar::Game::GetCurrentUser()
{
	return _currentUser;
}

bool ar::Game::PrevLib()
{
	_selectedLib -= 1;
	if (_selectedLib < 0) {
		_selectedLib = static_cast<int>(_libs.size() - 1);
	}
	delete _currentLib;
	_currentLib = LaunchLibraries::LaunchLibs(_libs[_selectedLib],
		_openLib);
	InitSprites();
	return true;
}

bool ar::Game::NextLib()
{
	_selectedLib += 1;
	if (_selectedLib >= static_cast<int>(_libs.size())) {
		_selectedLib = 0;
	}
	delete _currentLib;
	_currentLib = LaunchLibraries::LaunchLibs(_libs[_selectedLib],
		_openLib);
	InitSprites();
	return true;
}

bool ar::Game::NextGame()
{
	_currentLoadGame++;
	if (_currentLoadGame >= static_cast<int>(_games.size())) {
		_currentLoadGame = 0;
		InitSprites();
	} else {
		InitSprites();
	}
	return true;
}

bool ar::Game::PrevGame()
{
	_currentLoadGame--;
	if (_currentLoadGame < 0) {
		_currentLoadGame = static_cast<int>(_launchGames.size() - 1);
		InitSprites();
	} else {
		InitSprites();
	}
	return true;
}

int ar::Game::GetLastGameIndex() const
{
	return _currentLoadGame;
}

bool ar::Game::Restart()
{
	delete _launchGames[_currentLoadGame];
	_launchGames[_currentLoadGame] = LaunchLibraries::LaunchGame(
		_games[_currentLoadGame], _openGames);
	InitSprites();
	return true;
}
