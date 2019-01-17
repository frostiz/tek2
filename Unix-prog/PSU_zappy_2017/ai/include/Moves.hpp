/*
** EPITECH PROJECT, 2018
** Moves.hpp
** File description:
** Zappy
*/

#ifndef MOVES_HPP_
# define MOVES_HPP_

#include <map>
#include <functional>
#include "CommandHandler.hpp"

class Moves {
	public:
		Moves(Ai *);
		~Moves();
		int moveTo(int);
	
	private:
		int moveOne();
		int moveTwo();
		int moveThree();
		int moveFour();
		int moveFive();
		int moveSix();
		int moveSeven();
		int moveHeight();
		int moveNine();
		int moveTen();
		int moveEleven();
		int moveTwelve();
		int moveThirteen();
		int moveFourteen();
		int moveFifteen();
		std::map<int, std::function<int()>> _keys;
		Ai *_ai;
		CommandHandler *_cmd;
};

#endif // MOVES_HPP_