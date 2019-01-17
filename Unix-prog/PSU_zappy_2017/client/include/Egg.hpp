/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PSU_zappy_2017 file
*/

#ifndef PSU_ZAPPY_2017_EGG_HPP
#define PSU_ZAPPY_2017_EGG_HPP

#include "Element.hpp"

class Egg : public Element {
	public:
	Egg(const int &, const int &);
	~Egg() = default;

	sf::Texture	*getTexture(AssetsManager *) override;
	int		&getPlayerNumber();
	int		&getEggNumber();

	enum eStatus {
		EGG_LAYED = 0,
		EGG_HATCHING
	};

	void		setStatus(eStatus);

	private:
	int		_playerNumber;
	int		_eggNumber;
	eStatus		_status;
};

#endif //PSU_ZAPPY_2017_EGG_HPP
