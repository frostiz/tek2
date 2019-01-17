/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** cpp_nanotekspice file
*/

#ifndef CPP_NANOTEKSPICE_CIRCUIT_HPP
#define CPP_NANOTEKSPICE_CIRCUIT_HPP

#include <unordered_map>
#include "IComponent.hpp"
#include "ComponentFactory.hpp"

namespace nts {
	class Circuit {
		public:
		Circuit();
		~Circuit();

		void simulate();
		void dumpComponents();
		void displayOutputs();
		void setSortedOutputs();
		void addComponent(const std::string &type, const std::string &name, const std::string &value);
		nts::IComponent &getComponentByName(const std::string &name);
		void invertClocks();
		const std::unordered_map<std::string, std::unique_ptr<IComponent>> &getComponents() const;

		private:
		nts::ComponentFactory *_factory;
		std::unordered_map<std::string, std::unique_ptr<nts::IComponent>> _components;
		std::unordered_map<std::string, nts::Tristate> _outputs;
		std::vector<std::string> _sortedOutputs;
	};
}
#endif //CPP_NANOTEKSPICE_CIRCUIT_HPP
