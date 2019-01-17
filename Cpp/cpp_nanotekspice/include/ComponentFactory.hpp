/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** cpp_nanotekspice file
*/

#ifndef CPP_NANOTEKSPICE_COMPONENT_HPP
#define CPP_NANOTEKSPICE_COMPONENT_HPP

#include <unordered_map>
#include <iostream>
#include <functional>
#include <memory>
#include "IComponent.hpp"
#include "components/Output.hpp"
#include "components/Input.hpp"
#include "components/c4081.hpp"
#include "components/c4071.hpp"
#include "components/c4069.hpp"
#include "components/c4030.hpp"
#include "components/c4001.hpp"
#include "components/c4011.hpp"
#include "components/True.hpp"
#include "components/False.hpp"
#include "components/Clock.hpp"

namespace nts {
	class ComponentFactory {
		public:
		ComponentFactory();
		~ComponentFactory();

		std::unique_ptr<nts::IComponent>	createComponent(const std::string &type, const std::string &value);

		private:
		std::unordered_map<std::string, std::function<std::unique_ptr<nts::IComponent>(const std::string &value)>>	_actions;

		std::unique_ptr<nts::IComponent>	createOutput(const std::string &value) const noexcept;
		std::unique_ptr<nts::IComponent>	createInput(const std::string &value) const noexcept;
		std::unique_ptr<nts::IComponent>	create4081(const std::string &value) const noexcept;
		std::unique_ptr<nts::IComponent>	create4071(const std::string &value) const noexcept;
		std::unique_ptr<nts::IComponent>	create4069(const std::string &value) const noexcept;
		std::unique_ptr<nts::IComponent>	create4030(const std::string &value) const noexcept;
		std::unique_ptr<nts::IComponent>	create4001(const std::string &value) const noexcept;
		std::unique_ptr<nts::IComponent>	create4011(const std::string &value) const noexcept;
		std::unique_ptr<nts::IComponent>	createTrue(const std::string &value) const noexcept;
		std::unique_ptr<nts::IComponent>	createFalse(const std::string &value) const noexcept;
		std::unique_ptr<nts::IComponent>	createClock(const std::string &value) const noexcept;
	};
}

#endif //CPP_NANOTEKSPICE_COMPONENT_HPP
