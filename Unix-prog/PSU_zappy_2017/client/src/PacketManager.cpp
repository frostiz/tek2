/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PSU_zappy_2017 file
*/

#include <unistd.h>
#include <sstream>
#include <netinet/in.h>
#include <netdb.h>
#include "PacketManager.hpp"

PacketManager::PacketManager(Core *core)
	: _packetFunc(
	{
		{"WELCOME", [this](void) { return this->rplWelcome(); }},
		{"msz", [this](void) { return this->rplMsz(); }},
		{"bct", [this](void) { return this->rplBct(); }},
		{"tna", [this](void) { return this->rplTna(); }},
		{"pnw", [this](void) { return this->rplPnw(); }},
		{"ppo", [this](void) { return this->rplPpo(); }},
		{"plv", [this](void) { return this->rplPlv(); }},
		{"pin", [this](void) { return this->rplPin(); }},
		{"pex", [this](void) { return this->rplPex(); }},
		{"pbc", [this](void) { return this->rplPbc(); }},
		{"pic", [this](void) { return this->rplPic(); }},
		{"pie", [this](void) { return this->rplPie(); }},
		{"pfk", [this](void) { return this->rplPfk(); }},
		{"pdr", [this](void) { return this->rplPdr(); }},
		{"pgt", [this](void) { return this->rplPgt(); }},
		{"pdi", [this](void) { return this->rplPdi(); }},
		{"enw", [this](void) { return this->rplEnw(); }},
		{"eht", [this](void) { return this->rplEht(); }},
		{"ebo", [this](void) { return this->rplEbo(); }},
		{"edi", [this](void) { return this->rplEdi(); }},
		{"sgt", [this](void) { return this->rplSgt(); }},
		{"sst", [this](void) { return this->rplSst(); }},
		{"seg", [this](void) { return this->rplSeg(); }},
		{"smg", [this](void) { return this->rplSmg(); }},
		{"suc", [this](void) { return this->rplSuc(); }},
		{"sbp", [this](void) { return this->rplSbp(); }}
	}
)
{
	_core = core;
	_circularBuffer = new CircularBuffer(2048);
	_tilesInitialized = 0;
}

void PacketManager::initialize(const std::string &port)
{
	_mapManager = _core->getMapManager();
	_teamManager = _core->getTeamManager();
	_graphicManager = _core->getGraphicManager();
	std::cout << "Trying connection on port [" << port << "]" << std::endl;

	struct sockaddr_in sockaddr;
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(atoi(port.c_str()));
	sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	struct protoent *proto = getprotobyname("TCP");

	_socketFd = socket(AF_INET, SOCK_STREAM, proto->p_proto);
	if (_socketFd == -1)
		exit(84);

	if (connect(_socketFd, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) == -1) {
		std::cerr << "Failed to connect to server 127.0.0.1 on port [" << port << "]" << std::endl;
		exit(84);
	}
}

void PacketManager::sendData(const std::string &data)
{
	if (FD_ISSET(_socketFd, &_write)) {
		write(this->_socketFd, data.c_str(), data.size());
		std::cout << "Sending [" << data << "]" << std::endl;
	}
}

void PacketManager::receiveData()
{
	_command.clear();
	_args.clear();
	FD_ZERO(&_read);
	FD_ZERO(&_write);
	FD_SET(_socketFd, &_read);
	FD_SET(_socketFd, &_write);
	struct timeval tv;

	tv.tv_sec = 0;
	tv.tv_usec = 50000;
	if (select(_socketFd + 1, &_read, &_write, nullptr, &tv) == -1)
		exit(84);
	if (FD_ISSET(_socketFd, &_read))
		this->onDataReceived();
}

void PacketManager::onDataReceived()
{
	std::string command = _circularBuffer->getNextLine(_socketFd);

	this->parseCommand(command);
}

void PacketManager::parseCommand(const std::string &command)
{
	std::istringstream stream(command.c_str());
	std::string token;
	int i = 0;

	while (getline(stream, token, ' ')) {
		if (i == 0)
			_command = token;
		else
			_args.push_back(token);
		++i;
	}
	//FOR DEBUG
	/*std::cout << "Command recu : [" << _command << "]" << std::endl;
	std::cout << "Argument : [";
	for (const auto &elem : _args)
		std::cout << elem << " ";
	std::cout << "]" << std::endl;*/

	this->execCommand();
}

void PacketManager::execCommand()
{
	try {
		//std::cout << "Executing [" << _command << "]" << std::endl;
		this->_packetFunc[_command]();
	} catch (const std::exception &e) {
		std::cout << "Error while executing command" << _command << std::endl;
		for (const auto &arg : _args) {
			std::cout << arg << std::endl;
		}
	}
}

int &PacketManager::getTilesInitialized()
{
	return _tilesInitialized;
}

bool PacketManager::rplWelcome()
{
	std::cout << "Reply welcome.." << std::endl;
	write(_socketFd, "GRAPHIC\n", 8);
	return true;
}

bool PacketManager::rplMsz()
{
	std::cout << "Reply msz.." << std::endl;
	if (_args.size() != 2)
		exit(84);
	int width = atoi(_args[0].c_str());
	int height = atoi(_args[1].c_str());

	_mapManager->initialize(width, height, _core->getWindow());
	return true;
}

bool PacketManager::rplSgt()
{
	std::cout << "Reply sgt.." << std::endl;
	_core->setTimeUnit(atoi(_args[0].c_str()));
	return true;
}

bool PacketManager::rplBct()
{
	std::cout << "Reply bct.." << std::endl;
	if (_args.size() != 9)
		exit(84);
	int x = atoi(_args[0].c_str());
	int y = atoi(_args[1].c_str());
	Tile *tile = _mapManager->getTileAtPos(x, y);
	std::vector<std::string> ressources = std::vector<std::string>(_args.begin() + 2, _args.end());

	tile->getRessources().clear();
	int i = 0;
	int count = 0;
	for (const auto &quantity : ressources) {
		if (atoi(quantity.c_str()) > 0) {
			Ressource *ressource = new Ressource(i, count, atoi(quantity.c_str()));

			ressource->setPosition(sf::Vector2i(x, y));
			tile->getRessources().push_back(ressource);
			count++;
		}
		i++;
	}
	_graphicManager->updateElementPosition(tile->getRessources(), _graphicManager->getSquareSize() / 2, _graphicManager->getSquareSize());
	++_tilesInitialized;
	// to update
	//if (_graphicManager->getGuiTileDisplayedPos() == tile->getPosition())
	//	_graphicManager->showRessourcesOnTile(tile);
	return true;
}

bool PacketManager::rplTna()
{
	std::cout << "Reply tna.." << std::endl;
	if (_args.size() != 1)
		exit(84);
	_teamManager->addTeam(_args[0]);
	return true;
}

bool PacketManager::rplPnw()
{
	std::cout << "Reply Pnw.." << std::endl;
	if (_args.size() != 6)
		exit(84);
	int playerNumber = atoi(_args[0].c_str());
	int playerX = atoi(_args[1].c_str());
	int playerY = atoi(_args[2].c_str());
	int playerOrient = atoi(_args[3].c_str());
	int playerLevel = atoi(_args[4].c_str());

	Player *player = new Player(playerNumber, playerOrient, playerLevel, _args[5]);
	player->setPosition(sf::Vector2i(playerX, playerY));
	player->setDisplayPosition(sf::Vector2i(playerX * _graphicManager->getSquareSize() + playerX, playerY * _graphicManager->getSquareSize() + playerY));
	player->setSize(sf::Vector2f(_graphicManager->getSquareSize(), _graphicManager->getSquareSize()));
	_mapManager->getPlayers().push_back(player);
	return true;
}

bool PacketManager::rplPpo()
{
	std::cout << "Reply ppo.." << std::endl;
	if (_args.size() != 4)
		exit(84);
	int playerNumber = atoi(_args[0].c_str());
	int playerX = atoi(_args[1].c_str());
	int playerY = atoi(_args[2].c_str());
	int playerOrient = atoi(_args[3].c_str());

	for (const auto &player : _mapManager->getPlayers()) {
		if (player->getPlayerNumber() == playerNumber) {
			player->setPosition(sf::Vector2i(playerX, playerY));
			player->setDisplayPosition(sf::Vector2i(playerX * _graphicManager->getSquareSize() + playerX, playerY * _graphicManager->getSquareSize() + playerY));
			player->setOrientation(playerOrient);
			return true;
		}
	}
	return true;
}

bool PacketManager::rplPlv()
{
	std::cout << "Reply plv.." << std::endl;
	if (_args.size() != 2)
		exit(84);
	int playerNumber = atoi(_args[0].c_str());
	int playerLevel = atoi(_args[1].c_str());
	for (const auto &player : _mapManager->getPlayers()) {
		if (player->getPlayerNumber() == playerNumber) {
			player->setLevel(playerLevel);
			return true;
		}
	}
	return true;
}


bool PacketManager::rplPin()
{
	std::cout << "Reply pin.." << std::endl;
	if (_args.size() != 10)
		exit(84);
	int playerNumber = atoi(_args[0].c_str());
	//int playerX = atoi(_args[1].c_str());
	//int playerY = atoi(_args[2].c_str());
	int playerFood = atoi(_args[3].c_str());
	int playerLinemate = atoi(_args[4].c_str());
	int playerDeraumere = atoi(_args[5].c_str());
	int playerSibur = atoi(_args[6].c_str());
	int playerMendiane = atoi(_args[7].c_str());
	int playerPhiras = atoi(_args[8].c_str());
	int playerThystame = atoi(_args[9].c_str());

	for (const auto &player : _mapManager->getPlayers()) {
		if (player->getPlayerNumber() == playerNumber) {
			player->setNbFood(playerFood);
			player->setNbLinemate(playerLinemate);
			player->setNbDeraumere(playerDeraumere);
			player->setNbSibur(playerSibur);
			player->setNbMendiane(playerMendiane);
			player->setNbPhiras(playerPhiras);
			player->setNbThystame(playerThystame);
			return true;
		}
	}
	return true;
}

bool PacketManager::rplPex()
{
	std::cout << "Reply pex.." << std::endl;
	if (_args.size() != 1)
		exit(84);
	int playerNumber = atoi(_args[0].c_str());
	std::vector<Player *> &players = _mapManager->getPlayers();
	for (size_t i = 0; i < players.size(); ++i) {
		if (players[i]->getPlayerNumber() == playerNumber) {
			players.erase(players.begin() + i);
			return true;
		}
	}
	return true;
}

bool PacketManager::rplPbc()
{
	std::cout << "Reply pbc.." << std::endl;
	return true;
}

bool PacketManager::rplPic()
{
	std::cout << "Reply pic.." << std::endl;
	int playerNumber = atoi(_args[3].c_str());

	for (const auto &player : _mapManager->getPlayers()) {
		if (player->getPlayerNumber() == playerNumber) {
			player->setStatus(Player::PLAYER_STATUS_INCANTING);
		}
	}
	return true;
}

bool PacketManager::rplPie()
{
	std::cout << "Reply pie.." << std::endl;
	int x = atoi(_args[0].c_str());
	int y = atoi(_args[1].c_str());

	for (const auto &player : _mapManager->getPlayers()) {
		if (player->getPosition() == sf::Vector2i(x, y)) {
			player->setStatus(Player::PLAYER_STATUS_NORMAL);
		}
	}
	return true;
}

bool PacketManager::rplPfk()
{
	std::cout << "Reply pfk.." << std::endl;
	if (_args.size() != 1)
		exit(84);

	//_teamManager->layDownAnEgg(player_number);
	return true;
}

bool PacketManager::rplPdr()
{
	std::cout << "Reply pdr.." << std::endl;
	if (_args.size() != 2)
		exit(84);
	int playerNumber = atoi(_args[0].c_str());
	//int ressourceNumber = atoi(_args[1].c_str());

	std::vector<Player *> &players = _mapManager->getPlayers();
	for (size_t i = 0; i < players.size(); ++i) {
		if (players[i]->getPlayerNumber() == playerNumber) {
			this->sendData("bct " + std::to_string(players[i]->getPosition().x) + " " + std::to_string(players[i]->getPosition().y) + "\n");
			this->sendData("pin " + std::to_string(players[i]->getPlayerNumber()));
			return true;
		}
	}
	return true;
}

bool PacketManager::rplPgt()
{
	std::cout << "Reply pgt.." << std::endl;
	if (_args.size() != 2)
		exit(84);
	int playerNumber = atoi(_args[0].c_str());
	//int ressourceNumber = atoi(_args[1].c_str());

	std::vector<Player *> &players = _mapManager->getPlayers();
	for (size_t i = 0; i < players.size(); ++i) {
		if (players[i]->getPlayerNumber() == playerNumber) {
			this->sendData("bct " + std::to_string(players[i]->getPosition().x) + " " + std::to_string(players[i]->getPosition().y) + "\n");
			this->sendData("pin " + std::to_string(players[i]->getPlayerNumber()));
			return true;
		}
	}
	return true;
}

bool PacketManager::rplPdi()
{
	std::cout << "Reply pdi.." << std::endl;
	if (_args.size() != 1)
		exit(84);
	int playerNumber = atoi(_args[0].c_str());
	std::vector<Player *> &players = _mapManager->getPlayers();
	for (size_t i = 0; i < players.size(); ++i) {
		if (players[i]->getPlayerNumber() == playerNumber) {
			players.erase(players.begin() + i);
			return true;
		}
	}
	return true;
}

bool PacketManager::rplEnw()
{
	std::cout << "Reply enw.." << std::endl;
	if (_args.size() != 4)
		exit(84);
	int eggNumber = atoi(_args[0].c_str());
	int playerNumber = atoi(_args[1].c_str());
	int playerX = atoi(_args[2].c_str());
	int playerY = atoi(_args[3].c_str());

	Egg *egg = new Egg(playerNumber, eggNumber);

	egg->setPosition(sf::Vector2i(playerX, playerY));
	egg->setSize(sf::Vector2f(_graphicManager->getSquareSize(), _graphicManager->getSquareSize()));
	egg->setDisplayPosition(sf::Vector2i(playerX * _graphicManager->getSquareSize() + playerX, playerY * _graphicManager->getSquareSize() + playerY));
	_mapManager->getEggs().push_back(egg);
	return true;
}

bool PacketManager::rplEht()
{
	std::cout << "Reply eht.." << std::endl;
	if (_args.size() != 1)
		exit(84);
	int eggNumber = atoi(_args[0].c_str());
	for (const auto &egg : _mapManager->getEggs()) {
		if (egg->getEggNumber() == eggNumber) {
			egg->setStatus(Egg::EGG_HATCHING);
			return true;
		}
	}
	return true;
}

bool PacketManager::rplEbo()
{
	std::cout << "Reply ebo.." << std::endl;
	if (_args.size() != 1)
		exit(84);
	int eggNumber = atoi(_args[0].c_str());
	std::vector<Egg *> &eggs = _mapManager->getEggs();
	for (size_t i = 0; i < eggs.size(); ++i) {
		if (eggs[i]->getEggNumber() == eggNumber) {
			eggs.erase(eggs.begin() + i);
			return true;
		}
	}
	return true;
}

bool PacketManager::rplEdi()
{
	std::cout << "Reply edi.." << std::endl;
	if (_args.size() != 1)
		exit(84);
	int eggNumber = atoi(_args[0].c_str());
	auto &eggs = _mapManager->getEggs();
	for (size_t i = 0; i < eggs.size(); ++i) {
		if (eggs[i]->getEggNumber() == eggNumber) {
			eggs.erase(eggs.begin() + i);
			return true;
		}
	}
	return true;
}

bool PacketManager::rplSst()
{
	std::cout << "Reply sst.." << std::endl;
	if (_args.size() != 1)
		exit(84);
	_core->setTimeUnit(atoi(_args[0].c_str()));
	return true;
}

bool PacketManager::rplSeg()
{
	std::cout << "Reply seg.." << std::endl;
	_mapManager->getPlayers().clear();
	_mapManager->getEggs().clear();
	_mapManager->getTiles().clear();
	exit(0);
	return true;
}

bool PacketManager::rplSmg()
{
	if (_args.size() != 1)
		exit(84);
	std::cout << "Reply smg.." << std::endl;
	std::cout << "Message from the server : " << _args[0] << std::endl;
	return true;
}

bool PacketManager::rplSuc()
{
	std::cout << "Reply suc.." << std::endl;
	std::cout << "Unknown command." << std::endl;
	return true;
}

bool PacketManager::rplSbp()
{
	std::cout << "Reply sbp.." << std::endl;
	std::cout << "Invalid command parameter." << std::endl;
	return true;
}
