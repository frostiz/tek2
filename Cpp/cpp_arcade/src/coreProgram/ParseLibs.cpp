//
// EPITECH PROJECT, 2018
// ParseLibs.cpp
// File description:
// ParseLibs
//

#include <dirent.h>
#include <functional>
#include <vector>
#include "ArcadeException.hpp"
#include "coreProgram/ParseLibs.hpp"

std::vector<std::string> ParseLibs::getGames()
{
	return getFiles("./games");
}

std::vector<std::string> ParseLibs::getGraphs()
{
	return getFiles("./lib");
}

std::vector<std::string> ParseLibs::getFiles(const char *path)
{
	std::vector<std::string> dynamicsFiles;
	DIR *dir;
	struct dirent *files;
	std::regex filesPattern{"lib_arcade_([[:alpha:]]+).so"};

	dir = opendir(path);
	if (dir == NULL) {
		closedir(dir);
		std::string err(path);
		throw NoDirectoryException("./lib or ./games doesn't exit");
	}
	files = readdir(dir);
	while (files != NULL) {
		if (std::regex_match(files->d_name, filesPattern)) {
			dynamicsFiles.push_back(files->d_name);
		}
		files = readdir(dir);
	}
	closedir(dir);
	return dynamicsFiles;
}

std::vector<std::string> ParseLibs::GetName(std::vector<std::string> &libs)
{
	std::vector<std::string> names;
	std::regex filesPattern{"lib_arcade_|.so"};

	for (const auto &it : libs) {
		names.push_back(
			std::regex_replace(it, filesPattern, ""));
	}
	return names;
}
