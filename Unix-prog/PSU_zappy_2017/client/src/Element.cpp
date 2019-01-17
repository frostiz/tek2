/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PSU_zappy_2017 file
*/

#include "Element.hpp"

Element::Element()
{
	this->_pos = {0, 0};
	this->_displayPos = {0, 0};
	this->_texture = nullptr;
	this->_display = true;
	this->_isSubSquare = false;
	this->_sub = 0;
}

sf::Vector2i &Element::getPosition()
{
	return this->_pos;
}

sf::RectangleShape &Element::getRectangle()
{
	return this->_rectangle;
}

sf::Vector2f &Element::getSize()
{
	return this->_size;
}

void Element::setPosition(const sf::Vector2i &pos)
{
	this->_pos = pos;
}

void Element::setTexture(sf::Texture *texture)
{
	this->_texture = texture;
}

void Element::setRectangle(const sf::RectangleShape &rectangle)
{
	this->_rectangle = rectangle;
}

void Element::setSize(const sf::Vector2f &size)
{
	this->_size = size;
}

void Element::draw(sf::RenderWindow *window)
{
	window->draw(this->_rectangle);
}

sf::Vector2i &Element::getDisplayPosition()
{
	return this->_displayPos;
}

void Element::setDisplayPosition(const sf::Vector2i &displayPos)
{
	this->_displayPos = displayPos;
}

bool &Element::getDisplay()
{
	return this->_display;
}

bool &Element::isSubSquare()
{
	return this->_isSubSquare;
}

int &Element::getSub()
{
	return this->_sub;
}

sf::Vector2i Element::getSubSquare()
{
	switch (this->_sub) {
	case (0):
		return {0, 0};
	case (1):
		return {1, 0};
	case (2):
		return {0, 1};
	case (3):
		return {1, 1};
	default:
		return {0, 0};
	}
}

void Element::setDisplay(const bool &display)
{
	this->_display = display;
}
