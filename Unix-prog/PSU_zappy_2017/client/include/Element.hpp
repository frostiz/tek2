/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PSU_zappy_2017 file
*/

#ifndef PSU_ZAPPY_2017_ELEMENT_HPP
#define PSU_ZAPPY_2017_ELEMENT_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "AssetsManager.hpp"

class Element {
	public:
	Element();
	virtual ~Element() = default;

	sf::Vector2i		&getPosition();
	sf::Vector2i		&getDisplayPosition();
	virtual sf::Texture	*getTexture(AssetsManager *) = 0;
	sf::RectangleShape	&getRectangle();
	sf::Vector2f		&getSize();
	bool			&getDisplay();
	bool			&isSubSquare();
	int			&getSub();
	sf::Vector2i 		getSubSquare();

	void			setPosition(const sf::Vector2i &);
	void			setDisplayPosition(const sf::Vector2i &);
	void			setTexture(sf::Texture *);
	void			setRectangle(const sf::RectangleShape &);
	void			setSize(const sf::Vector2f &);
	void			setDisplay(const bool &);

	void			draw(sf::RenderWindow *);

	protected:

	sf::Vector2f		_size;
	sf::Vector2i		_pos;
	sf::Vector2i		_displayPos;
	sf::Texture		*_texture;
	sf::RectangleShape	_rectangle;

	bool			_display;
	bool			_isSubSquare;
	int			_sub;

};

#endif //PSU_ZAPPY_2017_ELEMENT_HPP
