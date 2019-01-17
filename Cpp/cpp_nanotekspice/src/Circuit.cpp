/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** cpp_nanotekspice file
*/

#include <algorithm>
#include "NtsError.hpp"
#include "Circuit.hpp"

nts::Circuit::Circuit()
{
	_factory = new ComponentFactory();
}

nts::Circuit::~Circuit()
{

}

void		nts::Circuit::invertClocks()
{
	for (const auto &element : this->_components) {
		if (element.second.get()->getType() == "clock") {
			if (dynamic_cast<nts::Clock *>(element.second.get()) != nullptr) {
				nts::Tristate state = dynamic_cast<nts::Clock *>(element.second.get())->getState();
				nts::Tristate value;
				if (state == nts::Tristate::XFALSE)
					value = nts::Tristate::XTRUE;
				else if (state == nts::Tristate::XTRUE)
					value = nts::Tristate::XFALSE;
				else
					value = nts::Tristate::XUNDEFINED;
				dynamic_cast<nts::Clock *>(element.second.get())->setState(value);
			}
		}
	}
}

void		nts::Circuit::simulate()
{
	for (const auto &element : this->_components) {
		if (element.second.get()->getType() == "output") {
			_outputs[element.first] = element.second.get()->compute();
		}
	}
	this->invertClocks();
}

void nts::Circuit::setSortedOutputs()
{
	for (const auto &element : this->_outputs) {
		_sortedOutputs.push_back(element.first);
	}
	std::sort(_sortedOutputs.begin(), _sortedOutputs.end());
}

void		nts::Circuit::displayOutputs()
{
	for (const auto &name : this->_sortedOutputs) {
		if (_outputs[name] != nts::Tristate::XUNDEFINED)
			std::cout << name << "=" << _outputs[name] << std::endl;
		else
			std::cout << name << "=" << "U" << std::endl;
	}
}

void 		nts::Circuit::dumpComponents()
{
	for (const auto &element : this->_components) {
		std::cout << "Component [" << element.second.get()->getType() << "]" << std::endl;
		element.second.get()->dump();
	}
}

void		nts::Circuit::addComponent(const std::string &type, const std::string &name, const std::string &value)
{
	std::vector<std::string> handledComponents = {"output", "input", "true", "false",
						      "clock", "4001", "4011",
						      "4030", "4069", "4071", "4081"};
	if (std::find(handledComponents.begin(), handledComponents.end(), type) != handledComponents.end())
	{
		this->_components.emplace(name, std::move(std::unique_ptr<IComponent> (_factory->createComponent(type, value))));
		if (type == "output")
			this->_outputs.emplace(name, nts::Tristate::XFALSE);
	} else {
		throw ComponentError("Component type : [" + type + "] is unknown.");
	}
}

const std::unordered_map<std::string, std::unique_ptr<nts::IComponent>>	&nts::Circuit::getComponents() const {
	return _components;
}

nts::IComponent &nts::Circuit::getComponentByName(const std::string &name)
{
	if (_components.find(name) == _components.end()) {
		throw ComponentError("Component name: [" + name + "] is unknown");
	} else {
		return *this->_components[name].get();
	}
}
