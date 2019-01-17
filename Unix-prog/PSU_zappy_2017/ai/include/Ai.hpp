/*
** EPITECH PROJECT, 2018
** ai
** File description:
** Ai.hpp
*/

#ifndef AI_HPP_
#define AI_HPP_

#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <iostream>
#include <map>
#include <functional>
#include "ServerMessage.hpp"
#include "IncomingPackets.hpp"
#include "OutgoingPackets.hpp"
#include "Packet.hpp"
#include "CommandType.hpp"

class OutgoingPackets;
class IncomingPackets;

enum ReturnState {
	OK,
	KO,
	UNDEFINED
};

enum Incantation {
	READY,
	NOTREADY
};

class Ai {
	public:
		Ai(std::string, int, std::string);
		~Ai() = default;
		void initCommunication();
		void receiveData();
		void receiveDeath();
		void readData();
		std::string readUnformattedData();
		void sendData(ServerMessage &, bool waitResponse = true);
		void handshake();
		void executePacket(const char *);
		void setDead(bool);
		bool getDead() const;
		void setStatus(const ReturnState &);
		ReturnState getStatus();
		std::string getTeam();
		int getLvl();
		void setLvl(int);
		Incantation getIncantationState();
		void setIncantationState(Incantation);

	private:
		int 		_socket;
		std::string 	_ip;
		int 		_port;
		std::string 	_team;
		int 		_maxClients;
		std::map<std::string, std::function<void(Packet&)>> _receiveKeys;
		bool 		_dead;
		ReturnState	_status;
		int 		_lvl;
		Incantation 	_incantationStatus;
};

#endif /*AI_HPP_*/