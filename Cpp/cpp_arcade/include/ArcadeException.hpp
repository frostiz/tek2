//
// EPITECH PROJECT, 2018
// ArcadeException.hpp
// File description:
// ArcadeException
//

#ifndef CPP_ARCADE_EXCEPTION_HPP
#define CPP_ARCADE_EXCEPTION_HPP

#include <exception>
#include <iostream>

class NoDirectoryException : public std::exception {
	public:
	NoDirectoryException(const char *msg);

	const char *what() const noexcept override;

	private:
	const char *_msg;
};

#endif //CPP_ARCADE_EXCEPTION_HPP
