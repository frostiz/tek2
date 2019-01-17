/*
** EPITECH PROJECT, 2018
** CommandReturn.hpp
** File description:
** Zappy
*/

#ifndef COMMANDRETURN_HPP_
# define COMMANDRETURN_HPP_

#include <vector>
#include <string>

class CommandReturn {
	public:
		CommandReturn();
		~CommandReturn();
		std::vector<std::string> getIndexAt(const size_t &);
		std::vector<std::vector<std::string> > getIndexes();
		void addIndex(std::vector<std::string>);

	private:
		std::vector<std::vector<std::string> > _indexes;

};

#endif // COMMANDRETURN_HPP_