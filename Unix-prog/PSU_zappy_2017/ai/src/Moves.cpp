/*
** EPITECH PROJECT, 2018
** Moves.cpp
** File description:
** Zappy
*/

#include "Moves.hpp"

Moves::Moves(Ai *ai)
	: _ai(ai)
{
	_keys[1] = std::bind(&Moves::moveOne, this);
	_keys[2] = std::bind(&Moves::moveTwo, this);
	_keys[3] = std::bind(&Moves::moveThree, this);
	_keys[4] = std::bind(&Moves::moveFour, this);
	_keys[5] = std::bind(&Moves::moveFive, this);
	_keys[6] = std::bind(&Moves::moveSix, this);
	_keys[7] = std::bind(&Moves::moveSeven, this);
	_keys[8] = std::bind(&Moves::moveHeight, this);
	_keys[9] = std::bind(&Moves::moveNine, this);
	_keys[10] = std::bind(&Moves::moveTen, this);
	_keys[11] = std::bind(&Moves::moveEleven, this);
	_keys[12] = std::bind(&Moves::moveTwelve, this);
	_keys[13] = std::bind(&Moves::moveThirteen, this);
	_keys[14] = std::bind(&Moves::moveFourteen, this);
	_keys[15] = std::bind(&Moves::moveFifteen, this);

	_cmd = new CommandHandler(ai);
}

Moves::~Moves() {

}

int Moves::moveTo(int pos) {
	int value = 0;
	if (pos != -1 && pos != 0)
		value = _keys[pos]();
	return value;
}

int Moves::moveOne() {
	_cmd->executeCommand(CommandType::FORWARD);
	_cmd->executeCommand(CommandType::LEFT);
	_cmd->executeCommand(CommandType::FORWARD);
	return 21;
}

int Moves::moveTwo() {
	_cmd->executeCommand(CommandType::FORWARD);
	return 7;
}

int Moves::moveThree() {
	_cmd->executeCommand(CommandType::FORWARD);
	_cmd->executeCommand(CommandType::RIGHT);
	_cmd->executeCommand(CommandType::FORWARD);
	return 21;
}

int Moves::moveFour() {
	this->moveOne();
	this->moveOne();
	return 42;
}

int Moves::moveFive() {
	this->moveOne();
	_cmd->executeCommand(CommandType::FORWARD);
	return 28;
}

int Moves::moveSix() {
	_cmd->executeCommand(CommandType::FORWARD);
	_cmd->executeCommand(CommandType::FORWARD);
	return 14;
}

int Moves::moveSeven() {
	this->moveThree();
	_cmd->executeCommand(CommandType::FORWARD);
	return 28;
}

int Moves::moveHeight() {
	this->moveThree();
	this->moveThree();
	return 42;
}

int Moves::moveNine() {
	this->moveFour();
	this->moveOne();
	return 63;
}

int Moves::moveTen() {
	this->moveFive();
	this->moveOne();
	return 49;
}

int Moves::moveEleven() {
	this->moveSix();
	this->moveOne();
	return 35;
}

int Moves::moveTwelve() {
	this->moveSix();
	_cmd->executeCommand(CommandType::FORWARD);
	return 21;
}

int Moves::moveThirteen() {
	this->moveSix();
	this->moveThree();
	return 35;
}

int Moves::moveFourteen() {
	this->moveSeven();
	this->moveThree();
	return 49;
}

int Moves::moveFifteen() {
	this->moveHeight();
	this->moveThree();
	return 63;
}