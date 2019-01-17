/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** cpp_nanotekspice file
*/

#include "components/Input.hpp"

nts::Input::Input(const std::string &value)
{
	if (value == "0")
		_state = nts::Tristate::XFALSE;
	else if (value == "1")
		_state = nts::Tristate::XTRUE;
	else if (value == "-1")
		_state = nts::Tristate::XUNDEFINED;
	_pin[0].first = nullptr;
	_pin[0].second = 0;
}

nts::Input::~Input() {

}

nts::Tristate		nts::Input::compute(size_t pin)
{
	if (pin == 1) {
		return _state;
	} else {
		throw PinError("Requested pin : " + std::to_string(pin) + " does not exist on Input component.");
	}
}

void  			nts::Input::setLink(size_t pin, nts::IComponent &other, size_t otherPin)
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

void  			nts::Input::dump() const
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

void			nts::Input::setState(const nts::Tristate &state)
{
	_state = state;
}

const size_t		&nts::Input::getPinNumber() const {
	return _pinNumber;
}

const std::string	&nts::Input::getType() const {
	return _type;
}
