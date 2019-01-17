/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PSU_zappy_2017 file
*/

#ifndef PSU_ZAPPY_2017_CIRCULARBUFFER_HPP
#define PSU_ZAPPY_2017_CIRCULARBUFFER_HPP

#include <iostream>

class CircularBuffer {
	public:
	CircularBuffer(const size_t &);
	~CircularBuffer() = default;

	std::string	getNextLine(const int &);

	private:
	std::string	_buffer;
	size_t		_head;
	size_t		_size;
};

#endif //PSU_ZAPPY_2017_CIRCULARBUFFER_HPP
