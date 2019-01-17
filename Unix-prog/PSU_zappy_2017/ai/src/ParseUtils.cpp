/*
** EPITECH PROJECT, 2018
** ParseUtils.cpp
** File description:
** My IRC GUI
*/

#include <sstream>
#include "ParseUtils.hpp"

ParseUtils::ParseUtils() {}

ParseUtils::~ParseUtils() {}

std::vector<std::string> ParseUtils::split(std::string line, char delim) {
	std::vector<std::string> vector;
	std::istringstream ss(line);
	std::string s;
	while (getline(ss, s, delim))
		vector.push_back(s);
	return (vector);
}

std::string ParseUtils::epur(std::string s) {
	bool space = false;
	auto p = s.begin();
	for (char ch : s)
		if (std::isspace(ch)) {
			space = p != s.begin();
		} else {
			if (space) *p++ = ' ';
				*p++ = ch;
			space = false; 
		}
	s.erase(p, s.end());
	return (s);
}

std::vector<std::string> ParseUtils::removeFirst(std::vector<std::string> vector) {
	vector.erase(vector.begin());
	return vector;
}