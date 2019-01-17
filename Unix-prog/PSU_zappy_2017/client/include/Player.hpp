/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PSU_zappy_2017 file
*/

#ifndef PSU_ZAPPY_2017_PLAYER_HPP
#define PSU_ZAPPY_2017_PLAYER_HPP

#include <iostream>
#include <SFML/System.hpp>
#include "Element.hpp"
#include "AssetsManager.hpp"

class Player : public Element {
	public:
	Player(Player *);
	Player(const int &, const int &, const int &, const std::string &);
	~Player() = default;

	int		&getPlayerNumber();
	std::string	&getTeam();
	int		&getLevel();
	int		&getOrientation();

	void		setOrientation(const int &);
	void		setLevel(const int &);

	void 		setNbFood(const int &);
	void 		setNbLinemate(const int &);
	void 		setNbDeraumere(const int &);
	void 		setNbSibur(const int &);
	void 		setNbMendiane(const int &);
	void 		setNbPhiras(const int &);
	void 		setNbThystame(const int &);

	void		setStatus(const int &);

	sf::Texture	*getTexture(AssetsManager *) override;

	int 		&getNbFood();
	int 		&getNbLinemate();
	int 		&getNbDeraumere();
	int 		&getNbSibur();
	int 		&getNbMendiane();
	int 		&getNbPhiras();
	int 		&getNbThystame();

	enum {
		PLAYER_ORIENTATION_NORTH = 1,
		PLAYER_ORIENTATION_EAST,
		PLAYER_ORIENTATION_SOUTH,
		PLAYER_ORIENTATION_WEST
	};

	enum {
		PLAYER_STATUS_NORMAL = 0,
		PLAYER_STATUS_INCANTING
	};

	private:
	int		_playerNumber;
	int		_orientation;
	int		_level;
	std::string	_team;

	int		_status;

	int		_nbFood;
	int		_nbLinemate;
	int		_nbDeraumere;
	int		_nbSibur;
	int		_nbMendiane;
	int		_nbPhiras;
	int		_nbThystame;
};

#endif //PSU_ZAPPY_2017_PLAYER_HPP
