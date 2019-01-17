/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PSU_zappy_2017 file
*/

#ifndef PSU_ZAPPY_2017_PACKETMANAGER_HPP
#define PSU_ZAPPY_2017_PACKETMANAGER_HPP

#include <vector>
#include <iostream>
#include <unordered_map>
#include <functional>
#include "EventManager.hpp"
#include "CircularBuffer.hpp"

class Core;
class TeamManager;
class GraphicManager;
class MapManager;

class PacketManager {
	public:
	PacketManager(Core *);
	~PacketManager() = default;

	void	initialize(const std::string &);
	void	receiveData();
	void	sendData(const std::string &);

	int	&getTilesInitialized();

	private:
	void	onDataReceived();
	void	parseCommand(const std::string &);
	void	execCommand();

	bool	rplWelcome();
	bool	rplMsz();
	bool	rplBct();
	bool	rplTna();
	bool	rplPnw();
	bool	rplPpo();
	bool	rplPlv();
	bool	rplPin();
	bool	rplPex();
	bool	rplPbc();
	bool	rplPic();
	bool	rplPie();
	bool	rplPfk();
	bool	rplPdr();
	bool	rplPgt();
	bool	rplPdi();
	bool	rplEnw();
	bool	rplEht();
	bool	rplEbo();
	bool	rplEdi();
	bool	rplSgt();
	bool	rplSst();
	bool	rplSeg();
	bool	rplSmg();
	bool	rplSuc();
	bool	rplSbp();

	MapManager			*_mapManager;
	TeamManager			*_teamManager;
	CircularBuffer			*_circularBuffer;
	GraphicManager			*_graphicManager;
	Core				*_core;

	std::unordered_map<std::string, std::function<bool(void)>>	_packetFunc;

	fd_set				_read;
	fd_set				_write;
	int				_socketFd;
	std::string			_command;
	std::vector<std::string>	_args;

	int				_tilesInitialized;
};

#endif //PSU_ZAPPY_2017_PACKETMANAGER_HPP
