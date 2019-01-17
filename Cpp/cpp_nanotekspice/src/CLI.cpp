/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** cpp_nanotekspice file
*/

#include <stdlib.h>
#include "CLI.hpp"
#include <thread>

CLI::CLI(nts::Circuit *circuit)
	: _circuit(circuit),
	_actions(
	{
		{"exit", [this]() { this->my_exit(); }},
		{"display", [this]() { this->display(); }},
		{"simulate", [this]() { this->simulate(); }},
		{"loop", [this]() { this->loop(); }},
		{"dump", [this]() { this->dump(); }}
	}
)
{

}

CLI::~CLI()
{

}

void	CLI::changeInputValue(const std::string &s)
{
	bool		changed = false;
	std::string	name = s.substr(0, s.find_first_of('='));
	std::string 	value_str = s.substr(s.find_first_of('=') + 1, s.npos);
	nts::Tristate	value = nts::Tristate::XUNDEFINED;

	if (value_str == "0")
		value = nts::Tristate::XFALSE;
	else if (value_str == "1")
		value = nts::Tristate::XTRUE;
	else if (value_str == "-1")
		value = nts::Tristate::XUNDEFINED;
	else {
		std::cout << "Value [" << value_str << "] is incorrect. It must be -1, 0 or 1." << std::endl;
		return (void)-1;
	}
	if (_circuit->getComponents().find(name) != _circuit->getComponents().end()) {
		if (_circuit->getComponentByName(name).getType() == "input") {
			if (dynamic_cast<nts::Input *>(&_circuit->getComponentByName(name)) != nullptr) {
				changed = true;
				dynamic_cast<nts::Input *>(&_circuit->getComponentByName(name))->setState(value);
			}
		}
	}
	if (!changed) {
		std::cout << "Input [" << name << "] doesnt exist." << std::endl;
	}
}

void	CLI::read()
{
	std::string s("42");
	while (!s.empty()) {
		std::cout << "> ";
		std::getline(std::cin, s);
		if (s.empty())
			return (void)-1;
		else if (_actions.find(s) != _actions.end())
			_actions[s]();
		else if (s.find('=') != s.npos) {
			this->changeInputValue(s);
		} else {
			std::cout << "Command not found." << std::endl;
		}
	}
}

void CLI::my_exit() {
	exit(0);
}

void CLI::display() {
	_circuit->displayOutputs();
}

void CLI::simulate() {
	_circuit->simulate();
}

void CLI::loop() {
	while (1) {
		_circuit->simulate();
		_circuit->displayOutputs();
		std::this_thread::sleep_for (std::chrono::seconds(1));
	}
}

void CLI::dump() {
	_circuit->dumpComponents();
}
