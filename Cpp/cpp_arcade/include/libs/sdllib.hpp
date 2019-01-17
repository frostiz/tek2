//
// EPITECH PROJECT, 2018
// Sdllib.hpp
// File description:
// Sdllib
//

#ifndef CPP_ARCADE_SDL_HPP
#define CPP_ARCADE_SDL_HPP

#include "interfaces/IDisplay.hpp"
#include <unordered_map>
#include <vector>
#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <algorithm>

namespace ar {
	class Sdl : public IDisplay {
		public:
		Sdl();
		~Sdl() override;
		void initMenu(const std::vector<std::string> &menuChoices,
		const std::string &menuName, const std::vector<std::string> &libs) override;
		void loadResources(const std::map<unsigned char, colorVector> &color) override;
		void refreshUsername(std::string &name, int realKey) override;
		int refreshMenu(const ar::Event &key,
			const std::vector<userInterface> &dataArray) override;
		void destroyMenu() override;
		ar::Event getEvent(int &realKey) override;
		bool canHandleSprites() override;
		void displayGame(const userInterface &UI, Map &map) override;
		void loadResources(const std::string &filePath,
			const std::map<unsigned char, ar::spriteCoords> &sprites) override;

		private:
		std::map<unsigned char, ar::colorVector> _colors;
		std::map<unsigned char, ar::spriteCoords> _sprites;
		std::string _filePath;

		std::vector<std::string> _menuChoices;
		std::vector<std::string> _menuLibs;
		size_t _currentGame;
		bool _menuLib;
		bool _firstInit;
		int _key;
		int textSize;
		int _screenHeight;
		int _screenWidth;

		/**
		 *  SDL
		 */
		std::map<unsigned char, SDL_Texture *> _textures;
		std::map<std::pair<bool, int>, ar::Event> _events;
		SDL_Window *_window;
		SDL_Event _event;
		SDL_Surface *_text;
		TTF_Font *_font;
		TTF_Font *_littleFont;
		SDL_Renderer *_render;
		SDL_Surface *_sprite;
		SDL_Surface *_menuBG;

		/**
		 *  Rectangles
		 */
		SDL_Rect _menuSize;
		SDL_Rect _menuSrc;
		SDL_Rect _gameNameRect;
		SDL_Rect _usernameRect;

		/**
		 *  Colors
		 */
		SDL_Color whiteColor = {255, 255, 255, 0};
		SDL_Color redColor = {255, 0, 0, 0};

		/**
	 	*  Textures
	 	*/
		SDL_Texture* _texture;
		SDL_Texture* _texture2;
		SDL_Surface *_surfaceTest;
		SDL_Texture *_textureMenu;
		SDL_Texture *_usernameText;

		void displayTooltip(const char *);
		void DisplayScore(ar::userInterface &user);
		void DiplayGames(const std::vector<ar::userInterface> &dataArray);
		void DiplayLibs(const std::vector<ar::userInterface> &dataArray);
		void DisplayIngameScore(const ar::userInterface &UI, int squareSize, ar::Map &map);
		void DisplayIngameName(const ar::userInterface &UI, int squareSize, ar::Map &map);
		void DisplayIngameTime(const ar::userInterface &UI, int squareSize, ar::Map &map);
	};
}

#endif //CPP_ARCADE_SDL_HPP
