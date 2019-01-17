/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** cpp_nanotekspice file
*/

#include "components/c4069.hpp"

nts::c4069::c4069(const std::string &value)
{
	(void)value;
	for (size_t i = 0; i < _pinNumber; i++)
	{
		_pin[i].first = nullptr;
		_pin[i].second = 0;
	}
}

nts::c4069::~c4069() {

}

nts::Tristate		nts::c4069::gate_not(const nts::Tristate &value)
{
	if (value == nts::Tristate::XTRUE) {
		return nts::Tristate::XFALSE;
	} else if (value == nts::Tristate::XFALSE) {
		return nts::Tristate::XTRUE;
	}
	return nts::Tristate::XUNDEFINED;
}

nts::Tristate		nts::c4069::compute(size_t pin)
{
	size_t otherPin;
	nts::Tristate result;

	if (pin == 2) {
		pin = 1;
	} else if (pin == 4) {
		pin = 3;
	} else if (pin == 6) {
		pin = 5;
	} else if (pin == 8) {
		pin = 9;
	} else if (pin == 10) {
		pin = 11;
	} else if (pin == 12) {
		pin = 13;
	}
	else
		throw PinError("Requested pin: [" + std::to_string(pin) +"] is not valid.");
	otherPin = _pin[pin - 1].second;
	result = _pin[pin - 1].first->compute(otherPin);
	return this->gate_not(result);
}

void			nts::c4069::setLink(size_t pin, nts::IComponent &other, size_t otherPin)
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

void 			nts::c4069::dump() const
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

const size_t		&nts::c4069::getPinNumber() const {
	return _pinNumber;
}

const std::string 	&nts::c4069::getType() const {
	return _type;
}
