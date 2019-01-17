//
// EPITECH PROJECT, 2018
// Snake.hpp
// File description:
// Snake.hpp
//

#ifndef CPP_ARCADE_Snake_HPP
# define CPP_ARCADE_Snake_HPP

#include <map>
#include <vector>
#include <chrono>
#include "Arcade.hpp"
#include "interfaces/IGame.hpp"

namespace ar {
	class Snake : public IGame{
	public:
		typedef enum {
			FLOOR = 2,
			BODY_B = 3,
			BODY_TR = 4,
			BODY_TL = 5,
			HEAD_B = 6,
			VOID = 7,
			APPLE = 8,
			BODY_BL = 9,
			BODY_BR = 10,
			BODY_T = 11,
			HEAD_T = 12,
			WALL = 13,
		} snakeEnum;
		Snake();

		~Snake() = default;

		/**
		 * modify the state of the game depending on the key send
		 * @param key key received with getEvent of the graphical interface
		 */
		void manageKey(const Event &key) override;

		/**
		 * @return the vector of sprites to set via initSprites in the graphical interface
		 */
		const std::map<unsigned char, spriteCoords> &getSprites() const override;

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

		/* Pour le Snake */
		unsigned long long tickMove() const ;
		void resetTick();
		void newSeed();

		private:

		bool _alreadyUse = false;

		ar::Map _map = ar::Map(30, 30);
		std::vector<int>_BlockX;
		std::vector<int>_BlockY;
		ar::Event _key;
		ar::Event _saveKey;

		bool _gameOver;
		int _score;
		bool _pause;
		bool _firstPause;
		int _savePause;
		std::chrono::time_point<std::chrono::system_clock> _timer;

		std::chrono::time_point<std::chrono::system_clock> _startTime;

		int _firstTimer;
		int _actualTimer;


		std::map<unsigned char, ar::spriteCoords> _sprites;
		std::map<unsigned char, ar::colorVector> _colors;

		void getLastKey(ar::Event &);
		bool getUpAndDown(int _saveX, int _saveY, ar::Event);
		bool getLeftAndRight(int _saveX, int _saveY, ar::Event);
		void getFirstBody(int i);
		void getSecondBody(int i);
		void getThirdBody(int i);
		bool checkMap(int &, int&);
		void assignSpritesColors();
	};
};

#endif //CPP_ARCADE_Snake_HPP
