/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PSU_zappy_2017 file
*/

#include <SFML/Graphics/RectangleShape.hpp>
#include "MouseManager.hpp"

MouseManager::MouseManager(const sf::RenderWindow *window, const int &mouseWidth, const int &mouseHeight)
{
	this->_window = window;
	this->_mouseBox.width = mouseWidth;
	this->_mouseBox.height = mouseHeight;
}

sf::Vector2i MouseManager::getPosition(const sf::RenderWindow *relativeTo)
{
	return sf::Mouse::getPosition(*relativeTo);
}

bool MouseManager::intersects(sf::RectangleShape &otherBox)
{
	this->_mouseBox.left = sf::Mouse::getPosition(*this->_window).x;
	this->_mouseBox.top = sf::Mouse::getPosition(*this->_window).y;

	return this->_mouseBox.intersects(otherBox.getGlobalBounds());
}
