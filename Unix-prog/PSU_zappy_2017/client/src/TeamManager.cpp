/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PSU_zappy_2017 file
*/

#include <algorithm>
#include "TeamManager.hpp"

TeamManager::TeamManager()
{
}

void TeamManager::addTeam(const std::string &teamName)
{
	_teams.push_back(teamName);
}

void TeamManager::delTeam(const std::string &teamName)
{
	auto it = std::find(_teams.begin(), _teams.end(), teamName.c_str());

	if (it != _teams.end()) {
		_teams.erase(it);
	}
}

std::vector<std::string> &TeamManager::getTeams()
{
	return _teams;
}
