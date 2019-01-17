/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** cpp_nanotekspice file
*/

#include "NtsError.hpp"

NtsError::NtsError(const std::string &message)
	: _message(message) {

}

ComponentError::ComponentError(const std::string &message)
	: NtsError(message) {

}

SpecialComponentError::SpecialComponentError(const std::string &message)
	: NtsError(message) {

}

PinError::PinError(const std::string &message)
	: NtsError(message) {

}

FileError::FileError(const std::string &message)
	: NtsError(message) {

}
