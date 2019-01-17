/*
** EPITECH PROJECT, 2018
** ai
** File description:
** Ai.cpp
*/

#include <cstring>
#include "Ai.hpp"

Ai::Ai(std::string ipAdress, int port, std::string team)
	: _ip(ipAdress), _port(port), _team(team)
{
	IncomingPackets *incoming = new IncomingPackets(this);
	_dead = false;
	_receiveKeys["WELCOME"] = std::bind(&IncomingPackets::receiveWelcome, incoming, std::placeholders::_1);
	_receiveKeys["dead"] = std::bind(&IncomingPackets::receiveDead, incoming, std::placeholders::_1);
	_receiveKeys["ok"] = std::bind(&IncomingPackets::receiveOk, incoming, std::placeholders::_1);
	_receiveKeys["ko"] = std::bind(&IncomingPackets::receiveKo, incoming, std::placeholders::_1);
	_receiveKeys["message"] = std::bind(&IncomingPackets::receiveMessage, incoming, std::placeholders::_1);

	this->initCommunication();
	this->receiveData();
	this->handshake();
}

void Ai::initCommunication()
{
	struct sockaddr_in servAddr;
	this->_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (this->_socket < 0) {
		std::cerr << "Ai can't create socket" << std::endl;
		exit(84);
	}
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(_port);
	if (inet_pton(AF_INET, _ip.c_str(), &servAddr.sin_addr) <= 0) {
		std::cerr << "Ai invalid address" << std::endl;
		exit(84);
	}
	if (connect(this->_socket, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0) {
		std::cerr << "Ai can't connect to server" << std::endl;
		exit(84);
	}
}

void Ai::receiveDeath()
{
	fd_set readFd;
	struct timeval tv;
	if (this->_socket <= 0)
		return;
	tv.tv_sec = 0;
	tv.tv_usec = 300;
	FD_ZERO(&readFd);
	FD_SET(this->_socket, &readFd);
	int activity = select(this->_socket+1, &readFd, NULL, NULL, &tv);
	if (activity && FD_ISSET(this->_socket, &readFd))
		this->readData();
}

void Ai::receiveData()
{
	if (_dead == false) {
		fd_set readFd;
		if (this->_socket <= 0)
			return;
		FD_ZERO(&readFd);
		FD_SET(this->_socket, &readFd);
		int activity = select(this->_socket + 1, &readFd, NULL, NULL,
			NULL);
		if (activity && FD_ISSET(this->_socket, &readFd))
			this->readData();
	}
}


void Ai::readData()
{
	std::string tmpBuffer("");
	char buffer[4096] = { 0 };
	read(this->_socket, buffer, 4096);
	if (strncmp(buffer, "dead", 4) == 0) {
		_dead = true;
		close(_socket);
		std::cout << "dead" << std::endl;
		exit(0);
	}
	tmpBuffer.append(buffer);
	std::size_t clrf;
	while ((clrf = tmpBuffer.find("\n")) != std::string::npos) {
		std::string data = tmpBuffer.substr(0, clrf);
		std::string tmp = tmpBuffer.substr(clrf + 1);
		tmpBuffer = tmp;
		std::cout << "RCV : '" << data << "'" << std::endl;
		this->executePacket(data.c_str());
	}
}



std::string Ai::readUnformattedData()
{
	std::string tmpBuffer("");
	char buffer[4096] = { 0 };

	read(this->_socket, buffer, 4096);
	tmpBuffer.append(buffer);
	std::size_t clrf;
	while ((clrf = tmpBuffer.find("\n")) != std::string::npos) {
		std::string data = tmpBuffer.substr(0, clrf);
		std::string tmp = tmpBuffer.substr(clrf + 1);
		tmpBuffer = tmp;
		std::cout << "RCV : '" << data << "'" << std::endl;
		return data;
	}
	return "";
}

void Ai::sendData(ServerMessage &message, bool waitResponse)
{
	std::string tmp(message.getBody());
	tmp.append("\n");
	if (_dead == false)
		send(this->_socket, tmp.c_str(), tmp.length(), 0);
	std::cout << "SEND : '" << tmp << "'" << std::endl;
	if (waitResponse) {
		this->receiveData();
	}
}

void Ai::handshake()
{
	ServerMessage message(_team.c_str());
	this->sendData(message, false);
	std::string raw = this->readUnformattedData();
}

void Ai::executePacket(const char *data)
{
	std::string raw(data);
	Packet packetParsed = Packet(raw);
	if (_receiveKeys[packetParsed.getCommand()]) {
		_receiveKeys[packetParsed.getCommand()](packetParsed);
	}
}

void Ai::setDead(const bool dead)
{
	_dead = dead;
}

bool Ai::getDead() const
{
	return _dead;
}

void Ai::setStatus(const ReturnState &state)
{
	_status = state;
}

ReturnState Ai::getStatus()
{
	return _status;
}

std::string Ai::getTeam() {
	return _team;
}

int Ai::getLvl() {
	return _lvl;
}

void Ai::setLvl(int lvl) {
	_lvl = lvl;
}

Incantation Ai::getIncantationState() {
	return _incantationStatus;
}

void Ai::setIncantationState(Incantation incant) {
	_incantationStatus = incant;
}