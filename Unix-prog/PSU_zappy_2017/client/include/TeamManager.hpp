/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PSU_zappy_2017 file
*/

#ifndef PSU_ZAPPY_2017_TEAMMANAGER_HPP
#define PSU_ZAPPY_2017_TEAMMANAGER_HPP

#include <iostream>
#include <vector>

class TeamManager {
	public:
	TeamManager();
	~TeamManager() = default;

	void	addTeam(const std::string &);
	void 	delTeam(const std::string &);

	std::vector<std::string> 	&getTeams();

	private:
	std::vector<std::string>	_teams;
};

#endif //PSU_ZAPPY_2017_TEAMMANAGER_HPP
