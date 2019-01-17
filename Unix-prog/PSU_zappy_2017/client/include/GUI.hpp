/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PSU_zappy_2017 file
*/

#ifndef PSU_ZAPPY_2017_GUI_HPP
#define PSU_ZAPPY_2017_GUI_HPP

#include "Tile.hpp"
#include "Ressource.hpp"
#include "Player.hpp"
#include "Core.hpp"

class GraphicManager;

class GUI {
	public:
	GUI(const int &, Core *);
	~GUI() = default;

	void	setTile(Tile *);
	Tile	*getTile() const;

	void	setPlayer(Player *);
	Player	*getPlayer() const;

	void	updatePosition();
	sf::Text	*createText(const std::string &);

	int				&getHeight();
	std::vector<Ressource *>	&getRessources();
	sf::Vector2i			&getIndex();
	std::vector<sf::Text *>		&getTexts();
	std::vector<sf::Text *>		&getPlayerTexts();

	private:
	//int				_displayIndex;
	sf::Vector2f			_displayIndex;

	Tile				*_tile;
	Player				*_player;

	int				_height;
	sf::Vector2i			_index;


	std::vector<Ressource *>	_ressources;
	std::vector<sf::Text *>		_texts;
	std::vector<sf::Text *>		_playerTexts;
	std::map<std::string, int>	_ressourceIndexes;

	sf::RenderWindow		*_window;
	AssetsManager			*_assetsManager;
	GraphicManager			*_graphicManager;
	MapManager			*_mapManager;
};

#endif //PSU_ZAPPY_2017_GUI_HPP
