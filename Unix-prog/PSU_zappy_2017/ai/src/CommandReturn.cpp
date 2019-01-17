/*
** EPITECH PROJECT, 2018
** CommandReturn.cpp
** File description:
** Zappy
*/

#include "CommandReturn.hpp"

CommandReturn::CommandReturn() {

}

CommandReturn::~CommandReturn() {

}

std::vector<std::string> CommandReturn::getIndexAt(const size_t &pos) {
	return _indexes.at(pos);
}

std::vector<std::vector<std::string>> CommandReturn::getIndexes() {
	return _indexes;
}

void CommandReturn::addIndex(std::vector<std::string> param) {
	_indexes.push_back(param);
}