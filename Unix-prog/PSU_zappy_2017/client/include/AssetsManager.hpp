/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PSU_zappy_2017 file
*/

#ifndef PSU_ZAPPY_2017_ASSETSMANAGER_HPP
#define PSU_ZAPPY_2017_ASSETSMANAGER_HPP

#include <map>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

class AssetsManager {
	public:
	AssetsManager();
	~AssetsManager() = default;

	enum eAssetsTexture {
		ASSETS_TEXTURE_NONE = 0,
		ASSETS_TEXTURE_FLOOR,
		ASSETS_TEXTURE_FOOD,
		ASSETS_TEXTURE_LINEMATE,
		ASSETS_TEXTURE_DERAUMERE,
		ASSETS_TEXTURE_SIBUR,
		ASSETS_TEXTURE_MENDIANE,
		ASSETS_TEXTURE_PHIRAS,
		ASSETS_TEXTURE_THYSTAME,
		ASSETS_TEXTURE_EGG_HATCHING,
		ASSETS_TEXTURE_EGG_LAYED,
		ASSETS_TEXTURE_PLAYER_NORTH,
		ASSETS_TEXTURE_PLAYER_EAST,
		ASSETS_TEXTURE_PLAYER_SOUTH,
		ASSETS_TEXTURE_PLAYER_WEST,
		ASSETS_TEXTURE_PLAYER_INCANTING
	};

	enum eAssetsFont {
		ASSETS_FONT_GUI_COUNT = 0
	};

	void		initialize();
	sf::Texture	*loadTexture(const std::string &);
	sf::Texture	*getTexture(eAssetsTexture);

	sf::Font	*loadFont(const std::string &);
	sf::Font	*getFont(eAssetsFont);

	private:
	std::map<eAssetsTexture, sf::Texture *>	_textures;
	std::map<eAssetsFont, sf::Font *>	_fonts;
};

#endif //PSU_ZAPPY_2017_ASSETSMANAGER_HPP
