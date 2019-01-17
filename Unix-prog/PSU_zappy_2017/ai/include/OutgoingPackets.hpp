/*
** EPITECH PROJECT, 2018
** OutgoingPackets.hpp
** File description:
** Zappy
*/

#ifndef OUTGOING_PACKETS_HPP
# define OUTGOING_PACKETS_HPP

#include "ServerMessage.hpp"
#include "Ai.hpp"

class Ai;

class OutgoingPackets {
	public:
		OutgoingPackets(Ai *ai);
		~OutgoingPackets();
		void forward(std::string);
		void right(std::string);
		void left(std::string);
		void connectNbr(std::string);
		void fork(std::string);
		void eject(std::string);
		void take(std::string);
		void set(std::string);
		void incantation(std::string);
		void broadcast(std::string);

	private:
		Ai *_ai;
};

#endif // OUTGOING_PACKETS_HPP