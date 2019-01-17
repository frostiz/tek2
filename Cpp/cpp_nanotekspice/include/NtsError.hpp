/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** cpp_nanotekspice file
*/

#ifndef CPP_NANOTEKSPICE_NTSERROR_HPP
#define CPP_NANOTEKSPICE_NTSERROR_HPP

#include <exception>
#include <iostream>

class NtsError : public std::exception {
	public:
	explicit NtsError(const std::string &message);

	const char *what() const noexcept override {
		return this->_message.c_str();
	}

	protected:
	std::string	_message;
};

class ComponentError : public NtsError {
	public:
	explicit ComponentError(const std::string &message);
};

class SpecialComponentError : public NtsError {
	public:
	explicit SpecialComponentError(const std::string &message);
};

class PinError : public NtsError {
	public:
	explicit PinError(const std::string &message);
};

class FileError : public NtsError {
	public:
	explicit FileError(const std::string &message);
};

#endif //CPP_NANOTEKSPICE_NTSERROR_HPP
