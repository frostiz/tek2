/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** cpp_nanotekspice file
*/

#include "components/True.hpp"


nts::True::True(const std::string &value)
{
	(void)value;
	for (size_t i = 0; i < _pinNumber; i++)
	{
		_pin[i].first = nullptr;
		_pin[i].second = 0;
	}
}

nts::True::~True() {

}

nts::Tristate		nts::True::compute(size_t pin)
{
	(void)pin;
	return nts::Tristate::XTRUE;
}

void			nts::True::setLink(size_t pin, nts::IComponent &other, size_t otherPin)
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

void 			nts::True::dump() const
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

const size_t		&nts::True::getPinNumber() const {
	return _pinNumber;
}

const std::string 	&nts::True::getType() const {
	return _type;
}
