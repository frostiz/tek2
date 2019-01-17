/*
** EPITECH PROJECT, 2018
** Moves.cpp
** File description:
** Zappy
*/

#include "SoundMove.hpp"

SoundMove::SoundMove(Ai *ai)
	: _ai(ai)
{
	_keys[1] = std::bind(&SoundMove::moveOne, this);
	_keys[2] = std::bind(&SoundMove::moveTwo, this);
	_keys[3] = std::bind(&SoundMove::moveThree, this);
	_keys[4] = std::bind(&SoundMove::moveFour, this);
	_keys[5] = std::bind(&SoundMove::moveFive, this);
	_keys[6] = std::bind(&SoundMove::moveSix, this);
	_keys[7] = std::bind(&SoundMove::moveSeven, this);
	_keys[8] = std::bind(&SoundMove::moveHeight, this);

	_cmd = new CommandHandler(ai);
}

SoundMove::~SoundMove() {
	
}

int SoundMove::moveTo(int pos) {
	int value = 0;
	if (pos != -1 && pos != 0)
		value = _keys[pos]();
	return value;
}

int SoundMove::moveOne() {
	_cmd->executeCommand(CommandType::FORWARD);
	return 7;
}

int SoundMove::moveTwo() {
	_cmd->executeCommand(CommandType::FORWARD);
	_cmd->executeCommand(CommandType::LEFT);
	_cmd->executeCommand(CommandType::FORWARD);
	return 21;
}

int SoundMove::moveThree() {
	_cmd->executeCommand(CommandType::LEFT);
	_cmd->executeCommand(CommandType::FORWARD);
	return 14;
}

int SoundMove::moveFour() {
	_cmd->executeCommand(CommandType::LEFT);
	_cmd->executeCommand(CommandType::FORWARD);
	_cmd->executeCommand(CommandType::LEFT);
	_cmd->executeCommand(CommandType::FORWARD);
	return 28;
}

int SoundMove::moveFive() {
	_cmd->executeCommand(CommandType::LEFT);
	_cmd->executeCommand(CommandType::LEFT);
	_cmd->executeCommand(CommandType::FORWARD);
	return 21;
}

int SoundMove::moveSix() {
	_cmd->executeCommand(CommandType::RIGHT);
	_cmd->executeCommand(CommandType::FORWARD);
	_cmd->executeCommand(CommandType::RIGHT);
	_cmd->executeCommand(CommandType::FORWARD);
	return 14;
}

int SoundMove::moveSeven() {
	_cmd->executeCommand(CommandType::RIGHT);
	_cmd->executeCommand(CommandType::FORWARD);
	return 14;
}

int SoundMove::moveHeight() {
	_cmd->executeCommand(CommandType::FORWARD);
	_cmd->executeCommand(CommandType::RIGHT);
	_cmd->executeCommand(CommandType::FORWARD);
	return 21;
}