//
// EPITECH PROJECT, 2018
// Sdllib.cpp
// File description:
// sdllib
//

#include <iostream>
#include <sstream>
#include <cstring>
#include <cmath>
#include <zconf.h>
#include <libs/sdllib.hpp>

ar::Sdl::Sdl()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDL_Quit();
		throw std::invalid_argument("Could not init SDL");
	}
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
	if (TTF_Init() == -1) {
		SDL_Quit();
		throw std::invalid_argument("Could not load TTF_Init");
	}
	_screenWidth = 1920;
	_screenHeight = 1080;
	_window = SDL_CreateWindow("SDL 2.0 Window", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight,
		SDL_WINDOW_FULLSCREEN | SDL_WINDOW_RESIZABLE);
	if (!_window) {
		SDL_Quit();
		throw std::invalid_argument("Could not create window");
	}
	if (!(_font = TTF_OpenFont("resources/Colleged.ttf", 30)))
		throw std::invalid_argument("Could not load font");
	if (!(_littleFont = TTF_OpenFont("resources/Colleged.ttf", 15)))
		throw std::invalid_argument("Could not load font");
	if (!(_render = SDL_CreateRenderer(_window, -1,
		SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_PRESENTVSYNC)))
		throw std::invalid_argument("Could not create render");
	_currentGame = 0;
	_menuLib = false;
	_firstInit = false;
	_events = {
		{{false, SDLK_ESCAPE}, ar::Event::AR_EXIT},
		{{false, SDLK_UP}, ar::Event::AR_UP},
		{{false, SDLK_DOWN}, ar::Event::AR_DOWN},
		{{false, SDLK_LEFT}, ar::Event::AR_LEFT},
		{{false, SDLK_RIGHT}, ar::Event::AR_RIGHT},
		{{false, SDLK_RETURN}, ar::Event::AR_VALIDATE},
		{{false, SDLK_1}, ar::Event::AR_PREV_GAME},
		{{false, '&'}, ar::Event::AR_PREV_GAME},
		{{false, SDLK_2}, ar::Event::AR_NEXT_GAME},
		{{false, 233}, ar::Event::AR_NEXT_GAME},
		{{false, SDLK_3}, ar::Event::AR_PREV_GRAPH_LIB},
		{{false, SDLK_QUOTEDBL}, ar::Event::AR_PREV_GRAPH_LIB},
		{{false, SDLK_4}, ar::Event::AR_NEXT_GRAPH_LIB},
		{{false, SDLK_QUOTE}, ar::Event::AR_NEXT_GRAPH_LIB},
		{{false, SDLK_m}, ar::Event::AR_MENU},
		{{false, SDLK_r}, ar::Event::AR_RESTART},
		{{false, SDLK_p}, ar::Event::AR_PAUSE}};
}

ar::Sdl::~Sdl()
{
	SDL_DestroyRenderer(_render);
	IMG_Quit();
	TTF_CloseFont(_font);
	TTF_CloseFont(_littleFont);
	TTF_Quit();
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

void ar::Sdl::destroyMenu()
{
	return;
}

ar::Event ar::Sdl::getEvent(int &realKey)
{
	realKey = -1;
	if (SDL_PollEvent(&_event)) {
		switch (_event.type) {
		case SDL_QUIT: {
			return AR_EXIT;
		}
		case SDL_KEYUP:
			realKey = _event.key.keysym.sym;
			if (_events.find({false, _event.key.keysym.sym}) !=
				_events.end())
				return _events[{false, _event.key.keysym.sym}];
			else
				return ar::AR_UNKNOWN;
		}
	}
	return AR_UNKNOWN;
}

bool ar::Sdl::canHandleSprites()
{
	return true;
}

void ar::Sdl::loadResources(const std::string &filePath,
	const std::map<unsigned char, ar::spriteCoords> &sprites)
{
	SDL_Rect tmpRect {};

	_filePath = filePath;
	_sprites = sprites;
	_textures.clear();
	for (auto it = _sprites.begin(); it != _sprites.end(); it++) {
		_sprite = IMG_Load(_filePath.c_str());
		tmpRect.x = it->second.x;
		tmpRect.y = it->second.y;
		tmpRect.w = it->second.width;
		tmpRect.h = it->second.height;
		if (tmpRect.h == 32)
			textSize = 2;
		else
			textSize = 1;
		if (!(_surfaceTest = IMG_Load("./resources/empty.png")))
			throw std::invalid_argument(
				"Could not load resources/empty.png");
		SDL_BlitSurface(_sprite, &tmpRect, _surfaceTest, nullptr);
		SDL_UnlockSurface(_surfaceTest);
		_texture2 = SDL_CreateTextureFromSurface(_render, _surfaceTest);
		SDL_LockSurface(_surfaceTest);
		_textures[it->first] = _texture2;
		SDL_SetTextureBlendMode(_textures[it->first],
			SDL_BLENDMODE_BLEND);
		SDL_FreeSurface(_sprite);
		SDL_FreeSurface(_surfaceTest);
	}
}

void ar::Sdl::loadResources(
	const std::map<unsigned char, ar::colorVector> &colors)
{
	_colors = colors;
}

void ar::Sdl::refreshUsername(std::string &name, int realKey)
{
	const char *gameName;

	if (realKey >= SDLK_a && realKey < SDLK_z) {
		name += (realKey);
	} else if (realKey == SDLK_BACKSPACE && name.size() > 0) {
		name.pop_back();
	}
	gameName = name.c_str();
	if (strlen(gameName) == 0)
		gameName = "unknown";
	{
		SDL_Surface *surface;
		surface = TTF_RenderText_Solid(_font, gameName,
			this->whiteColor);
		_usernameText = SDL_CreateTextureFromSurface(_render, surface);
		_usernameRect.x = 0;
		_usernameRect.y = 0;
		_usernameRect.w = surface->w;
		_usernameRect.h = surface->h;
		SDL_FreeSurface(surface);
	}
}

void ar::Sdl::initMenu(const std::vector<std::string> &menuChoices,
	const std::string &menuName, const std::vector<std::string> &lib)
{
	int x = 2;
	int count = 0;

	(void)menuName;
	_menuLibs.clear();
	_menuChoices.clear();
	_menuChoices = menuChoices;
	_menuLibs = lib;
	if (!_firstInit) {
		_textureMenu = IMG_LoadTexture(_render, "./resources/arcade.png");
		SDL_GetWindowSize(_window, &_screenWidth, &_screenHeight);
		_menuSrc.x = 0;
		_menuSrc.y = 0;
		_menuSrc.w = _screenWidth;
		_menuSrc.h = _screenHeight;
		_menuSize.x = 0;
		_menuSize.y = 0;
		_menuSize.w = _screenWidth;
		_menuSize.h = _screenHeight;
		SDL_RenderCopy(_render, _textureMenu, &_menuSize, &_menuSrc);
		SDL_RenderPresent(_render);
		usleep(550000);
		while (count < 100) {
			SDL_RenderClear(_render);
			_menuSrc.h += x;
			_menuSrc.w += x;
			_menuSize.x += x;
			_menuSize.y += x;
			SDL_RenderCopy(_render, _textureMenu, &_menuSize,
				&_menuSrc);
			SDL_RenderPresent(_render);
			usleep(15000);
			count++;
		}
		_firstInit = true;
	}
}

void ar::Sdl::displayTooltip(const char *gameName)
{
	SDL_Surface *surface;
	SDL_Texture *texture;

	surface = TTF_RenderText_Solid(_font, gameName, this->whiteColor);
	texture = SDL_CreateTextureFromSurface(_render, surface);
	_gameNameRect.x = static_cast<int>((_screenWidth / 2) -
		(strlen(gameName) * 8));
	_gameNameRect.y = 70;
	_gameNameRect.w = (surface->w / 8) * 5;
	_gameNameRect.h = surface->h;
	SDL_FreeSurface(surface);
	SDL_RenderCopy(_render, texture, nullptr, &_gameNameRect);
	SDL_DestroyTexture(texture);
}

void ar::Sdl::DisplayScore(ar::userInterface &user)
{
	int pos = 50;
	std::vector<std::string> desc{"Name : ", "Score : ", "Time : "};
	std::string tmpText;
	std::stringstream ss;

	for (int game = 0; game < 3; game++) {
		ss.str(std::string());
		if (game == 0)
			tmpText = desc[game] + user.username;
		else if (game == 1) {
			ss << user.score;
			tmpText = desc[game] + ss.str();
		} else {
			ss << user.time;
			tmpText = desc[game] + ss.str();
		}
		SDL_Surface *surface;
		SDL_Texture *texture;
		surface = TTF_RenderText_Solid(_littleFont, tmpText.c_str(),
			this->whiteColor);
		texture = SDL_CreateTextureFromSurface(_render, surface);
		_gameNameRect.x = _screenWidth / 14;
		_gameNameRect.y = (_screenHeight / 6) + (pos);
		_gameNameRect.w = surface->w;
		_gameNameRect.h = surface->h;
		SDL_FreeSurface(surface);
		SDL_RenderCopy(_render, texture, nullptr, &_gameNameRect);
		SDL_DestroyTexture(texture);
		pos += 50;
	}
}

void ar::Sdl::DiplayGames(const std::vector<ar::userInterface> &dataArray)
{
	const char *gameName;

	for (int unsigned i = 0; i < _menuChoices.size(); i++) {
		gameName = _menuChoices[i].c_str();
		SDL_Surface *surface;
		SDL_Texture *texture;
		if (_currentGame == i) {
			DisplayScore(const_cast<userInterface &>
			(dataArray[_currentGame]));
			surface = TTF_RenderText_Solid(_font, gameName,
				this->redColor);
		}
		else
			surface = TTF_RenderText_Solid(_font, gameName,
				this->whiteColor);
		texture = SDL_CreateTextureFromSurface(_render,
			surface);
		_gameNameRect.x = static_cast<int>((_screenWidth / 2) -
			((strlen(gameName) * 30) / 2));
		_gameNameRect.y = (_screenHeight / 6) + (i * 50);
		_gameNameRect.w = surface->w;
		_gameNameRect.h = surface->h;
		SDL_FreeSurface(surface);
		SDL_RenderCopy(_render, texture, nullptr, &_gameNameRect);
		SDL_DestroyTexture(texture);
	}

}

void ar::Sdl::DiplayLibs(const std::vector<ar::userInterface> &dataArray)
{
	const char *gameName;

	(void)dataArray;
	for (int unsigned i = 0; i < _menuLibs.size(); i++) {
		gameName = _menuLibs[i].c_str();
		SDL_Surface *surface;
		SDL_Texture *texture;
		surface = TTF_RenderText_Solid(_font, gameName,
			this->whiteColor);
		texture = SDL_CreateTextureFromSurface(_render,
			surface);
		_gameNameRect.x = static_cast<int>((_screenWidth / 2) -
			(strlen(gameName) * 30) / 2);
		_gameNameRect.y = (_screenHeight / 6) + (i * 50);
		_gameNameRect.w = surface->w;
		_gameNameRect.h = surface->h;
		SDL_FreeSurface(surface);
		SDL_RenderCopy(_render, texture, nullptr, &_gameNameRect);
		SDL_DestroyTexture(texture);
	}
}

int ar::Sdl::refreshMenu(const ar::Event &key,
	const std::vector<ar::userInterface> &dataArray)
{
	if (key == AR_UP && _currentGame > 0)
		_currentGame--;
	else if (key == AR_DOWN && _currentGame < _menuChoices.size() - 1)
		_currentGame++;
	if (key == AR_LEFT && !_menuLib) {
		_menuLib = true;
	} else if (key == AR_RIGHT && _menuLib) {
		_menuLib = false;
	}
	SDL_SetRenderDrawColor(_render, 0, 0, 0, 0);
	SDL_RenderClear(_render);
	SDL_RenderCopy(_render, _textureMenu, &_menuSize, &_menuSrc);
	if (!_menuLib) {
		if (_currentGame < dataArray.size()) {
			displayTooltip("Press Left Key to see available Libs");
			DiplayGames(dataArray);
		}
	} else {
		displayTooltip("Press Right Key to see available Games");
		DiplayLibs(dataArray);
	}
	SDL_RenderCopy(_render, _usernameText, nullptr, &_usernameRect);
	SDL_DestroyTexture(_usernameText);
	SDL_RenderPresent(_render);
	return static_cast<int>(_currentGame);
}

void ar::Sdl::DisplayIngameScore(const ar::userInterface &UI, int squareSize,
	ar::Map &map)
{
	SDL_Texture *texture;
	SDL_Rect dstrect {};
	SDL_Surface *surface;
	std::string data;
	std::stringstream ss;

	ss << UI.score;
	data = "Score ";
	data += ss.str();
	surface = TTF_RenderText_Solid(_font, data.c_str(), whiteColor);
	texture = SDL_CreateTextureFromSurface(_render, surface);
	dstrect.x = (squareSize * map.getWidth()) + 100;
	dstrect.y = 50;
	dstrect.w = surface->w;
	dstrect.h = surface->h;
	SDL_FreeSurface(surface);
	SDL_RenderCopy(_render, texture, NULL, &dstrect);
	SDL_DestroyTexture(texture);
}

void ar::Sdl::DisplayIngameTime(const ar::userInterface &UI, int squareSize,
	ar::Map &map)
{
	SDL_Texture *texture;
	SDL_Rect dstrect {};
	SDL_Surface *surface;
	std::string data;
	std::stringstream ss;

	ss.str(std::string());
	int seconds = UI.time;
	int minutes = seconds / 60;
	seconds = seconds % 60;
	ss << minutes << ":" << seconds;
	data = "Time ";
	data += ss.str();
	surface = TTF_RenderText_Solid(_font, data.c_str(), whiteColor);
	texture = SDL_CreateTextureFromSurface(_render, surface);
	dstrect.x = (squareSize * map.getWidth()) + 100;
	dstrect.y = 100;
	dstrect.w = surface->w;
	dstrect.h = surface->h;
	SDL_RenderCopy(_render, texture, nullptr, &dstrect);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);

}
void ar::Sdl::DisplayIngameName(const ar::userInterface &UI, int squareSize,
	ar::Map &map)
{
	SDL_Texture *texture;
	SDL_Rect dstrect {};
	SDL_Surface *surface;
	std::string data;
	std::stringstream ss;

	if (strlen(UI.username.c_str()) != 0) {
		surface = TTF_RenderText_Solid(_font, UI.username.c_str(),
			whiteColor);
		texture = SDL_CreateTextureFromSurface(_render, surface);
		dstrect.x = (squareSize * map.getWidth()) + 100;
		dstrect.y = 150;
		dstrect.w = surface->w;
		dstrect.h = surface->h;
		SDL_RenderCopy(_render, texture, nullptr, &dstrect);
		SDL_FreeSurface(surface);
		SDL_DestroyTexture(texture);
	}
}

void ar::Sdl::displayGame(__attribute__((unused))const ar::userInterface &UI,
	ar::Map &map)
{
	int squareSize;

	SDL_GetWindowSize(_window, &_screenWidth, &_screenHeight);
	if (_screenWidth >= _screenHeight) {
		squareSize = _screenHeight;
	} else {
		squareSize = _screenWidth;
	}
	if (map.getWidth() > map.getHeight()) {
		squareSize /= map.getWidth();
	} else {
		squareSize /= map.getHeight();
	}
	SDL_Rect src = {0, 0, squareSize, squareSize};
	SDL_RenderClear(_render);
	DisplayIngameScore(UI, squareSize, map);
	DisplayIngameTime(UI, squareSize, map);
	DisplayIngameName(UI, squareSize, map);
	for (int i = 0; i < map.getHeight(); i++) {
		for (int j = 0; j < map.getWidth(); j++) {
			src.x = j * squareSize / textSize;
			src.y = i * squareSize / textSize;
			SDL_RenderCopy(_render, _textures[2], nullptr, &src);
			SDL_RenderCopy(_render, _textures[map[i][j]], nullptr,
				&src);
		}
	}
	SDL_RenderPresent(_render);
}

extern "C" ar::IDisplay *createDisplay()
{
	return new ar::Sdl;
}

extern "C" void destroyDisplay(ar::IDisplay *ptr)
{
	delete ptr;
}
