/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PSU_zappy_2017 file
*/

#include "Player.hpp"

Player::Player(Player *player) : Player(player->getPlayerNumber(), player->getOrientation(), player->getLevel(), player->getTeam())
{
	_pos = player->_pos;
	_displayPos = player->_displayPos;
	_nbFood = player->_nbFood;
	_nbLinemate = player->_nbLinemate;
	_nbDeraumere = player->_nbDeraumere;
	_nbSibur = player->_nbSibur;
	_nbMendiane = player->_nbMendiane;
	_nbPhiras = player->_nbPhiras;
	_nbThystame = player->_nbThystame;
	_status = player->_status;
}

Player::Player(const int &playerNumber, const int &playerOrient, const int &playerLevel, const std::string &team)
	: Element()
{
	this->_playerNumber = playerNumber;
	this->_orientation = playerOrient;
	this->_level = playerLevel;
	this->_team = team;
	this->_pos = {-1, -1};
	this->_displayPos = {-1, -1};
	this->_nbFood = 0;
	this->_nbLinemate = 0;
	this->_nbDeraumere = 0;
	this->_nbSibur = 0;
	this->_nbMendiane = 0;
	this->_nbPhiras = 0;
	this->_nbThystame = 0;
	this->_status = PLAYER_STATUS_NORMAL;
}

int &Player::getOrientation()
{
	return this->_orientation;
}

int &Player::getPlayerNumber()
{
	return this->_playerNumber;
}

int &Player::getLevel()
{
	return this->_level;
}

void Player::setOrientation(const int &orientation)
{
	this->_orientation = orientation;
}

void Player::setLevel(const int &level)
{
	this->_level = level;
}

void Player::setNbFood(const int &nbFood)
{
	this->_nbFood = nbFood;
}

void Player::setNbLinemate(const int &nbLinemate)
{
	this->_nbLinemate = nbLinemate;
}

void Player::setNbDeraumere(const int &nbDeraumere)
{
	this->_nbDeraumere = nbDeraumere;
}

void Player::setNbSibur(const int &nbSibur)
{
	this->_nbSibur = nbSibur;
}

void Player::setNbMendiane(const int &nbMendiane)
{
	this->_nbMendiane = nbMendiane;
}

void Player::setNbPhiras(const int &nbPhiras)
{
	this->_nbPhiras = nbPhiras;
}

void Player::setNbThystame(const int &nbThystame)
{
	this->_nbThystame = nbThystame;
}

sf::Texture *Player::getTexture(AssetsManager *assetsManager)
{
	if (this->_status == PLAYER_STATUS_INCANTING)
		return assetsManager->getTexture(AssetsManager::ASSETS_TEXTURE_PLAYER_INCANTING);
	switch (this->_orientation) {
	case PLAYER_ORIENTATION_NORTH:
		return assetsManager->getTexture(AssetsManager::ASSETS_TEXTURE_PLAYER_NORTH);
	case PLAYER_ORIENTATION_EAST:
		return assetsManager->getTexture(AssetsManager::ASSETS_TEXTURE_PLAYER_EAST);
	case PLAYER_ORIENTATION_SOUTH:
		return assetsManager->getTexture(AssetsManager::ASSETS_TEXTURE_PLAYER_SOUTH);
	case PLAYER_ORIENTATION_WEST:
		return assetsManager->getTexture(AssetsManager::ASSETS_TEXTURE_PLAYER_WEST);
	default:
		return nullptr;
	}
}

void Player::setStatus(const int &status)
{
	this->_status = status;
}

std::string &Player::getTeam()
{
	return this->_team;
}

int &Player::getNbFood()
{
	return _nbFood;
}

int &Player::getNbLinemate()
{
	return _nbLinemate;
}

int &Player::getNbDeraumere()
{
	return _nbDeraumere;
}

int &Player::getNbSibur()
{
	return _nbSibur;
}

int &Player::getNbMendiane()
{
	return _nbMendiane;
}

int &Player::getNbPhiras()
{
	return _nbPhiras;
}

int &Player::getNbThystame()
{
	return _nbThystame;
}
