/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PSU_zappy_2017 file
*/

#include <cstdlib>
#include <SFML/System.hpp>
#include "Tile.hpp"

Tile::Tile(const sf::Vector2i &pos) : Element()
{
	_pos = pos;
}

std::vector<Ressource *> &Tile::getRessources()
{
	return this->_ressources;
}

sf::Texture *Tile::getTexture(AssetsManager *assetsManager)
{
	return assetsManager->getTexture(AssetsManager::ASSETS_TEXTURE_FLOOR);
}
