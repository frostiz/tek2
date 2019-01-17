/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PSU_zappy_2017 file
*/

#include <unistd.h>
#include "CircularBuffer.hpp"

CircularBuffer::CircularBuffer(const size_t &size)
{
	_size = size;
	_buffer.reserve(size);
	//_buffer.resize(size);
	_head = 0;
}

std::string CircularBuffer::getNextLine(const int &fd)
{
	char c = 0;
	size_t nbChar = 0;
	size_t initHead = _head;

	while (read(fd, &c, 1) >= 0) {
		if (c == '\n') {
			std::string final;

			if (_head < initHead) {
				final = std::string(_buffer.begin() + initHead, _buffer.end());
				initHead = 0;
			}
			final += std::string(_buffer.begin() + initHead, _buffer.begin() + _head);
			return final;
		}
		if (_buffer.size() < _size)
			_buffer += c;
		else
			_buffer[_head] = c;
		++nbChar;
		++_head;
		if (_head == _size)
			_head = 0;
	}
	return "";
}