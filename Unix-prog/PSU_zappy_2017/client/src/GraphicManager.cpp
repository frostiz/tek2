/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PSU_zappy_2017 file
*/

#include <SFML/Graphics.hpp>
#include "GraphicManager.hpp"

GraphicManager::GraphicManager()
{
	_squareSize = 0;
}

void GraphicManager::initialize(Core *core)
{
	this->_mapManager = core->getMapManager();
	this->_window = core->getWindow();
	this->_assetsManager = core->getAssetsManager();
	this->_gui = new GUI(100, core);
}

void GraphicManager::drawMap()
{
	this->drawElement(this->_mapManager->getTiles(), this->_assetsManager);
	this->drawElement(this->_mapManager->getEggs(), this->_assetsManager);
	for (const auto &tile : this->_mapManager->getTiles())
		this->drawElement(tile->getRessources(), this->_assetsManager);
	this->drawElement(this->_mapManager->getPlayers(), this->_assetsManager);
}

void GraphicManager::update()
{
	this->updateSquareSize();
	this->updateElementPosition(this->_mapManager->getTiles(), _squareSize, _squareSize);
	this->updateElementPosition(this->_mapManager->getEggs(), _squareSize, _squareSize);
	for (const auto &tile : this->_mapManager->getTiles())
		this->updateElementPosition(tile->getRessources(), _squareSize / 2, _squareSize);
	this->updateElementPosition(this->_mapManager->getPlayers(), _squareSize, _squareSize);

	this->_gui->updatePosition();
}

template<typename T>
void GraphicManager::drawElement(const std::vector<T> &elements, AssetsManager *assetsManager) {
	for (const auto &elem : elements) {
		sf::RectangleShape rectangle = this->createRectangle(
			sf::Vector2f(elem->getDisplayPosition()),
			elem->getSize(),
			elem->getTexture(assetsManager));
		elem->setRectangle(rectangle);
		elem->draw(this->_window);
	}
};

template<typename T>
void GraphicManager::updateElementPosition(const std::vector<T> &elements, const float &size, const float &oneSquareSize)
{
	for (const auto &elem : elements) {
		if (elem->getSub() >= 4)
			elem->setDisplay(false);
		if (elem->getDisplay()) {
			sf::Vector2i subSquare = elem->getSubSquare();

			elem->setSize(sf::Vector2f(size, size));
			elem->setDisplayPosition(
				sf::Vector2i(
					oneSquareSize * elem->getPosition().x + elem->getPosition().x + subSquare.x * size,
					oneSquareSize * elem->getPosition().y + elem->getPosition().y + subSquare.y * size
				)
			);
		}
	}
}

void GraphicManager::drawGUI()
{
	if (!this->_gui->getTile())
		return ;
	this->drawElement(_gui->getRessources(), this->_assetsManager);
	this->showPlayerInfo(_gui->getPlayer());
	for (sf::Text *text : _gui->getTexts())
		_window->draw(*text);
	for (sf::Text *text : _gui->getPlayerTexts())
		_window->draw(*text);
}

void GraphicManager::showRessourcesOnTile(Tile *tile)
{
	_gui->setTile(tile);
}

void GraphicManager::showPlayerInfo(Player *player)
{
	_gui->setPlayer(player);
}

sf::RectangleShape GraphicManager::createRectangle(const sf::Vector2f &pos, const sf::Vector2f &size, sf::Texture *texture)
{
	sf::RectangleShape rectangle(size);

	rectangle.setPosition(pos);
	if (!texture)
		rectangle.setFillColor(sf::Color::Transparent);
	rectangle.setTexture(texture);
	return rectangle;
}

float &GraphicManager::getSquareSize()
{
	return _squareSize;
}

void GraphicManager::updateSquareSize()
{
	auto size = this->_window->getSize();

	float tmp = size.x / this->_mapManager->getWidth();
	float tmp2 = (size.y - this->_gui->getHeight()) / this->_mapManager->getHeight();

	if (tmp < tmp2)
		this->_squareSize = tmp - 1;
	else
		this->_squareSize = tmp2 - 1;
}

GUI *GraphicManager::getGUI()
{
	return this->_gui;
}

template void GraphicManager::drawElement<Tile *> (const std::vector<Tile *> &, AssetsManager *);
template void GraphicManager::drawElement<Player *> (const std::vector<Player *> &, AssetsManager *);
template void GraphicManager::drawElement<Egg *> (const std::vector<Egg *> &, AssetsManager *);
template void GraphicManager::drawElement<Ressource *> (const std::vector<Ressource *> &, AssetsManager *);

template void GraphicManager::updateElementPosition<Tile *>(const std::vector<Tile *> &, const float &, const float &);
template void GraphicManager::updateElementPosition<Player *>(const std::vector<Player *> &, const float &, const float &);
template void GraphicManager::updateElementPosition<Egg *>(const std::vector<Egg *> &, const float &, const float &);
template void GraphicManager::updateElementPosition<Ressource *>(const std::vector<Ressource *> &, const float &, const float &);