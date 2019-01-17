//
// EPITECH PROJECT, 2018
// ArcadeException.hpp
// File description:
// ArcadeException
//

#include "ArcadeException.hpp"

NoDirectoryException::NoDirectoryException(const char *msg) : exception(), _msg(msg)
{
}

const char *NoDirectoryException::what() const noexcept
{
	return _msg;
}
