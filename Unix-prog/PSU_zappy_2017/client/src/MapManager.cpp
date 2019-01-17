/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PSU_zappy_2017 file
*/

#include <iostream>
#include "MapManager.hpp"

MapManager::MapManager()
{
	_width = 0;
	_height = 0;
	_guiHeight = 100;
}

void MapManager::initialize(const int &width, const int &height, sf::RenderWindow *window)
{
	_width = width;
	_height = height;
	_window = window;

	_tiles.clear();
	_players.clear();
	_eggs.clear();
	for (int i = 0; i < _height; ++i) {
		for (int j = 0; j < _width; ++j) {
			Tile *tile = new Tile(sf::Vector2i(j, i));
			_tiles.push_back(tile);
		}
	}
}

std::vector<Tile *> &MapManager::getTiles()
{
	return this->_tiles;
}

int &MapManager::getWidth()
{
	return this->_width;
}

int &MapManager::getHeight()
{
	return this->_height;
}

Tile *MapManager::getTileAtPos(const int &x, const int &y)
{
	if (static_cast<size_t>(y * _width + x) < _tiles.size())
		return this->_tiles[y * _width + x];
	else
		return nullptr;
}

std::vector<Player *> &MapManager::getPlayers()
{
	return this->_players;
}

std::vector<Egg *> &MapManager::getEggs()
{
	return this->_eggs;
}