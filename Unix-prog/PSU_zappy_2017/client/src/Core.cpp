/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PSU_zappy_2017 file
*/

#include <SFML/Graphics/RectangleShape.hpp>
#include "Core.hpp"

Core::Core(const int &argc, const char **argv) : _argc(argc), _argv(argv)
{
	this->_screenWidth = 1400;
	this->_screenHeight = 700;
	this->_window = new sf::RenderWindow();
	this->_eventManager = new EventManager();
	this->_mapManager = new MapManager();
	this->_packetManager = new PacketManager(this);
	this->_graphicManager = new GraphicManager();
	this->_assetsManager = new AssetsManager();
	this->_teamManager = new TeamManager();
	this->_mouseManager = new MouseManager(this->_window, 1, 1);
}

Core::~Core()
{
}

void Core::initialize()
{
	this->initPacketManager();
	this->initEventManager();

	this->loadLoop();

	this->initSFML();
	this->initAssetsManager();
	this->initGraphicManager();

	this->mainLoop();
}

void Core::initPacketManager()
{
	std::string port("8080");
	for (int i = 0; i < _argc; ++i) {
		if (_argv[i] && _argv[i + 1] && std::string(_argv[i]) == "-p") {
			port = _argv[i + 1];
		}
	}
	_packetManager->initialize(port);
}

void Core::initEventManager()
{
	this->_eventManager->initialize(this);
}

void Core::initSFML()
{
	this->_window->create(sf::VideoMode(_screenWidth, _screenHeight), "Zappy - Client");
	this->_window->setFramerateLimit(60);
}

void Core::initGraphicManager()
{
	this->_graphicManager->initialize(this);
	this->_graphicManager->update();
}

void Core::initAssetsManager()
{
	this->_assetsManager->initialize();
}

void Core::loadLoop()
{
	while (!this->isReadyToDisplay()) {
		this->_packetManager->receiveData();
	}
}

bool Core::isReadyToDisplay()
{
	return _mapManager->getWidth() != 0 && _packetManager->getTilesInitialized() == _mapManager->getWidth() * _mapManager->getHeight() &&
		_packetManager->getTilesInitialized() == (int)_mapManager->getTiles().size();
}

void Core::mainLoop()
{
	sf::Event event;

	while (this->_window->isOpen()) {
		if (this->_eventManager->onEvent(event))
			this->_eventManager->startEvent(event);
		this->_packetManager->receiveData();
		this->update();
		this->display();
	}
}

void Core::update()
{
	//for (Player *player : _mapManager->getPlayers()) {
		//this->_packetManager->sendData("ppo " + std::to_string(player->getPlayerNumber()) + "\n");
	//}
}

void Core::display()
{
	this->_window->clear();
	this->_graphicManager->drawMap();
	this->_graphicManager->drawGUI();
	this->_window->display();
}

sf::RenderWindow *Core::getWindow() const
{
	return this->_window;
}

MapManager *Core::getMapManager() const
{
	return this->_mapManager;
}

TeamManager *Core::getTeamManager() const
{
	return this->_teamManager;
}

AssetsManager *Core::getAssetsManager() const
{
	return this->_assetsManager;
}

MouseManager *Core::getMouseManager() const
{
	return this->_mouseManager;
}

GraphicManager *Core::getGraphicManager() const
{
	return this->_graphicManager;
}

void Core::setTimeUnit(const int &timeUnit)
{
	_timeUnit = timeUnit;
}
