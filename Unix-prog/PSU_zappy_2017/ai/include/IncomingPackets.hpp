/*
** EPITECH PROJECT, 2018
** IncomingPackets.hpp
** File description:
** Zappy
*/

#ifndef INCOMING_PACKETS_HPP
# define INCOMING_PACKETS_HPP

#include "Packet.hpp"
#include "Ai.hpp"

class Ai;

class IncomingPackets {
	public:
		IncomingPackets(Ai *ai);
		~IncomingPackets();
		void receiveWelcome(Packet &);
		void receiveDead(Packet &);
		void receiveOk(Packet &);
		void receiveKo(Packet &);
		void receiveMessage(Packet &);

	private:
		int findPlayer();
		Ai *_ai;
};

#endif // INCOMING_PACKETS_HPP