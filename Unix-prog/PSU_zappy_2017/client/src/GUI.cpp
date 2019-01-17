/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PSU_zappy_2017 file
*/

#include "GUI.hpp"

GUI::GUI(const int &height, Core *core)
{
	this->_tile = nullptr;
	this->_height = height;
	this->_assetsManager = core->getAssetsManager();
	this->_window = core->getWindow();
	this->_graphicManager = core->getGraphicManager();
	this->_mapManager = core->getMapManager();
	this->_index = {-1, -1};
	this->_ressourceIndexes = {
		{"food", 0},
		{"linemate", 1},
		{"deraumere", 2},
		{"sibur", 3},
		{"mendiane", 4},
		{"phiras", 5},
		{"thystame", 6},
	};
	this->_player = nullptr;
	this->_displayIndex = {0, 0};
}

void GUI::updatePosition()
{
	int inc = 0;
	for (Ressource *ressource : _ressources) {
		ressource->setDisplayPosition(sf::Vector2i(inc * _height, _window->getSize().y - _height));
		++inc;
	}
	inc = 0;
	for (sf::Text *text : _texts) {
		text->setPosition(sf::Vector2f(inc * _height, _window->getSize().y - _height));
		++inc;
	}
}

void GUI::setTile(Tile *tile)
{
	this->_tile = tile;
	if (!tile)
		return ;
	_ressources.clear();
	_texts.clear();
	int	inc = 0;
	for (Ressource *ressource : tile->getRessources()) {
		Ressource *cpy = new Ressource(ressource);
		if (cpy->getQuantity() > 0) {
			sf::Text 	*text = new sf::Text();
			sf::Font 	*font = _assetsManager->getFont(AssetsManager::ASSETS_FONT_GUI_COUNT);

			cpy->setDisplayPosition(sf::Vector2i(inc * _height, _window->getSize().y - _height));
			cpy->setSize(sf::Vector2f(_height, _height));

			text->setFont(*font);
			text->setString(std::to_string(ressource->getQuantity()));
			text->setPosition(sf::Vector2f(inc * _height, _window->getSize().y - _height));

			_ressources.push_back(cpy);
			_texts.push_back(text);
			++inc;
		}
	}
}

sf::Text *GUI::createText(const std::string &string)
{
	sf::Text	*text = new sf::Text();
	sf::Font 	*font = _assetsManager->getFont(AssetsManager::ASSETS_FONT_GUI_COUNT);

	text->setFont(*font);
	text->setString(string);
	text->setPosition(sf::Vector2f(_displayIndex.x, _displayIndex.y));
	_displayIndex = sf::Vector2f(_displayIndex.x, _displayIndex.y + _graphicManager->getSquareSize());
	return text;
}

void GUI::setPlayer(Player *player)
{
	if (!player)
		return ;
	_player = player;

	_playerTexts.clear();
	_displayIndex = {static_cast<float>(_mapManager->getWidth() * _graphicManager->getSquareSize() + _graphicManager->getSquareSize()), 0};

	//Show Player number, level, position, inventory
	sf::Text *number = this->createText("Player : " + std::to_string(player->getPlayerNumber()));
	sf::Text *level = this->createText("Level : " + std::to_string(player->getLevel()));
	sf::Text *pos = this->createText("Position : " + std::to_string(player->getPosition().x) + ";" + std::to_string(player->getPosition().y));
	sf::Text *food = this->createText("Food : " + std::to_string(player->getNbFood()));
	sf::Text *linemate = this->createText("Linemate : " + std::to_string(player->getNbLinemate()));
	sf::Text *deraumere = this->createText("Deraumere : " + std::to_string(player->getNbDeraumere()));
	sf::Text *sibur = this->createText("Sibur : " + std::to_string(player->getNbSibur()));
	sf::Text *mendiane = this->createText("Mendiane : " + std::to_string(player->getNbMendiane()));
	sf::Text *phiras = this->createText("Phiras : " + std::to_string(player->getNbPhiras()));
	sf::Text *thystame = this->createText("Thystame : " + std::to_string(player->getNbThystame()));

	_playerTexts.push_back(number);
	_playerTexts.push_back(level);
	_playerTexts.push_back(pos);
	_playerTexts.push_back(food);
	_playerTexts.push_back(linemate);
	_playerTexts.push_back(deraumere);
	_playerTexts.push_back(sibur);
	_playerTexts.push_back(mendiane);
	_playerTexts.push_back(phiras);
	_playerTexts.push_back(thystame);
}

std::vector<sf::Text *> &GUI::getPlayerTexts()
{
	return this->_playerTexts;
}

Player *GUI::getPlayer() const
{
	return this->_player;
}

Tile *GUI::getTile() const
{
	return this->_tile;
}

int &GUI::getHeight()
{
	return this->_height;
}

sf::Vector2i	&GUI::getIndex()
{
	return this->_index;
}

std::vector<Ressource *> &GUI::getRessources()
{
	return this->_ressources;
}

std::vector<sf::Text *> &GUI::getTexts()
{
	return this->_texts;
}
