/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** cpp_nanotekspice file
*/

#ifndef CPP_NANOTEKSPICE_C4069_HPP
#define CPP_NANOTEKSPICE_C4069_HPP

#include "IComponent.hpp"

namespace nts {
	class c4069 : public nts::IComponent {
		public:
		c4069(const std::string &value);
		~c4069();

		nts::Tristate		compute(size_t pin = 1) override;
		void 			setLink(size_t pin, nts::IComponent &other, size_t otherPin) override;
		void 			dump() const override;

		nts::Tristate		gate_not(const nts::Tristate &value);
		const size_t		&getPinNumber() const override;
		const std::string 	&getType() const override;

		private:
		std::pair<nts::IComponent *, size_t>	_pin[14];
		const size_t				_pinNumber = 14;
		const std::string			_type = "4069";
	};
}

#endif //CPP_NANOTEKSPICE_C4069_HPP