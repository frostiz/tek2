//
// EPITECH PROJECT, 2018
// Game.hpp
// File description:
// Game
//

#ifndef CPP_ARCADE_GAME_HPP
#define CPP_ARCADE_GAME_HPP

#include <vector>
#include <interfaces/IDisplay.hpp>
#include "Arcade.hpp"
#include "interfaces/IGame.hpp"

namespace ar {
	class Game {
		public:
		Game();
		~Game();

		bool CheckEvent(const ar::Event &event);

		bool SetGame(ar::IDisplay *&_currentGraphique,
			std::vector<std::string> &lib,
			std::vector<std::string> &game,
			int &selectedGame);
		void Start();

		void SetCurrentUser(ar::userInterface &user);

		void SetCurrentLib(int &current);

		void SetOpenLib(void *&openLib);

		void *&GetOpenLib();

		userInterface &GetCurrentUser();

		ar::IDisplay *&GetDisplay();

		int GetLastGameIndex() const;

		private:
		bool NextLib();
		bool PrevLib();
		bool NextGame();
		bool PrevGame();
		bool Restart();


		void InitSprites();

		ar::Event	_event;
		int 	_currentLoadGame;
		int 	_selectedLib;
		ar::IDisplay *_currentLib;
		std::vector<std::string> _libs;
		std::vector<std::string> _games;
		std::vector<ar::IGame *> _launchGames;

		std::map<ar::Event, bool(ar::Game::*)()> _gameFunctions;

		ar::userInterface _currentUser;

		void *_openLib;
		std::vector<void *> _openGames;
	};
}

#endif //CPP_ARCADE_GAME_HPP
