/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PSU_zappy_2017 file
*/

#include "EventManager.hpp"

EventManager::EventManager()
{
	this->_window = nullptr;
}

void EventManager::initialize(Core *core)
{
	this->_core = core;
	this->_window = this->_core->getWindow();
	this->_mouseManager = this->_core->getMouseManager();
	this->_graphicManager = this->_core->getGraphicManager();
	this->_mapManager = this->_core->getMapManager();
}

bool EventManager::onEvent(sf::Event &event)
{
	return _window->pollEvent(event);
}

void EventManager::startEvent(const sf::Event &event)
{
	if (event.type == sf::Event::Closed)
		_window->close();
	else if (event.type == sf::Event::Resized) {
		sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
		this->_window->setView(sf::View(visibleArea));
		this->_graphicManager->update();
	} else if (event.type == sf::Event::MouseButtonPressed) {
		for (const auto &player : _mapManager->getPlayers()) {
			if (_mouseManager->intersects(player->getRectangle())) {
				std::cout << "Clicked on player at position : x=" << player->getPosition().x << " y=" << player->getPosition().y << std::endl;
				_graphicManager->showPlayerInfo(player);
				return ;
			}
		}
		for (const auto &tile : _mapManager->getTiles()) {
			if (_mouseManager->intersects(tile->getRectangle())) {
				std::cout << "Clicked on tile at position : x=" << tile->getPosition().x << " y=" << tile->getPosition().y << std::endl;
				_graphicManager->showRessourcesOnTile(tile);
				return ;
			}
		}
	}
}
