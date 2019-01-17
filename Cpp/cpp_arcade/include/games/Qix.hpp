/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** cpp_arcade file
*/

#ifndef CPP_ARCADE_QIX_HPP
#define CPP_ARCADE_QIX_HPP

#include <map>
#include <vector>
#include <chrono>
#include "Arcade.hpp"
#include "interfaces/IGame.hpp"

namespace ar {
	class Qix : public IGame{
		public:
		Qix();

		~Qix() = default;

		typedef enum	e_type
		{
			FLOOR = 2,
			CAPTURED_FLOOR = 3,
			WALL = 4,
			UNWALKABLE_WALL = 5,
			BODY = 6,
			SPARK = 7,
			TRAIL = 8,
			MONSTER = 9
		}		type_e;

		/**
		 * modify the state of the game depending on the key send
		 * @param key key received with getEvent of the graphical interface
		 */
		void manageKey(const Event &key) override;

		/**
		 * @return the vector of sprites to set via initSprites in the graphical interface
		 */
		const std::map<unsigned char, spriteCoords> &getSprites() const override; //dans games, à l'initialisation

		/**
		 * @return the path to the spriteSheet
		 */
		const std::string getSpritesPath() const override ;

		/**
		 * @return the vector of colors to set via initColors in the graphical interface
		 */
		const std::map<unsigned char, colorVector> &getColors() const;

		/**
		 * @return the actual score of the game
		 */
		int refreshScore() override;

		/**
		 * @return the actual timer of the game
		 */
		int refreshTimer() override;

		/**
		 * check the state of the game
		 * @return true if the game is over, false otherwise
		 */
		bool isGameOver() override;

		/**
		 * get the map
		 * @return map
		 */
		Map &getMap() override;

		/**
		 * refresh the game (a timer should be used for the refresh rate)
		 */
		void loop() override;

		/**
		 * @return a string containing the name of the game
		 */
		const std::string getGameName() const override ;

		/**
		 * forces the pause in the game
		 */
		void setPause() override;

		//FOR QIX ONLY
		enum e_direction {
			NORTH = 1,
			EAST = 2,
			SOUTH = 3,
			WEST = 4
		};

		unsigned long long tickMove() const;
		void resetTick();
		void showMonster();
		void hideMonster();
		std::vector<std::pair<int, int>> getNewMonsterPos();
		void colorMap();
		int checkAround(const int &, const int &, const ar::Event &);
		int displayMonster(const std::vector<std::pair<int, int>> &);
		void checkBlockedWall();
		void checkEnd();
		void moveSparks();
		void randomSparkPos(const e_direction &, int &, int &, const int &);
		bool isTrail(const int &, const int &) const;
		void retrieveWalkable(int &, int &, const int &);
		int checkSparkOnBody();
		void killBody();
		int checkKey(int &, int &);
		void retrievedWall();
		void loopBody();
		void fillMap(Map &, int, int);
		void changeDirFromNorthSouth(int &, int &, const int &);
		void changeDirFromEastWest(int &, int &, const int &);
		int searchWall(int &, int &, const int &);
		void defaultMove(int &, int &, const int &);
		void useLastDir(int &, int &, const int &);
		void followTrail(int &, int &, const int &);
		void initSprites();
		void initColors();
		void initMonster();

		private:
		ar::Map _map = ar::Map(30, 30);
		ar::Map _copymap = ar::Map(30, 30);
		std::chrono::time_point<std::chrono::system_clock> _timer;
		std::chrono::time_point<std::chrono::system_clock> _startTime;
		bool	_pause;
		int	_score;
		bool	_gameOver;
		int 	_posx;
		int	_posy;
		int _firstTimer;
		int _actualTimer;
		bool _firstPause;
		int _savePause;
		ar::Event _key;
		std::vector<std::pair<int, int>> _posMonster;
		std::map<unsigned char, ar::spriteCoords> _sprites;
		std::map<unsigned char, ar::colorVector> _colors;
		unsigned long long _monsterSpeed;
		std::pair<int, int> _savePos;
		std::vector<std::pair<int, int>> _trailPos;
		int _lives;
		bool _loose;
		std::vector<std::pair<int, int>> _sparks;
		std::vector<int> _sparksDir;
	};
};

#endif //CPP_ARCADE_Qix_HP