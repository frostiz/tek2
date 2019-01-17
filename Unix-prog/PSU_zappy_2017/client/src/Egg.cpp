/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PSU_zappy_2017 file
*/

#include "Egg.hpp"

Egg::Egg(const int &playerNumber, const int &eggNumber) : Element()
{
	this->_playerNumber = playerNumber;
	this->_eggNumber = eggNumber;
	this->_status = EGG_LAYED;
}

sf::Texture *Egg::getTexture(AssetsManager *assetsManager)
{
	switch (this->_status) {
	case (EGG_HATCHING) : {
		return assetsManager->getTexture(AssetsManager::ASSETS_TEXTURE_EGG_HATCHING);
	}
	case (EGG_LAYED) : {
		return assetsManager->getTexture(AssetsManager::ASSETS_TEXTURE_EGG_LAYED);
	}
	default:
		return nullptr;
	}
}

int &Egg::getPlayerNumber()
{
	return this->_playerNumber;
}

int &Egg::getEggNumber()
{
	return this->_eggNumber;
}

void Egg::setStatus(Egg::eStatus status)
{
	this->_status = status;
}
