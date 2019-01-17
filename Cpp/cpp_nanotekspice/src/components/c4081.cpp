/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** cpp_nanotekspice file
*/

#include "components/c4081.hpp"

nts::c4081::c4081(const std::string &value)
	: _truthtable {
	{nts::Tristate::XUNDEFINED, nts::Tristate::XUNDEFINED, nts::Tristate::XUNDEFINED},
	{nts::Tristate::XUNDEFINED, nts::Tristate::XFALSE, nts::Tristate::XFALSE},
	{nts::Tristate::XUNDEFINED, nts::Tristate::XTRUE, nts::Tristate::XUNDEFINED},
	{nts::Tristate::XFALSE, nts::Tristate::XUNDEFINED, nts::Tristate::XFALSE},
	{nts::Tristate::XFALSE, nts::Tristate::XFALSE, nts::Tristate::XFALSE},
	{nts::Tristate::XFALSE, nts::Tristate::XTRUE, nts::Tristate::XFALSE},
	{nts::Tristate::XTRUE, nts::Tristate::XUNDEFINED, nts::Tristate::XUNDEFINED},
	{nts::Tristate::XTRUE, nts::Tristate::XFALSE, nts::Tristate::XFALSE},
	{nts::Tristate::XTRUE, nts::Tristate::XTRUE, nts::Tristate::XTRUE},
}
{
	(void)value;
	for (size_t i = 0; i < _pinNumber; i++)
	{
		_pin[i].first = nullptr;
		_pin[i].second = 0;
	}
}

nts::c4081::~c4081() {

}

nts::Tristate		nts::c4081::gate_and(const nts::Tristate &left, const nts::Tristate &right)
{
	for (int i = 0; i < 9; i++) {
		if (left == _truthtable[i][0] && right == _truthtable[i][1]) {
			return _truthtable[i][2];
		}
	}
	return nts::Tristate::XUNDEFINED;
}

nts::Tristate		nts::c4081::compute(size_t pin)
{
	size_t pin1;
	size_t pin2;
	size_t otherPin1;
	size_t otherPin2;
	nts::Tristate result1;
	nts::Tristate result2;

	if (pin == 3) {
		pin1 = 1;
		pin2 = 2;
	} else if (pin == 4) {
		pin1 = 5;
		pin2 = 6;
	} else if (pin == 10) {
		pin1 = 8;
		pin2 = 9;
	} else if (pin == 11) {
		pin1 = 12;
		pin2 = 13;
	} else
		throw PinError("Requested pin: [" + std::to_string(pin) +"] is not valid.");
	otherPin1 = _pin[pin1 - 1].second;
	otherPin2 = _pin[pin2 - 1].second;
	result1 = _pin[pin1 - 1].first->compute(otherPin1);
	result2 = _pin[pin2 - 1].first->compute(otherPin2);
	return this->gate_and(result1, result2);
}

void			nts::c4081::setLink(size_t pin, nts::IComponent &other, size_t otherPin)
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

void 			nts::c4081::dump() const
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

const size_t		&nts::c4081::getPinNumber() const {
	return _pinNumber;
}

const std::string 	&nts::c4081::getType() const {
	return _type;
}
