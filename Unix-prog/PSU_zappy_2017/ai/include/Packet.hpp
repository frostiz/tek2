/*
** EPITECH PROJECT, 2018
** Packet.hpp
** File description:
** Zappy
*/

#ifndef PACKET_HPP_
# define PACKET_HPP_

#include <vector>
#include <string>

class Packet {
	public:
		Packet(std::string);
		~Packet();
		std::string getCommand();
		std::vector<std::string> getParams();
		std::string getParamAt(int);
		std::string getRaw();
	
	private:
		void parsePacket();
		void addParam(int, size_t&);
		std::string _raw;
		std::string _command;
		std::vector<std::string> _params;

};

#endif // PACKET_HPP_