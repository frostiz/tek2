/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** cpp_nanotekspice file
*/

#include "components/Output.hpp"

nts::Output::Output(const std::string &value)
{
	(void)value;
	_pin[0].first = nullptr;
	_pin[0].second = 0;
}

nts::Output::~Output() {

}

nts::Tristate		nts::Output::compute(size_t pin)
{
	if (pin == 1 && _pin[0].first != nullptr) {
		size_t otherPin = _pin[0].second;
		return _pin[0].first->compute(otherPin);
	} else {
		throw PinError("Requested pin : " + std::to_string(pin) + " does not exist on Output component.");
	}
}

void			nts::Output::setLink(size_t pin, nts::IComponent &other, size_t otherPin)
{
	if (pin > 0 && pin <= _pinNumber) {
		if (other.getPinNumber() < otherPin)
			throw PinError("The requested pin: [" + std::to_string(otherPin) + "] does not exist.");
		pin -= 1;
		_pin[pin].first = &other;
		_pin[pin].second = otherPin;
	} else {
		throw PinError("The requested pin: [" + std::to_string(pin) + "] does not exist.");
	}
}

void			nts::Output::dump() const
{
	for (size_t i = 0; i < _pinNumber; i++)
	{
		if (_pin[i].first != nullptr && _pin[i].second != 0)
			std::cout << "- Pin [" << _type << ":" << (i + 1)
				  << "] is linked with [" << _pin[i].first->getType() << ":" << _pin[i].second << "]" << std::endl;
		else
			std::cout << "- Pin [" << (i + 1) << "] is not linked" << std::endl;
	}
}

const size_t		&nts::Output::getPinNumber() const {
	return _pinNumber;
}

const std::string	&nts::Output::getType() const {
	return _type;
}

bool			nts::Output::isLinked() const
{
	if (_pin[0].first) {
		return true;
	}
	return false;
}