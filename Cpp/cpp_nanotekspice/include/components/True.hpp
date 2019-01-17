/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** cpp_nanotekspice file
*/

#ifndef CPP_NANOTEKSPICE_TRUE_HPP
#define CPP_NANOTEKSPICE_TRUE_HPP

#include "IComponent.hpp"

namespace nts {
	class True : public nts::IComponent {
		public:
		True(const std::string &value);
		~True();

		nts::Tristate		compute(size_t pin = 1) override;
		void 			setLink(size_t pin, nts::IComponent &other, size_t otherPin) override;
		void 			dump() const override;

		const size_t		&getPinNumber() const override;
		const std::string 	&getType() const override;

		private:
		std::pair<nts::IComponent *, size_t>	_pin[1];
		const size_t				_pinNumber = 1;
		const std::string			_type = "true";

	};
}

#endif //CPP_NANOTEKSPICE_TRUE_HPP
