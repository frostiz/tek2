//
// EPITECH PROJECT, 2018
// ParseLibs.hpp
// File description:
// ParseLibs
//

#ifndef CPP_ARCADE_PARSELIBS_HPP
#define CPP_ARCADE_PARSELIBS_HPP

#include <iostream>
#include <vector>
#include <regex>

class ParseLibs
{
	public:
	static std::vector<std::string> getGames();
	static std::vector<std::string> getGraphs();
	static std::vector<std::string> GetName(std::vector<std::string> &libs);

	private:
	static std::vector<std::string> getFiles(const char *);
};

#endif //CPP_ARCADE_PARSELIBS_HPP
