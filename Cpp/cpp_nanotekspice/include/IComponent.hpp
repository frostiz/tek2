/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** cpp_nanotekspice file
*/

#ifndef CPP_NANOTEKSPICE_ICOMPONENT_HPP
#define CPP_NANOTEKSPICE_ICOMPONENT_HPP

#include <iostream>
#include <vector>
#include "NtsError.hpp"

namespace nts
{
	enum Tristate {
		XUNDEFINED = (-true),
		XTRUE = true,
		XFALSE = false
	};

	class  IComponent
	{
		public:
		virtual ~IComponent () = default;
		virtual nts::Tristate		compute(size_t pin = 1) = 0;
		virtual void  			setLink(size_t pin, nts::IComponent &other, size_t otherPin) = 0;
		virtual void  			dump() const = 0;

		virtual const size_t		&getPinNumber() const = 0;
		virtual const std::string 	&getType() const = 0;
	};
}

#endif //CPP_NANOTEKSPICE_ICOMPONENT_HPP
