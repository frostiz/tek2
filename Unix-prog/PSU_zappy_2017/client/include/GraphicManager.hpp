/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PSU_zappy_2017 file
*/

#ifndef PSU_ZAPPY_2017_GRAPHICMANAGER_HPP
#define PSU_ZAPPY_2017_GRAPHICMANAGER_HPP

#include <vector>
#include <SFML/Graphics/RectangleShape.hpp>
#include <map>
#include "AssetsManager.hpp"
#include "Core.hpp"
#include "GUI.hpp"

class Core;
class AssetsManager;
class GUI;

class GraphicManager {
	public:
	GraphicManager();
	~GraphicManager() = default;

	void	initialize(Core *);
	void	drawMap();
	void	drawGUI();
	void	showRessourcesOnTile(Tile *);
	void	showPlayerInfo(Player *);

	void		update();
	void 		updateSquareSize();
	float		&getSquareSize();
	GUI		*getGUI();

	sf::RectangleShape	createRectangle(const sf::Vector2f &, const sf::Vector2f &, sf::Texture *);

	template<typename T>
	void			drawElement(const std::vector<T> &, AssetsManager *);
	template<typename T>
	void			updateElementPosition(const std::vector<T> &, const float &, const float &);

	private:

	sf::RenderWindow	*_window;
	MapManager		*_mapManager;
	AssetsManager		*_assetsManager;

	float			_squareSize;

	GUI			*_gui;
};

#endif //PSU_ZAPPY_2017_GRAPHICMANAGER_HPP
