/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** cpp_nanotekspice file
*/

#include <fstream>
#include <algorithm>
#include "Parser.hpp"

Parser::Parser(const std::string &path, nts::Circuit *circuit, char **args)
{
	_path = path;
	_circuit = circuit;
	_args = args;
}

Parser::~Parser()
{

}

void 		Parser::parse()
{
	std::ifstream	data(this->_path);
	std::string	line;
	nts::Tristate	part = nts::Tristate::XUNDEFINED;

	if (data) {
		while(getline(data, line)) {
			this->processLine(line, part);
		}
		if (part == nts::Tristate::XUNDEFINED) {
			throw FileError("Missing [.chipsets:] or [.links:] sections");
		}
		this->checkOutputsLink();
	} else {
		throw FileError("Requested file ["+ this->_path + "] does not exist.");
	}
}

void		Parser::processLine(std::string &line, nts::Tristate &part) {
	line = this->trim(line);
	line = this->deleteComment(line);
	std::replace(line.begin(), line.end(), '\t', ' ');
	if (line == ".chipsets:" || line == ".links:") {
		this->changePart(line, part);
	}
	else if (part == nts::Tristate::XTRUE || part == nts::Tristate::XFALSE)
		this->processSection(line, part);
}

void		Parser::changePart(const std::string &line, nts::Tristate &part) {
	if (line == ".chipsets:")
		part = nts::Tristate::XTRUE;
	else
		part = nts::Tristate::XFALSE;
}

void		Parser::processSection(const std::string &line, const nts::Tristate &part) {
	if (part == nts::Tristate::XTRUE)
		this->processChipset(line);
	else
		this->processLinks(line);
}

void		Parser::processChipset(const std::string &line) {
	std::string type;
	std::string name;
	std::string value;

	if (line.empty())
		return (void)-1;
	type = this->getChipsetType(line);
	name = this->getChipsetName(line);
	value = this->getChipsetValue(line);
	if (type == "input" || type == "clock")
		this->setInputValue(name, value, type);
	if (_circuit->getComponents().count(name) > 0)
		throw ComponentError("Several components share the same name: [" + name + "]");
	if (!type.empty() || !name.empty())
		_circuit->addComponent(type, name, value);
}

std::string 	Parser::getChipsetType(const std::string &line) const {
	size_t firstEnd = line.find_first_of(' ');
	std::string type = (firstEnd != std::string::npos) ? line.substr(0, firstEnd) : line;

	return type;
}

std::string	Parser::getChipsetName(const std::string &line) const {
	size_t secondEnd = line.find_last_of(' ');
	std::string name = (secondEnd != std::string::npos) ? line.substr(secondEnd + 1) : line;

	return name;
}

std::string	Parser::getChipsetValue(const std::string &line) const {
	size_t thirdEnd = line.find_first_of('(');
	size_t fourthEnd = line.find_first_of(')');
	std::string value = (thirdEnd != std::string::npos) ? line.substr(thirdEnd + 1, fourthEnd - 1) : "";

	return value;
}

void		Parser::setInputValue(const std::string &name, std::string &value, const std::string &type) {
	bool found = false;
	for (int i = 0; this->_args[i] != NULL; i++) {
		std::string arg = this->_args[i];
		if (arg.substr(0, arg.find_first_of('=')) == name) {
			value = arg.substr(arg.find_first_of('=') + 1);
			found = true;
		}
	}
	if (!found) {
		throw ComponentError("chipset [" + name + "] of type [" + type + "] value was not provided on the command line.");
	}
}

void		Parser::processLinks(const std::string &line) {
	if (line.empty())
		return (void)-1;
	std::string	firstName = this->getFirstName(line);
	std::string	otherName = this->getOtherName(line);
	std::string	firstPin = this->getFirstPin(line);
	std::string	otherPin = this->getOtherPin(line);

	/*std::cout << "ICI : " << firstName << std::endl;
	std::cout << firstPin << std::endl;
	std::cout << otherName << std::endl;
	std::cout << otherPin << std::endl;*/
	nts::IComponent &tmp = _circuit->getComponentByName(firstName);
	nts::IComponent &other = _circuit->getComponentByName(otherName);

	tmp.setLink(std::stoul(firstPin), other, std::stoul(otherPin));
	other.setLink(std::stoul(otherPin), tmp, std::stoul(firstPin));
}

std::string	Parser::getFirstPin(const std::string &line) const {
	size_t 		firstEnd = line.find_first_of(' ');
	std::string	first = (firstEnd != std::string::npos) ? line.substr(0, firstEnd) : line;
	firstEnd = first.find_last_of(':');
	std::string	firstPin = (firstEnd != std::string::npos) ? first.substr(firstEnd + 1) : first;

	return firstPin;
}

std::string	Parser::getOtherPin(const std::string &line) const {
	size_t		secondEnd = line.find_last_of(' ');
	std::string	second = (secondEnd != std::string::npos) ? line.substr(secondEnd + 1) : line;
	secondEnd = second.find_last_of(':');
	std::string	secondPin = (secondEnd != std::string::npos) ? second.substr(secondEnd + 1) : second;

	return secondPin;
}

std::string	Parser::getFirstName(const std::string &line) const {
	size_t 		firstEnd = line.find_first_of(' ');
	std::string	first = (firstEnd != std::string::npos) ? line.substr(0, firstEnd) : line;
	firstEnd = first.find_last_of(':');
	std::string 	firstName = (firstEnd != std::string::npos) ? first.substr(0, firstEnd) : first;

	return firstName;
}

std::string	Parser::getOtherName(const std::string &line) const {
	size_t		secondEnd = line.find_last_of(' ');
	std::string	second = (secondEnd != std::string::npos) ? line.substr(secondEnd + 1) : line;
	secondEnd = second.find_last_of(':');
	std::string	secondName = (secondEnd != std::string::npos) ? second.substr(0, secondEnd) : second;

	return secondName;
}

void		Parser::checkOutputsLink() const {
	for (const auto &element : _circuit->getComponents()) {
		if (element.second.get()->getType() == "output") {
			if (dynamic_cast<nts::Output *>(element.second.get()) != nullptr) {
				if (!dynamic_cast<nts::Output *>(element.second.get())->isLinked()) {
					throw ComponentError("Output [" + element.first + "] is not linked.");
				}
			}
		}
	}
}

std::string 	Parser::trim(const std::string &str) const
{
	size_t first = str.find_first_not_of(' ');
	if (std::string::npos == first)
	{
		return str;
	}
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}

std::string 	Parser::deleteComment(const std::string &str) const
{
	return str.substr(0, str.find('#'));
}