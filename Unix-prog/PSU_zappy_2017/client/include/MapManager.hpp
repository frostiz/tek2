/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PSU_zappy_2017 file
*/

#ifndef PSU_ZAPPY_2017_MAPMANAGER_HPP
#define PSU_ZAPPY_2017_MAPMANAGER_HPP

#include <vector>
#include "Tile.hpp"
#include "Player.hpp"
#include "Egg.hpp"
#include "Ressource.hpp"
#include "Core.hpp"

class Core;

class MapManager {
	public:
	MapManager();
	~MapManager() = default;

	void	initialize(const int &, const int &, sf::RenderWindow *);

	int			&getWidth();
	int			&getHeight();

	Tile			*getTileAtPos(const int &, const int &);

	std::vector<Tile *>		&getTiles();
	std::vector<Player *>		&getPlayers();
	std::vector<Egg *>		&getEggs();

	private:
	int	_width;
	int	_height;
	float	_guiHeight;

	std::vector<Tile *>		_tiles;
	std::vector<Player *>		_players;
	std::vector<Egg *>		_eggs;

	sf::RenderWindow		*_window;
};

#endif //PSU_ZAPPY_2017_MAPMANAGER_HPP
