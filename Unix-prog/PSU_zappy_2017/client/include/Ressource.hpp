/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PSU_zappy_2017 file
*/

#ifndef PSU_ZAPPY_2017_STONE_HPP
#define PSU_ZAPPY_2017_STONE_HPP

#include <iostream>
#include <SFML/Graphics/Texture.hpp>
#include "Element.hpp"

class Ressource : public Element {
	public:
	Ressource(Ressource *);
	Ressource(const size_t &, const int &, const int &quantity = 0);
	~Ressource() = default;

	int		&getQuantity();
	void		setQuantity(const int &);
	std::string	&getType();
	sf::Texture	*getTexture(AssetsManager *) override ;
	size_t		&getIndex();

	void		setIndex(const size_t &);

	protected:
	size_t				_index;
	std::vector<std::string>	_types;
	std::vector<int>		_textures;
	std::string			_type;
	int				_quantity;
};

#endif //PSU_ZAPPY_2017_STONE_HPP
