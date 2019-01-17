/*
** EPITECH PROJECT, 2018
** CommandHandler.cpp
** File description:
** Zappy
*/

#include "CommandHandler.hpp"
#include "ParseUtils.hpp"

CommandHandler::CommandHandler(Ai *ai)
	: _ai(ai)
{
	OutgoingPackets *outgoing = new OutgoingPackets(_ai);

	_keys[CommandType::FORWARD] = std::bind(&OutgoingPackets::forward, outgoing, std::placeholders::_1);
	_keys[CommandType::RIGHT] = std::bind(&OutgoingPackets::right, outgoing, std::placeholders::_1);
	_keys[CommandType::LEFT] = std::bind(&OutgoingPackets::left, outgoing, std::placeholders::_1);
	_keys[CommandType::CONNECT_NBR] = std::bind(&OutgoingPackets::connectNbr, outgoing, std::placeholders::_1);
	_keys[CommandType::FORK] = std::bind(&OutgoingPackets::fork, outgoing, std::placeholders::_1);
	_keys[CommandType::EJECT] = std::bind(&OutgoingPackets::eject, outgoing, std::placeholders::_1);
	_keys[CommandType::TAKE] = std::bind(&OutgoingPackets::take, outgoing, std::placeholders::_1);
	_keys[CommandType::SET] = std::bind(&OutgoingPackets::set, outgoing, std::placeholders::_1);
	_keys[CommandType::INCANTATION] = std::bind(&OutgoingPackets::incantation, outgoing, std::placeholders::_1);
	_keys[CommandType::BROADCAST] = std::bind(&OutgoingPackets::broadcast, outgoing, std::placeholders::_1);
	
}

CommandHandler::~CommandHandler() {}

void CommandHandler::executeCommand(CommandType type, std::string param)
{
	if (_ai->getDead() == false) {
		_keys[type](param);
	}
}

CommandReturn *CommandHandler::look() {
	ServerMessage message("Look");
	_ai->sendData(message, false);
	std::string raw = _ai->readUnformattedData();
	CommandReturn *cmdReturn = new CommandReturn();
	ParseUtils parser = ParseUtils();
	std::vector<std::string> tmpIndexes = parser.split(raw, ',');
	for (auto current : tmpIndexes) {
		std::vector<std::string> tmp = this->parseIndex(current);
		cmdReturn->addIndex(tmp);
	}
	return cmdReturn;
}

std::vector<std::string> CommandHandler::parseIndex(std::string rawIndex) {
	ParseUtils parser = ParseUtils();
	std::cout << rawIndex << std::endl;
	if (rawIndex.size() != 0 && rawIndex.at(0) == '[')
		rawIndex.erase(0, 1);
	if (rawIndex.size() != 0 && rawIndex.back() == ']')
		rawIndex.erase(rawIndex.size() - 1);
	std::vector<std::string> items = parser.split(rawIndex, ' ');
	return items;
}

std::vector<std::string> CommandHandler::inventory() {
	ServerMessage message("Inventory");
	_ai->sendData(message, false);
	std::string raw = _ai->readUnformattedData();
	ParseUtils parser = ParseUtils();
	if (raw.size() != 2) {
		raw.erase(0, 2);
		raw.erase(raw.size() - 2, 2);
	}
	std::vector<std::string> tmpIndexes = parser.split(raw, ',');
	std::vector<std::string> finalVector;
	for (auto current : tmpIndexes) {
		if (current.size() > 0 && current.at(0) == ' ')
			current.erase(0, 1);
		finalVector.push_back(current);
	}
	return finalVector;
}

int CommandHandler::connectNbr() {
	ServerMessage message("Connect_nbr");
	_ai->sendData(message, false);
	std::string raw = _ai->readUnformattedData();
	int value = 0;
	try {
		value = stoi(raw);
	} catch (std::exception &e) {
	}
	return value;
}

void CommandHandler::sendReady() {
	std::string finalStr("Broadcast ready " + std::to_string(_ai->getLvl()));
	ServerMessage message(finalStr.c_str());
	_ai->sendData(message);
}

void CommandHandler::askPos() {
	ServerMessage message("Broadcast pos");
	_ai->sendData(message);
}

void CommandHandler::checkReady() {
	ServerMessage message("Broadcast checkReady");
	_ai->sendData(message);
}