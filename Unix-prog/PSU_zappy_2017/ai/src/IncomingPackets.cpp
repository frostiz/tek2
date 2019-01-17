/*
** EPITECH PROJECT, 2018
** IncomingPackets.cpp
** File description:
** Zappy
*/

#include "IncomingPackets.hpp"
#include "ParseUtils.hpp"
#include "SoundMove.hpp"
#include "CommandReturn.hpp"

IncomingPackets::IncomingPackets(Ai *ai)
	: _ai(ai)
{}

IncomingPackets::~IncomingPackets() {}

void IncomingPackets::receiveWelcome(Packet &packet) {
	(void) packet;
}

void IncomingPackets::receiveDead(Packet &packet) {
	(void) packet;
	_ai->setDead(true);
}

void IncomingPackets::receiveOk(Packet &packet) {
	(void) packet;
	_ai->setStatus(ReturnState::OK);
}

void IncomingPackets::receiveKo(Packet &packet) {
	(void) packet;
	_ai->setStatus(ReturnState::KO);
}

void IncomingPackets::receiveMessage(Packet &packet) {
	CommandHandler *cmdHandler = new CommandHandler(_ai);
	SoundMove *moveClass = new SoundMove(_ai);
	ParseUtils *parser = new ParseUtils();
	std::vector<std::string> out = parser->split(packet.getRaw(), ',');
	std::cout << packet.getParamAt(1) << std::endl;
	if (packet.getParamAt(1) == "ready") {
		if (stoi(packet.getParamAt(2)) == _ai->getLvl()) {
			std::string from = packet.getParamAt(0);
			from = from.substr(0, from.size()-1);
			int move;
			try {
				move = stoi(from);
			} catch (std::exception &e) {
				std::cerr << e.what() << std::endl;
				exit(84);
			}
			moveClass->moveTo(move);
			cmdHandler->askPos();
		}
	}
	else if (packet.getParamAt(1) == "here") {
		int move;
		std::string from = packet.getParamAt(0);
		from = from.substr(0, from.size()-1);
		try {
			move = stoi(from);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			exit(84);
		}
		moveClass->moveTo(move);
		if (this->findPlayer() <= 1) {
			cmdHandler->askPos();
		}
		else {
			while (this->findPlayer() > 1);
		}
	}
	else if (packet.getParamAt(1) == "pos") {
		if (_ai->getIncantationState() == Incantation::READY) {
			ServerMessage message("Broadcast here");
			_ai->sendData(message);
		}
	}
	else if (packet.getParamAt(1) == "checkReady") {
		if (_ai->getIncantationState() == Incantation::READY) {
			cmdHandler->sendReady();
		}
	}
}

int IncomingPackets::findPlayer() {
	CommandReturn *cmdReturn = new CommandReturn();
	CommandHandler *cmdHandler = new CommandHandler(_ai);
	cmdReturn = cmdHandler->look();
	std::vector<std::string> vector = cmdReturn->getIndexAt(0);
	int player = 0;
	for (auto current : vector) {
		if (current == "player") 
			player++;
	}
	return player;
}