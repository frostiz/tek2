/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PSU_zappy_2017 file
*/

#ifndef PSU_ZAPPY_2017_CORE_HPP
#define PSU_ZAPPY_2017_CORE_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include "EventManager.hpp"
#include "MapManager.hpp"
#include "PacketManager.hpp"
#include "TeamManager.hpp"
#include "GraphicManager.hpp"
#include "AssetsManager.hpp"
#include "MouseManager.hpp"

class EventManager;
class PacketManager;
class GraphicManager;
class AssetsManager;
class MouseManager;
class GraphicManager;

class Core
{
	public:
	Core(const int &, const char **);
	~Core();

	void	initialize();
	void		initSFML();
	void		initEventManager();
	void		initPacketManager();
	void		initGraphicManager();
	void		initAssetsManager();

	void	loadLoop();
	void	mainLoop();
	void	update();
	void	display();

	sf::RenderWindow	*getWindow() const;
	MapManager		*getMapManager() const;
	TeamManager		*getTeamManager() const;
	AssetsManager		*getAssetsManager() const;
	MouseManager		*getMouseManager() const;
	GraphicManager		*getGraphicManager() const;

	void			setTimeUnit(const int &);

	bool			isReadyToDisplay();

	private:

	const int 	_argc;
	const char	**_argv;

	int		_screenWidth;
	int		_screenHeight;

	sf::RenderWindow 	*_window;

	EventManager	*_eventManager;
	MapManager	*_mapManager;
	PacketManager	*_packetManager;
	TeamManager	*_teamManager;
	AssetsManager	*_assetsManager;
	GraphicManager	*_graphicManager;
	MouseManager	*_mouseManager;

	int		_timeUnit;
};

#endif //PSU_ZAPPY_2017_CORE_HPP
