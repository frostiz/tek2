/*
** EPITECH PROJECT, 2018
** ParseUtils.hpp
** File description:
** Zappy
*/

#include <string>
#include <vector>

class ParseUtils {
	public:
		ParseUtils();
		~ParseUtils();
		std::vector<std::string> split(std::string, char);
		std::string epur(std::string);
		std::vector<std::string> removeFirst(std::vector<std::string>);
};