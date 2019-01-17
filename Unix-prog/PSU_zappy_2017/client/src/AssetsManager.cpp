/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PSU_zappy_2017 file
*/

#include <iostream>
#include "AssetsManager.hpp"

AssetsManager::AssetsManager()
{
}

void AssetsManager::initialize()
{
	_textures[ASSETS_TEXTURE_NONE] = nullptr;
	_textures[ASSETS_TEXTURE_FLOOR] = this->loadTexture("./assets/floor.png");
	_textures[ASSETS_TEXTURE_FOOD] = this->loadTexture("./assets/food.png");
	_textures[ASSETS_TEXTURE_LINEMATE] = this->loadTexture("./assets/linemate.png");
	_textures[ASSETS_TEXTURE_DERAUMERE] = this->loadTexture("./assets/deraumere.png");
	_textures[ASSETS_TEXTURE_SIBUR] = this->loadTexture("./assets/sibur.png");
	_textures[ASSETS_TEXTURE_MENDIANE] = this->loadTexture("./assets/mendiane.png");
	_textures[ASSETS_TEXTURE_PHIRAS] = this->loadTexture("./assets/phiras.png");
	_textures[ASSETS_TEXTURE_THYSTAME] = this->loadTexture("./assets/thystame.png");
	_textures[ASSETS_TEXTURE_EGG_HATCHING] = this->loadTexture("./assets/egg_hatching.png");
	_textures[ASSETS_TEXTURE_EGG_LAYED] = this->loadTexture("./assets/egg_layed.png");
	_textures[ASSETS_TEXTURE_PLAYER_NORTH] = this->loadTexture("./assets/player_north.png");
	_textures[ASSETS_TEXTURE_PLAYER_EAST] = this->loadTexture("./assets/player_east.png");
	_textures[ASSETS_TEXTURE_PLAYER_SOUTH] = this->loadTexture("./assets/player_south.png");
	_textures[ASSETS_TEXTURE_PLAYER_WEST] = this->loadTexture("./assets/player_west.png");
	_textures[ASSETS_TEXTURE_PLAYER_INCANTING] = this->loadTexture("./assets/player_incanting.png");


	_fonts[ASSETS_FONT_GUI_COUNT] = this->loadFont("./assets/font/arial.ttf");
}

sf::Texture *AssetsManager::loadTexture(const std::string &path)
{
	sf::Texture *texture = new sf::Texture();
	std::string alternate = path;

	if (!texture->loadFromFile(path)) {
		if (!texture->loadFromFile(alternate.erase(0,1).insert(0, "./client")))
		{
			std::cout << "An asset hasn't been found" << std::endl;
			exit(84);
		}
	}
	std::cout << "Loaded texture:[" << path << "]" << std::endl;
	return texture;
}

sf::Texture *AssetsManager::getTexture(eAssetsTexture id)
{
	return _textures[id];
}

sf::Font *AssetsManager::loadFont(const std::string &path)
{
	sf::Font *font = new sf::Font();
	std::string alternate = path;

	if (!font->loadFromFile(path)) {
		if (!font->loadFromFile(alternate.erase(0,1).insert(0, "./client")))
		{
			std::cout << "An asset hasn't been found" << std::endl;
			exit(84);
		}
	}
	std::cout << "Loaded texture:[" << path << "]" << std::endl;
	return font;
}

sf::Font *AssetsManager::getFont(eAssetsFont id)
{
	return _fonts[id];
}

