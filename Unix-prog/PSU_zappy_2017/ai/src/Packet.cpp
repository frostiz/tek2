/*
** EPITECH PROJECT, 2018
** Packet.cpp
** File description:
** Zappy
*/

#include <iostream>
#include "Packet.hpp"
#include "ParseUtils.hpp"

Packet::Packet(std::string raw)
	: _raw(raw)
{
	this->parsePacket();
}

Packet::~Packet() {}

void Packet::parsePacket() {
	ParseUtils parserUtils = ParseUtils();

	std::vector<std::string> args = parserUtils.split(_raw, ' ');
	_command = args.at(0);
	args.erase(args.begin());
	for (auto current : args) {
		_params.push_back(current);
	}
}

std::string Packet::getCommand() {
	return _command;
}

std::vector<std::string> Packet::getParams() {
	return _params;
}

std::string Packet::getParamAt(int pos) {
	return _params.at(pos);
}

std::string Packet::getRaw() {
	return _raw;
}