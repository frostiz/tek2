/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PSU_zappy_2017 file
*/

#ifndef PSU_ZAPPY_2017_TILE_HPP
#define PSU_ZAPPY_2017_TILE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <unordered_map>
#include "Ressource.hpp"

class Tile : public Element {
	public:
	Tile(const sf::Vector2i &);
	~Tile() = default;

	std::vector<Ressource *>		&getRessources();

	sf::Texture				*getTexture(AssetsManager *) override;

	private:
	std::vector<Ressource *>		_ressources;
};

#endif //PSU_ZAPPY_2017_TILE_HPP
