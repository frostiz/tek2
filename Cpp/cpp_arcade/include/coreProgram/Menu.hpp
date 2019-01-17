//
// EPITECH PROJECT, 2018
// Menu.hpp
// File description:
// Menu
//

#ifndef CPP_ARCADE_HANDLE_HPP
#define CPP_ARCADE_HANDLE_HPP

#include <iostream>
#include <vector>
#include <unordered_map>
#include "interfaces/IDisplay.hpp"
#include "interfaces/IGame.hpp"
#include "Arcade.hpp"

namespace ar {
	class Menu {
		public:
		Menu();

		~Menu();

		ar::Event Start();

		bool SetLibraries(const std::string &arg);

		bool SetMenu(int lastGameLaunch,
			ar::IDisplay *&graphic, void *&openLib, const userInterface &lastUser
		);

		bool SetUsers(std::string &name);

		ar::IDisplay *&GetCurrentLib();

		std::vector<std::string> &GetLibs();

		std::vector<std::string> &GetGames();

		ar::userInterface &GetCurrentUser();

		int &GetSelectedGame();

		int &GetSelectedLib();

		void *&GetOpenLib();

		private:
		std::unordered_map<ar::Event, void(ar::Menu::*)()> _menuFunctions;
		std::vector<std::string> _libs;
		std::vector<std::string> _libsName;
		std::vector<std::string> _gamesName;
		std::vector<std::string> _games;
		ar::IDisplay *_graphic = nullptr;

		void NextLib();

		void PrevLib();

		int _currentLib;
		int _currentGame = 0;
		ar::Event _event;
		userInterface _user;
		std::vector<ar::userInterface> _users;
		void *_openLib = nullptr;
	};
};

#endif //CPP_ARCADE_HANDLE_HPP
