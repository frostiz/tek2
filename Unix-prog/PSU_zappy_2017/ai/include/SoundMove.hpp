/*
** EPITECH PROJECT, 2018
** SoundMove.hpp
** File description:
** Zappy
*/

#ifndef SOUNDMOVE_HPP_
# define SOUNDMOVE_HPP_

#include <map>
#include <functional>
#include "CommandHandler.hpp"

class SoundMove {
	public:
		SoundMove(Ai *);
		~SoundMove();
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
		std::map<int, std::function<int()>> _keys;
		Ai *_ai;
		CommandHandler *_cmd;
};

#endif // SOUNDMOVE_HPP_