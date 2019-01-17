/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PSU_zappy_2017 file
*/

#ifndef PSU_ZAPPY_2017_MOUSE_HPP
#define PSU_ZAPPY_2017_MOUSE_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Mouse.hpp>

class MouseManager
{
	public:
	MouseManager(const sf::RenderWindow *, const int &, const int &);

	sf::Vector2i getPosition(const sf::RenderWindow *);
	bool intersects(sf::RectangleShape &);

	private:
	const sf::RenderWindow	*_window;
	sf::FloatRect		_mouseBox;
};

#endif //PSU_ZAPPY_2017_MOUSE_HPP
