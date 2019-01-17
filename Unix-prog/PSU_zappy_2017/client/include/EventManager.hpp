/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PSU_zappy_2017 file
*/

#ifndef PSU_ZAPPY_2017_EVENTMANAGER_HPP
#define PSU_ZAPPY_2017_EVENTMANAGER_HPP

#include <SFML/Window.hpp>
#include "Core.hpp"

class Core;
class MouseManager;
class GraphicManager;
class MapManager;

class EventManager {
	public:
	EventManager();
	~EventManager() = default;

	void	initialize(Core *);
	bool	onEvent(sf::Event &);
	void	startEvent(const sf::Event &);

	private:
	Core			*_core;
	MouseManager		*_mouseManager;
	GraphicManager		*_graphicManager;
	MapManager		*_mapManager;
	sf::RenderWindow	*_window;
};

#endif //PSU_ZAPPY_2017_EVENTMANAGER_HPP
