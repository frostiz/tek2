//
// EPITECH PROJECT, 2018
// Snake.cpp
// File description:
// Snake
//

#include <map>
#include <chrono>
#include <iostream>
#include <string>
#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <algorithm>
#include "games/Snake.hpp"

ar::Snake::Snake()
{
	_actualTimer = std::time(nullptr);
	_timer = std::chrono::system_clock::now();
	for (int i = 0; i < _map.getHeight() - 1; i++) {
		_map[i][0] = WALL;
		_map[i][_map.getHeight() - 1] = WALL;
	}
	for (int i = 0; i < _map.getWidth() - 1; i++) {
		_map[0][i] = WALL;
		_map[_map.getWidth() - 1][i] = WALL;
	}
	_map[_map.getHeight() - 1][_map.getWidth() - 1] = WALL;
	for (int i = 0; i < _map.getHeight() - 1; i++) {
		for (int j = 0; j < _map.getWidth() - 1; j++) {
			if (_map[i][j] == '\0') {
				_map[i][j] = FLOOR;
			}
		}
	}
	_pause = true;
	_map[15][15] = HEAD_T;
	_BlockX.push_back(15);
	_BlockY.push_back(15);
	_map[16][15] = BODY_T;
	_BlockX.push_back(15);
	_BlockY.push_back(16);
	_map[17][15] = BODY_T;
	_BlockX.push_back(15);
	_BlockY.push_back(17);
	_map[18][15] = BODY_T;
	_BlockX.push_back(15);
	_BlockY.push_back(18);
	_gameOver = false;
	_score = 0;
	_key = ar::AR_UP;
	_saveKey = AR_UP;
	std::srand(std::time(nullptr));
	newSeed();
	assignSpritesColors();
}

void ar::Snake::assignSpritesColors()
{
	_colors[static_cast<const unsigned char &>('0' - 48)] = {255, 255, 255}; // WHITE
	_colors[static_cast<const unsigned char &>('1' - 48)] = {0, 0, 0}; // BLACK
	_colors[static_cast<const unsigned char &>('2' - 48)] = {204, 255, 204}; // FLOOR
	_colors[static_cast<const unsigned char &>('3' - 48)] = {50, 173, 107}; // BODY UP
	_colors[static_cast<const unsigned char &>('4' - 48)] = {50, 173, 107}; // BODY TR
	_colors[static_cast<const unsigned char &>('5' - 48)] = {50, 173, 107}; // BODY TL
	_colors[static_cast<const unsigned char &>('6' - 48)] = {26, 145, 81}; // HEAD
	_colors[static_cast<const unsigned char &>('7' - 48)] = {255, 255, 255}; // VOID
	_colors[static_cast<const unsigned char &>('8' - 48)] = {204, 38, 38}; // APPLE
	_colors[static_cast<const unsigned char &>('9' - 48)] = {50, 173, 107}; // BODY BL
	_colors[static_cast<const unsigned char &>(':' - 48)] = {50, 173, 107}; // BODY BL
	_colors[static_cast<const unsigned char &>(';' - 48)] = {50, 173, 107}; // BODY T
	_colors[static_cast<const unsigned char &>('<' - 48)] = {26, 145, 81}; // HEAD
	_colors[static_cast<const unsigned char &>('=' - 48)] = {142, 103, 17}; // WALL

	_sprites[static_cast<const unsigned char &>('2' - 48)] = {0, 0, 64, 64}; // FLOOR
	_sprites[static_cast<const unsigned char &>('3' - 48)] = {64, 0, 64, 64}; // BODY UP
	_sprites[static_cast<const unsigned char &>('4' - 48)] = {128, 0, 64, 64}; // BODY TR
	_sprites[static_cast<const unsigned char &>('5' - 48)] = {192, 0, 64, 64}; // BODY TL
	_sprites[static_cast<const unsigned char &>('6' - 48)] = {256, 0, 64, 64}; // HEAD_B
	_sprites[static_cast<const unsigned char &>('7' - 48)] = {320, 0, 64, 64}; // VOID
	_sprites[static_cast<const unsigned char &>('8' - 48)] = {0, 64, 64, 64}; // APPLE
	_sprites[static_cast<const unsigned char &>('9' - 48)] = {64, 64, 64, 64}; // BODY BL
	_sprites[static_cast<const unsigned char &>(':' - 48)] = {128, 64, 64, 64}; // BODY BR
	_sprites[static_cast<const unsigned char &>(';' - 48)] = {192, 64, 64, 64}; // BODY T
	_sprites[static_cast<const unsigned char &>('<' - 48)] = {256, 64, 64, 64}; // HEAD_T
	_sprites[static_cast<const unsigned char &>('=' - 48)] = {320, 64, 64, 64}; // WALL
}

int ar::Snake::refreshScore()
{
	return _score;
}

int ar::Snake::refreshTimer()
{
	if (!_firstPause)
		return (0);
	return (_actualTimer- _firstTimer);
}

bool ar::Snake::isGameOver()
{
	return _gameOver;
}

ar::Map &ar::Snake::getMap()
{
	return _map;
}

void ar::Snake::getLastKey(ar::Event &alternateKey)
{
	if (_key == AR_RIGHT) {
		if (_saveKey == AR_UP) {
			alternateKey = AR_RIGHT;
		} else if (_saveKey == AR_RIGHT) {
			alternateKey = AR_DOWN;
		} else if (_saveKey == AR_DOWN) {
			alternateKey = AR_LEFT;
		} else if (_saveKey == AR_LEFT) {
			alternateKey = AR_UP;
		}
	} else if (_key == AR_LEFT) {
		if (_saveKey == AR_UP) {
			alternateKey = AR_LEFT;
		} else if (_saveKey == AR_RIGHT) {
			alternateKey = AR_UP;
		} else if (_saveKey == AR_DOWN) {
			alternateKey = AR_RIGHT;
		} else if (_saveKey == AR_LEFT) {
			alternateKey = AR_DOWN;
		}
	} else {
		alternateKey = _saveKey;
	}
}

bool ar::Snake::getLeftAndRight(int _saveX, int _saveY, ar::Event alternateKey)
{
	if (alternateKey == AR_LEFT) {
		if (_BlockX[0] - 1 < 0 ||
			_map[_BlockY[0]][_BlockX[0] - 1] == BODY_B ||
			_map[_BlockY[0]][_BlockX[0] - 1] == BODY_BL ||
			_map[_BlockY[0]][_BlockX[0] - 1] == BODY_BR ||
			_map[_BlockY[0]][_BlockX[0] - 1] == BODY_T ||
			_map[_BlockY[0]][_BlockX[0] - 1] == BODY_TL ||
			_map[_BlockY[0]][_BlockX[0] - 1] == BODY_TR ||
			_map[_BlockY[0]][_BlockX[0] - 1] == WALL) {
			_gameOver = true;
			return true;
		}
		_BlockY.insert(_BlockY.begin(), _saveY);
		_BlockX.insert(_BlockX.begin(), _saveX - 1);
	} else if (alternateKey == AR_RIGHT) {
		if (_BlockX[0] + 1 > _map.getWidth() - 1 ||
			_map[_BlockY[0]][_BlockX[0] + 1] == BODY_B ||
			_map[_BlockY[0]][_BlockX[0] + 1] == BODY_BL ||
			_map[_BlockY[0]][_BlockX[0] + 1] == BODY_BR ||
			_map[_BlockY[0]][_BlockX[0] + 1] == BODY_T ||
			_map[_BlockY[0]][_BlockX[0] + 1] == BODY_TL ||
			_map[_BlockY[0]][_BlockX[0] + 1] == BODY_TR ||
			_map[_BlockY[0]][_BlockX[0] + 1] == WALL) {
			_gameOver = true;
			return true;
		}
		_BlockY.insert(_BlockY.begin(), _saveY);
		_BlockX.insert(_BlockX.begin(), _saveX + 1);
	}
	return false;
}

bool ar::Snake::getUpAndDown(int _saveX, int _saveY, ar::Event alternateKey)
{
	if (alternateKey == AR_UP) {
		if (_BlockY[0] - 1 < 0 ||
			_map[_BlockY[0] - 1][_BlockX[0]] == BODY_B ||
			_map[_BlockY[0] - 1][_BlockX[0]] == BODY_BL ||
			_map[_BlockY[0] - 1][_BlockX[0]] == BODY_BR ||
			_map[_BlockY[0] - 1][_BlockX[0]] == BODY_T ||
			_map[_BlockY[0] - 1][_BlockX[0]] == BODY_TL ||
			_map[_BlockY[0] - 1][_BlockX[0]] == BODY_TR ||
			_map[_BlockY[0] - 1][_BlockX[0]] == WALL) {
			_gameOver = true;
			return true;
		}
		_BlockY.insert(_BlockY.begin(), _saveY - 1);
		_BlockX.insert(_BlockX.begin(), _saveX);
	} else if (alternateKey == AR_DOWN) {
		if (_BlockY[0] + 1 > _map.getHeight() - 1 ||
			_map[_BlockY[0] + 1][_BlockX[0]] == BODY_B ||
			_map[_BlockY[0] + 1][_BlockX[0]] == BODY_BL ||
			_map[_BlockY[0] + 1][_BlockX[0]] == BODY_BR ||
			_map[_BlockY[0] + 1][_BlockX[0]] == BODY_T ||
			_map[_BlockY[0] + 1][_BlockX[0]] == BODY_TL ||
			_map[_BlockY[0] + 1][_BlockX[0]] == BODY_TR ||
			_map[_BlockY[0] + 1][_BlockX[0]] == WALL) {
			_gameOver = true;
			return true;
		}
		_BlockY.insert(_BlockY.begin(), _saveY + 1);
		_BlockX.insert(_BlockX.begin(), _saveX);
	}
	return false;
}

void ar::Snake::getFirstBody(int i)
{
	if ((_BlockY[i] == _BlockY[i - 1] &&
		_BlockX[i] != _BlockX[i - 1]) &&
		(_BlockY[i] == _BlockY[i + 1] && _BlockX[i] !=
		_BlockX[i + 1]))
		_map[_BlockY[i]][_BlockX[i]] = BODY_B;
	else if ((_BlockY[i] != _BlockY[i - 1] &&
		_BlockX[i] == _BlockX[i - 1]) &&
		(_BlockY[i] != _BlockY[i + 1] && _BlockX[i] ==
			_BlockX[i + 1]))
		_map[_BlockY[i]][_BlockX[i]] = BODY_T;
	else if ((_BlockY[i] == _BlockY[i - 1] &&
		_BlockX[i] < _BlockX[i - 1] &&
		_BlockY[i] < _BlockY[i + 1] &&
		_BlockX[i] == _BlockX[i + 1]) ||
		((_BlockY[i] < _BlockY[i - 1] &&
		_BlockX[i] == _BlockX[i - 1]) &&
		(_BlockY[i] == _BlockY[i + 1] &&
		_BlockX[i] < _BlockX[i + 1])))
		_map[_BlockY[i]][_BlockX[i]] = BODY_BR;
}

void ar::Snake::getSecondBody(int i)
{
	if ((_BlockY[i] == _BlockY[i - 1] &&
		_BlockX[i] > _BlockX[i - 1] &&
		_BlockY[i] < _BlockY[i + 1] &&
		_BlockX[i] == _BlockX[i + 1]) ||
		(_BlockY[i] < _BlockY[i - 1] &&
		_BlockX[i] == _BlockX[i - 1] &&
		_BlockY[i] == _BlockY[i + 1] &&
		_BlockX[i] > _BlockX[i + 1]))
		_map[_BlockY[i]][_BlockX[i]] = BODY_BL;
	else if ((_BlockY[i] == _BlockY[i - 1] &&
		_BlockX[i] < _BlockX[i - 1] &&
		_BlockY[i] > _BlockY[i + 1] &&
		_BlockX[i] == _BlockX[i + 1]) ||
		(_BlockY[i] > _BlockY[i - 1] &&
		_BlockX[i] == _BlockX[i - 1] &&
		_BlockY[i] == _BlockY[i + 1] &&
		_BlockX[i] < _BlockX[i + 1]))
		_map[_BlockY[i]][_BlockX[i]] = BODY_TR;
}

void ar::Snake::getThirdBody(int i)
{
	if ((_BlockY[i] == _BlockY[i - 1] &&
		_BlockX[i] > _BlockX[i - 1] &&
		_BlockY[i] > _BlockY[i + 1] &&
		_BlockX[i] == _BlockX[i + 1]) ||
		(_BlockY[i] > _BlockY[i - 1] &&
		_BlockX[i] == _BlockX[i - 1] &&
		_BlockY[i] == _BlockY[i + 1] &&
		_BlockX[i] > _BlockX[i + 1]))
		_map[_BlockY[i]][_BlockX[i]] = BODY_TL;
}

void ar::Snake::loop()
{
	int eat = 0;
	int _saveX = _BlockX[0];
	int _saveY = _BlockY[0];

	if (tickMove() > 150 && !_pause) {
		_alreadyUse = true;
		ar::Event alternateKey;
		getLastKey(alternateKey);
		_key = ar::AR_UNKNOWN;
		_saveKey = alternateKey;
		if (getUpAndDown(_saveX, _saveY, alternateKey))
			return ;
		if (getLeftAndRight(_saveX, _saveY, alternateKey))
			return ;
		if (_map[_BlockY[0]][_BlockX[0]] == APPLE) {
			eat = 1;
			_score += 100;
			newSeed();
		}
		if (alternateKey == AR_UP || alternateKey == AR_DOWN)
			_map[_BlockY[0]][_BlockX[0]] = HEAD_T;
		else if (alternateKey == AR_LEFT || alternateKey == AR_RIGHT)
			_map[_BlockY[0]][_BlockX[0]] = HEAD_B;
		for (int i = 1; i < static_cast<int>(_BlockY.size() - 1); i++) {
			getFirstBody(i);
			getSecondBody(i);
			getThirdBody(i);
		}
		_map[_BlockY[_BlockY.size() - 1]][_BlockX[_BlockX.size() -
			1]] = FLOOR;
		if (eat == 0) {
			_BlockX.pop_back();
			_BlockY.pop_back();
		}
		if ((alternateKey == AR_UP || alternateKey == AR_DOWN ||
			alternateKey == AR_LEFT || alternateKey == AR_RIGHT))
			_saveKey = alternateKey;
		_map.setPlayerX(_BlockX[0]);
		_map.setPlayerY(_BlockY[0]);
		resetTick();
		_actualTimer = std::time(nullptr);
	}
}

void ar::Snake::setPause()
{
	_pause = !_pause;
	if (!_pause) {
		_firstTimer += (_savePause - _actualTimer);
	}
}

unsigned long long ar::Snake::tickMove() const
{
	return static_cast<unsigned long long int>
	(std::chrono::duration_cast<std::chrono::milliseconds>(
			std::chrono::system_clock::now() - _startTime).count());
}

void ar::Snake::resetTick()
{
	_startTime = std::chrono::system_clock::now();
}

bool ar::Snake::checkMap(int &posX, int &posY)
{
	int count = 0;

	for (int i = 0; i < _map.getHeight(); i++) {
		for (int j = 0; j < _map.getWidth(); j++) {
			if (_map[i][j] == FLOOR) {
				posX = j;
				posY = i;
				count++;
			}
		}
	}
	if (count < 30)
		return false;
	return true;
}

void ar::Snake::newSeed()
{
	int i;
	int j;

	if (!checkMap(i, j)) {
		_map[i][j] = APPLE;
		return;
	}
	i = std::rand() % (_map.getHeight() - 2) + 1;
	j = std::rand() % (_map.getWidth() - 2) + 1;
	if (_map[i][j] != HEAD_B && _map[i][j] != HEAD_T &&
		_map[i][j] != BODY_BL && _map[i][j] != BODY_B &&
		_map[i][j] != BODY_TR && _map[i][j] != BODY_T &&
		_map[i][j] != BODY_TL && _map[i][j] != BODY_BR &&
		_map[i][j] != APPLE) {
		_map[i][j] = APPLE;
	}
	 else
		newSeed();
}

const std::string ar::Snake::getSpritesPath() const
{
	return std::__cxx11::string("./resources/Snake2.png");
}

const std::string ar::Snake::getGameName() const
{
	return std::__cxx11::string("Snake");
}

void ar::Snake::manageKey(const ar::Event &key)
{
	if (key == ar::AR_PAUSE) {
		setPause();
		if (!_firstPause) {
			_firstTimer = std::time(nullptr);
			_firstPause = true;
			}
	}
	if (_pause) {
		_savePause = std::time(nullptr);
	}

	if ((_alreadyUse && key != AR_UNKNOWN) ||
		(key != AR_UNKNOWN && key != _saveKey)) {
		_key = key;
		_alreadyUse = false;
	}
}

const std::map<unsigned char, ar::spriteCoords> &ar::Snake::getSprites() const
{
	return _sprites;
}

const std::map<unsigned char, ar::colorVector> &ar::Snake::getColors() const
{
	return _colors;
}

extern "C" ar::IGame *createGame()
{
	return new ar::Snake();
}

extern "C" void destroyGame(ar::IGame *ptr)
{
	delete ptr;
}
