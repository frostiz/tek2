/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** cpp_nanotekspice file
*/

#ifndef CPP_NANOTEKSPICE_PARSER_HPP
#define CPP_NANOTEKSPICE_PARSER_HPP

#include <iostream>
#include "Circuit.hpp"

class Parser {
	public:
	Parser(const std::string &path, nts::Circuit *circuit, char **args);
	~Parser();

	// Member functions
	void				parse();
	std::string 			trim(const std::string &) const;
	std::string			deleteComment(const std::string &) const;
	void				processLine(std::string &, nts::Tristate &);
	void				processChipset(const std::string &);
	void				processLinks(const std::string &);
	void				changePart(const std::string &, nts::Tristate &);
	void				processSection(const std::string &, const nts::Tristate &);
	void				setInputValue(const std::string &, std::string &, const std::string &);
	std::string			getChipsetType(const std::string &) const;
	std::string			getChipsetName(const std::string &) const;
	std::string			getChipsetValue(const std::string &) const;
	void				checkOutputsLink() const;
	std::string			getFirstName(const std::string &) const;
	std::string			getOtherName(const std::string &) const;
	std::string			getFirstPin(const std::string &) const;
	std::string			getOtherPin(const std::string &) const;

	private:
	nts::Circuit 	*_circuit;
	std::string	_path;
	char		**_args;
};


#endif //CPP_NANOTEKSPICE_PARSER_HPP
