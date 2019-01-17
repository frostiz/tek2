/*
** EPITECH PROJECT, 2018
** CommandHandler.hpp
** File description:
** Zappy
*/

#ifndef COMMANDHANDLER_HPP_
# define COMMANDHANDLER_HPP_

#include <map>
#include "CommandReturn.hpp"
#include "Ai.hpp"

class CommandHandler {
	public:
		CommandHandler(Ai *ai);
		~CommandHandler();
		void executeCommand(CommandType, std::string param = "");
		CommandReturn *look();
		std::vector<std::string> inventory();
		int connectNbr();
		void askPos();
		void sendReady();
		void checkReady();

	private:
		std::vector<std::string> parseIndex(std::string);
		Ai *_ai;
		std::map<CommandType, std::function<void(std::string)> > _keys;
};

#endif // COMMANDHANDLER_HPP_