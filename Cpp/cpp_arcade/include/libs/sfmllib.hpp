//
// EPITECH PROJECT, 2018
// SfmlLib.hpp
// File description:
// sfmllib
//

#ifndef CPP_ARCADE_SFLMLIB_HPP
#define CPP_ARCADE_SFLMLIB_HPP

#include <SFML/Graphics.hpp>
#include "interfaces/IDisplay.hpp"
#include <unordered_map>
#include <vector>

namespace ar {
	class sfmllib : public IDisplay {
		public:
		sfmllib();

		~sfmllib() override;

		void initMenu(const std::vector<std::string> &menuChoices,
			const std::string &menuName,
			const std::vector<std::string> &libs
		) override;

		void loadResources(
			const std::map<unsigned char, colorVector> &color
		) override;

		void refreshUsername(std::string &name, int realKey) override;

		int refreshMenu(const ar::Event &key,
			const std::vector<userInterface> &dataArray
		) override;

		void destroyMenu() override;

		ar::Event getEvent(int &realKey) override;

		bool canHandleSprites() override;

		void displayGame(const userInterface &UI, Map &map) override;

		void loadResources(const std::string &filePath,
			const std::map<unsigned char, spriteCoords> &sprites
		) override;

		private:
		std::map<unsigned char, ar::colorVector> _colors;
		std::map<unsigned char, ar::spriteCoords> _sprites;
		std::map<unsigned char, sf::Texture> _textures;
		std::map<std::pair<bool, int>, ar::Event> _events;

		std::string _filePath;
		sf::RenderWindow *_window;
		sf::Font _font;
		sf::Text _text;
		sf::Text _username;
		sf::Text _tmpText;
		std::vector<std::string> _menuChoices;
		std::vector<std::string> _libChoices;
		size_t _currentGame;
		sf::Vector2u _screenSize;
		size_t _screenWidth;
		size_t _screenHeight;
		void DisplayScore(float x, float y, ar::userInterface &);
		void writeDataInGame(const ar::userInterface &UI);
		std::vector<std::string> refreshIt(sf::Text &title);
		void displayMenu(float, float, const std::vector<ar::userInterface> &dataArray);
	};
}

#endif //CPP_ARCADE_SFLMLIB_HPP
