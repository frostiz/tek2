/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** cpp_nanotekspice file
*/

#ifndef CPP_NANOTEKSPICE_C4001_HPP
#define CPP_NANOTEKSPICE_C4001_HPP

#include "IComponent.hpp"

namespace nts {
	class c4001 : public nts::IComponent {
		public:
		c4001(const std::string &value);
		~c4001();

		nts::Tristate		compute(size_t pin = 1) override;
		void 			setLink(size_t pin, nts::IComponent &other, size_t otherPin) override;
		void 			dump() const override;

		nts::Tristate		gate_nor(const nts::Tristate &left, const nts::Tristate &right);
		const size_t		&getPinNumber() const override;
		const std::string 	&getType() const override;

		private:
		std::pair<nts::IComponent *, size_t>	_pin[14];
		const size_t				_pinNumber = 14;
		const std::string			_type = "4001";
		const nts::Tristate			_truthtable[9][3];
	};
}

#endif //CPP_NANOTEKSPICE_C4001_HPP
