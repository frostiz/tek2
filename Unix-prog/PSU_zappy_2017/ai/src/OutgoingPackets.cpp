/*
** EPITECH PROJECT, 2018
** OutgoingPackets.cpp
** File description:
** Zappy
*/

#include "OutgoingPackets.hpp"

OutgoingPackets::OutgoingPackets(Ai *ai)
	: _ai(ai)
{}

OutgoingPackets::~OutgoingPackets() {}

void OutgoingPackets::forward(std::string param) {
	(void) param;
	ServerMessage message("Forward");
	_ai->sendData(message);
}

void OutgoingPackets::right(std::string param) {
	(void) param;
	ServerMessage message("Right");
	_ai->sendData(message);
}

void OutgoingPackets::left(std::string param) {
	(void) param;
	ServerMessage message("Left");
	_ai->sendData(message);
}

void OutgoingPackets::connectNbr(std::string param) {
	(void) param;
	ServerMessage message("Connect_nbr");
	_ai->sendData(message);
}

void OutgoingPackets::fork(std::string param) {
	(void) param;
	ServerMessage message("Fork");
	_ai->sendData(message);
}

void OutgoingPackets::eject(std::string param) {
	(void) param;
	ServerMessage message("Eject");
	_ai->sendData(message);
}

void OutgoingPackets::take(std::string object) {
	std::string finalString = std::string("Take " + object);
	ServerMessage message(finalString.c_str());
	_ai->sendData(message);
}

void OutgoingPackets::set(std::string object) {
	std::string finalString = std::string("Set " + object);
	ServerMessage message(finalString.c_str());
	_ai->sendData(message);
}

void OutgoingPackets::incantation(std::string param) {
	(void) param;
	ServerMessage message("Incantation");
	_ai->sendData(message);
	_ai->receiveData();
}

void OutgoingPackets::broadcast(std::string param) {
	std::string finalString = std::string("Broadcast " + param);
	ServerMessage message(finalString.c_str());
	_ai->sendData(message);
}