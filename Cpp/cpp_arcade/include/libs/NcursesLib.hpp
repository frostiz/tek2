//
// EPITECH PROJECT, 2018
// NcursesLibs.hpp
// File description:
// NcursesLib
//

#ifndef CPP_ARCADE_NCURSESLIB_HPP
#define CPP_ARCADE_NCURSESLIB_HPP

#include <ncurses.h>
#include "interfaces/IDisplay.hpp"
#define MENU_COLORS 8

namespace ar {
	class NcursesLib : public IDisplay {
		public:
		NcursesLib();

		~NcursesLib() override;

		void initMenu(const std::vector<std::string> &menuChoices,
			const std::string &menuName, const std::vector<std::string> &libs
		) override;

		void refreshUsername(std::string &name, int realKey) override;
		int refreshMenu(const ar::Event &key, const std::vector<userInterface> &dataArray) override;
		void destroyMenu() override;
		ar::Event getEvent(int &realKey) override;
		bool canHandleSprites() override;
		void displayGame(const userInterface &UI, Map &map) override;
		void loadResources(const std::string &filePath, const std::map<unsigned char, spriteCoords> &sprites);
		void loadResources(const std::map<unsigned char, colorVector> &colors) override;

		void showStrInColor(const int &y, const int &x, const std::string &str, const int &pair);
		void displayAsciiArt(int &);
		void displayGames(int &);
		void displayLibs(int &);
		void displayUser(int &, const std::vector<userInterface> &);

		private:
		std::map<unsigned char, ar::colorVector> _colors;
		std::vector<std::string> _menuChoices;
		std::vector<std::string> _libChoices;
		WINDOW *_window;
		size_t _currentGame;
		std::string _username;
	};
}

#endif //CPP_ARCADE_NCURSESLIB_HPP
