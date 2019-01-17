/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PSU_zappy_2017 file
*/

#include "Ressource.hpp"

Ressource::Ressource(Ressource *ressource) : Ressource(ressource->getIndex(), ressource->getSub(), ressource->getQuantity())
{

}

Ressource::Ressource(const size_t &index, const int &sub, const int &quantity) : Element()
{
	this->_index = index;
	this->_types = {"food", "linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"};
	if (_index >= _types.size())
		exit(84);
	this->_type = _types[index];
	this->_textures = {
		AssetsManager::ASSETS_TEXTURE_FOOD,
		AssetsManager::ASSETS_TEXTURE_LINEMATE,
		AssetsManager::ASSETS_TEXTURE_DERAUMERE,
		AssetsManager::ASSETS_TEXTURE_SIBUR,
		AssetsManager::ASSETS_TEXTURE_MENDIANE,
		AssetsManager::ASSETS_TEXTURE_PHIRAS,
		AssetsManager::ASSETS_TEXTURE_THYSTAME
	};
	this->_quantity = quantity;
	this->_sub = sub;
	this->_isSubSquare = true;
}

int &Ressource::getQuantity()
{
	return this->_quantity;
}

void Ressource::setQuantity(const int &quantity)
{
	this->_quantity = quantity;
}

std::string &Ressource::getType()
{
	return this->_type;
}

sf::Texture *Ressource::getTexture(AssetsManager *assetsManager)
{
	return assetsManager->getTexture(static_cast<AssetsManager::eAssetsTexture >(_textures[_index]));
}

size_t &Ressource::getIndex()
{
	return this->_index;
}

void Ressource::setIndex(const size_t &index)
{
	_index = index;
	_type = _types[index];
}
