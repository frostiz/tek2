/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** cpp_arcade file
*/

#include <iostream>
#include <fstream>
#include <thread>
#include "games/Qix.hpp"

ar::Qix::Qix() {
	_actualTimer = std::time(nullptr);
	_startTime = std::chrono::system_clock::now();
	_timer = std::chrono::system_clock::now();
	for (int i = 0; i < _map.getHeight() - 1; i++) {
		for (int j = 0; j < _map.getWidth() - 1; j++) {
			_map[i][j] = FLOOR;
		}
	}
	for (int i = 0; i < _map.getHeight() - 1; i++) {
		_map[i][0] = WALL;
		_map[i][_map.getHeight() - 1] = WALL;
	}
	for (int i = 0; i < _map.getWidth() - 1; i++) {
		_map[0][i] = WALL;
		_map[_map.getWidth() - 1][i] = WALL;
	}
	_map[_map.getHeight() - 1][_map.getWidth() - 1] = WALL;

	for (int i = 0; i < _copymap.getHeight() - 1; i++) {
		for (int j = 0; j < _copymap.getWidth() - 1; j++) {
			_copymap[i][j] = FLOOR;
		}
	}
	for (int i = 0; i < _copymap.getHeight() - 1; i++) {
		_copymap[i][0] = WALL;
		_copymap[i][_copymap.getHeight() - 1] = WALL;
	}
	for (int i = 0; i < _copymap.getWidth() - 1; i++) {
		_copymap[0][i] = WALL;
		_copymap[_copymap.getWidth() - 1][i] = WALL;
	}
	_copymap[_copymap.getHeight() - 1][_copymap.getWidth() - 1] = WALL;
	_gameOver = false;
	_score = 0;
	_pause = true;
	_firstPause = false;
	initColors();
	initSprites();

	_posx = _map.getWidth() / 2;
	_posy = _map.getHeight() - 1;

	_savePos.first = _posy;
	_savePos.second = _posx;
	_lives = 3;
	_loose = false;
	initMonster();
	_sparks.push_back({0, 0});
	_sparks.push_back({0, 0});
	_sparksDir.push_back(EAST);
	_sparksDir.push_back(SOUTH);
	std::srand(std::time(nullptr));
}

void ar::Qix::initMonster() {
	_monsterSpeed = 150;
	_posMonster.push_back({2, 3});
	_posMonster.push_back({3, 3});
	_posMonster.push_back({4, 3});
	_posMonster.push_back({2, 4});
	_posMonster.push_back({3, 4});
	_posMonster.push_back({4, 4});
	_posMonster.push_back({2, 5});
	_posMonster.push_back({3, 5});
	_posMonster.push_back({4, 5});
	_posMonster.push_back({5, 4});
	_posMonster.push_back({3, 6});
	_posMonster.push_back({3, 2});
	_posMonster.push_back({1, 4});
}

void ar::Qix::initSprites() {
	_sprites[FLOOR] = {812, 496, 32, 32};
	_sprites[CAPTURED_FLOOR] = {854, 92, 32, 32};
	_sprites[WALL] = {938, 128, 31, 32};
	_sprites[UNWALKABLE_WALL] = {808, 250, 32, 32};
	_sprites[BODY] = {416, 74, 32, 48};
	_sprites[SPARK] = {1024, 68, 32, 32};
	_sprites[TRAIL] = {372, 130, 32, 32};
	_sprites[MONSTER] = {358, 252, 32, 32};
}

void ar::Qix::initColors() {
	_colors[0] = {0, 0, 0};
	_colors[1] = {255, 255, 255};
	_colors[WALL] = {255, 0, 0};
	_colors[UNWALKABLE_WALL] = {120, 0, 120};
	_colors[FLOOR] = {0, 0, 0};
	_colors[CAPTURED_FLOOR] = {0, 25, 0};
	_colors[BODY] = {0, 0, 255};
	_colors[SPARK] = {120, 120, 0};
	_colors[TRAIL] = {255, 255, 255};
	_colors[MONSTER] = {255, 255, 0};


}

void ar::Qix::manageKey(const Event &key) {
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
	if (key != AR_UNKNOWN)
		_key = key;
}

const std::map<unsigned char, ar::spriteCoords> &ar::Qix::getSprites() const {
	return _sprites;
}

const std::string ar::Qix::getSpritesPath() const {
	return std::string("./resources/qix-mario.png");
}

const std::map<unsigned char, ar::colorVector> &ar::Qix::getColors() const {
	return _colors;
}

int ar::Qix::refreshScore() {
	return _score;
}

int ar::Qix::refreshTimer()
{
	if (!_firstPause)
		return (0);
	return (_actualTimer - _firstTimer);
}

bool ar::Qix::isGameOver() {
	if (_loose == true)
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	return _loose;
}

ar::Map &ar::Qix::getMap() {
	return _map;
}

void ar::Qix::showMonster()
{
	for (const auto elem : _posMonster) {
		_map[elem.first][elem.second] = MONSTER;
	}
}

std::vector<std::pair<int, int>> ar::Qix::getNewMonsterPos()
{
	std::vector<std::pair<int, int>> tmp;
	int posx = 0;
	int posy = 0;

	tmp = _posMonster;

	posx = rand() % 2;
	posx = (rand() % 2 == 0) ? posx * (-1) : posx;
	posy = rand() % 2;
	posy = (rand() % 2 == 0) ? posy * (-1) : posy;

	if (posx == 0 && posy == 0)
		return getNewMonsterPos();
	for (auto & elem : tmp) {
		elem.first -= posx;
		elem.second -= posy;
		if (elem.first < 0 || elem.second < 0
		    || elem.first >= _map.getWidth() - 1
		    || elem.second >= _map.getHeight() - 1 ||
		    _copymap[elem.first][elem.second] == WALL) {
			return getNewMonsterPos();
		}
	}
	return tmp;
}

void ar::Qix::hideMonster()
{
	for (const auto elem : _posMonster) {
		_map[elem.first][elem.second] = FLOOR;
	}
}

void ar::Qix::fillMap(ar::Map &map, int y, int x) {
	if (map[y][x] == ar::Qix::FLOOR || map[y][x] == ar::Qix::MONSTER)
		map[y][x] = 'T';
	if (x < map.getWidth() && (map[y][x + 1] == ar::Qix::FLOOR || map[y][x + 1] == ar::Qix::MONSTER))
		fillMap(map, y, ++x);
	if (x > 0 && (map[y][x - 1] == ar::Qix::FLOOR || map[y][x - 1] == ar::Qix::MONSTER))
		fillMap(map, y, --x);
	if (y < map.getHeight() && (map[y + 1][x] == ar::Qix::FLOOR || map[y + 1][x] == ar::Qix::MONSTER))
		fillMap(map, ++y, x);
	if (y > 0 && (map[y - 1][x] == ar::Qix::FLOOR || map[y - 1][x] == ar::Qix::MONSTER))
		fillMap(map, --y, x);
}

void ar::Qix::colorMap()
{
	ar::Map tmp(30, 30);
	for (int i = 0; i < _map.getHeight(); i++) {
		for (int j = 0; j < _map.getWidth(); j++) {
			tmp[i][j] = _map[i][j];
		}
	}
	fillMap(tmp, _posMonster.front().first, _posMonster.front().second);
	for (int i = 0; i < tmp.getHeight(); i++) {
		for (int j = 0; j < tmp.getWidth(); j++) {
			if (tmp[i][j] != 'T' && _map[i][j] == FLOOR && _copymap[i][j] == FLOOR)
				_map[i][j] = CAPTURED_FLOOR;
		}
	}
}

int ar::Qix::checkAround(const int &y, const int &x, const ar::Event &event) {
	if (x == 0 || y == 0 || x == _map.getWidth() - 1 || y == _map.getHeight() - 1 || x == 1 || y == 1 ||
		x == _map.getWidth() - 2 || y == _map.getHeight() - 2)
		return 0;
	if (event != AR_RIGHT && event != AR_DOWN && y > 0 && x > 0 && (_map[y - 1][x - 1] == TRAIL)) {
		return 84;
	} else if (event != AR_DOWN && y > 0 && (_map[y - 1][x] == TRAIL)) {
		return 84;
	} else if (event != AR_LEFT && event != AR_DOWN && y > 0 && x <= _map.getWidth() - 1 && (_map[y - 1][x + 1] == TRAIL)) {
		return 84;
	} else if (event != AR_RIGHT && x > 0 && (_map[y][x - 1] == TRAIL)) {
		return 84;
	} else if (event != AR_LEFT && x <= _map.getWidth() - 1 && (_map[y][x + 1] == TRAIL)) {
		return 84;
	} else if (event != AR_RIGHT && event != AR_UP && y <= _map.getHeight() - 1 && x > 0 && (_map[y + 1][x - 1] == TRAIL)) {
		return 84;
	} else if (event != AR_UP && y <= _map.getHeight() - 1 && (_map[y + 1][x] == TRAIL)) {
		return 84;
	} else if (event != AR_LEFT && event != AR_UP && x <= _map.getWidth() - 1 && y <= _map.getHeight() - 1 && (_map[y + 1][x + 1] == TRAIL)) {
		return 84;
	}
	return 0;
}

void ar::Qix::killBody() {
	_key = AR_UNKNOWN;
	_trailPos.clear();
	_lives--;
	_map[_posy][_posx] = FLOOR;
	_map[_savePos.first][_savePos.second] = BODY;
	if (_posy != 0 && _posx != 0 && _posy != _map.getHeight() - 1 && _posx != _map.getWidth() - 1) {
		_posy = _savePos.first;
		_posx = _savePos.second;
	}
	for (size_t i = 0; i < _sparks.size(); i++) {
		if (isTrail(_sparks[i].first, _sparks[i].second)) {
			_sparks[i].first = 0;
			_sparks[i].second = 0;
			if (i % 2 == 0)
				_sparksDir[i] = SOUTH;
			else
				_sparksDir[i] = EAST;
		}
	}
	if (_sparksDir.size() >= 3 && isTrail(_sparks[2].first, _sparks[2].second)) {
		_sparks[2].first = 0;
		_sparks[2].second = _map.getWidth() - 1;
		_sparksDir[2] = SOUTH;
	}
	if (_lives == 0)
		_loose = true;
}

int ar::Qix::displayMonster(const std::vector<std::pair<int, int>> &tmp) {
	hideMonster();
	int i = 0;
	for (const auto &elem : tmp) {
		_posMonster[i].first = elem.first;
		_posMonster[i].second = elem.second;
		i++;
	}
	for (const auto &elem : _posMonster) {
		if (_map[elem.first][elem.second] == TRAIL || _map[elem.first][elem.second] == BODY) {
			for (const auto &elem2 : _trailPos) {
				_map[elem2.first][elem2.second] = FLOOR;
			}
			killBody();
			return 1;
		}
	}
	showMonster();
	return 0;
}

void ar::Qix::checkBlockedWall()
{
	for (int i = 0; i <= _map.getHeight() - 1; i++) {
		for (int j = 0; j <= _map.getWidth() - 1; j++) {
			if (_map[i][j] == WALL || _map[i][j] == SPARK) {
				if ((i > 0 && j > 0 && _map[i - 1][j - 1] == FLOOR) ||
				    (i > 0 && _map[i - 1][j] == FLOOR) ||
				    (i > 0 && j < _map.getWidth() - 1 && _map[i - 1][j + 1] == FLOOR) ||
				    (j > 0 && _map[i][j - 1] == FLOOR) ||
				    (j < _map.getWidth() - 1 && _map[i][j + 1] == FLOOR) ||
				    (i < _map.getHeight() - 1 && j > 0 && _map[i + 1][j - 1] == FLOOR) ||
				    (i < _map.getHeight() - 1 && _map[i + 1][j] == FLOOR) ||
				    (i < _map.getHeight() - 1 && j < _map.getWidth() - 1 && _map[i + 1][j + 1] == FLOOR)
					) {
				} else {
					_map[i][j] = UNWALKABLE_WALL;
					_copymap[i][j] = UNWALKABLE_WALL;
				}
			}
		}
	}
}

void ar::Qix::checkEnd() {
	int total = (_map.getWidth() - 2) * (_map.getHeight() - 2);

	int remain = 0;

	for (int i = 0; i < _map.getHeight(); i++) {
		for (int j = 0; j < _map.getHeight(); j++) {
			if (_map[i][j] == FLOOR)
				remain++;
		}
	}
	int result = remain * 100 / total;

	if (result <= 25) {
		_loose = true;
	}
	_score = (100 - result) * 100;
	if (_score >= 5000 && _sparks.size() <= 2) {
		_sparks.push_back({0, 0});
		_sparksDir.push_back(SOUTH);
	}
}

void ar::Qix::changeDirFromNorthSouth(int &y, int &x, const int &i) {
	bool left = false;
	bool right = false;

	if (x > 0 && (_map[y][x - 1] == WALL || _map[y][x - 1] == TRAIL || _map[y][x - 1] == SPARK || _map[y][x - 1] == BODY))
		left = true;
	if (x < _map.getWidth() - 1 && (_map[y][x + 1] == WALL || _map[y][x + 1] == TRAIL || _map[y][x + 1] == SPARK || _map[y][x + 1] == BODY))
		right = true;
	if (right && left) {
		if (rand() % 2 == 0) {
			_sparksDir[i] = EAST;
			x += 1;
		} else {
			_sparksDir[i] = WEST;
			x -= 1;
		}
	} else if (right) {
		_sparksDir[i] = EAST;
		x += 1;
	} else if (left) {
		_sparksDir[i] = WEST;
		x -= 1;
	} else {
		y = 0;
		x = 0;
	}
}

void ar::Qix::changeDirFromEastWest(int &y, int &x, const int &i) {
	bool up = false;
	bool down = false;

	if (y > 0 && (_map[y - 1][x] == WALL || _map[y - 1][x] == TRAIL || _map[y - 1][x] == SPARK || _map[y - 1][x] == BODY))
		up = true;
	if (y < _map.getHeight() - 1 && (_map[y + 1][x] == WALL || _map[y + 1][x] == TRAIL || _map[y + 1][x] == SPARK || _map[y + 1][x] == BODY))
		down = true;
	if (up && down) {
		if (rand() % 2 == 0) {
			_sparksDir[i] = NORTH;
			y -= 1;
		} else {
			_sparksDir[i] = SOUTH;
			y += 1;
		}
	} else if (up) {
		_sparksDir[i] = NORTH;
		y -= 1;
	} else if (down) {
		_sparksDir[i] = SOUTH;
		y += 1;
	} else {
		y = 0;
		x = 0;
	}
}

void ar::Qix::randomSparkPos(const ar::Qix::e_direction &dir, int &y, int &x, const int &i) {
	if (dir == NORTH || dir == SOUTH) {
		changeDirFromNorthSouth(y, x, i);
	} else if (dir == EAST || dir == WEST) {
		changeDirFromEastWest(y, x, i);
	}
}

bool ar::Qix::isTrail(const int &y, const int &x) const {
	for (const auto &elem : _trailPos) {
		if (elem.first == y && elem.second == x)
			return true;
	}
	return false;
}

int ar::Qix::searchWall(int &y, int &x, const int &i) {
	for (int j = x;
	     j < _map.getWidth() && (_map[y][j] == UNWALKABLE_WALL || _map[y][j] == WALL || _map[y][j] == BODY); j++) {
		if (_map[y][j] == WALL || _map[y][j] == BODY) {
			x += 1;
			_sparksDir[i] = EAST;
			return 1;
		}
	}
	for (int j = x; j > 0 && (_map[y][j] == UNWALKABLE_WALL || _map[y][j] == WALL || _map[y][j] == BODY); j--) {
		if (_map[y][j] == WALL || _map[y][j] == BODY) {
			x -= 1;
			_sparksDir[i] = WEST;
			return 1;
		}
	}
	for (int j = y;
	     j < _map.getHeight() && (_map[j][x] == UNWALKABLE_WALL || _map[j][x] == WALL || _map[j][x] == BODY); j++) {
		if (_map[j][x] == WALL || _map[j][x] == BODY) {
			y += 1;
			_sparksDir[i] = SOUTH;
			return 1;
		}
	}
	for (int j = y; j > 0 && (_map[j][x] == UNWALKABLE_WALL || _map[j][x] == WALL || _map[j][x] == BODY); j--) {
		if (_map[j][x] == WALL || _map[j][x] == BODY) {
			y -= 1;
			_sparksDir[i] = NORTH;
			return 1;
		}
	}
	return 0;
}

void ar::Qix::defaultMove(int &y, int &x, const int &i) {
	if (x < _map.getWidth() - 1 && _map[y][x + 1] == UNWALKABLE_WALL) {
		_sparksDir[i] = EAST;
		x += 1;
		return ;
	} else if (y < _map.getHeight() - 1 && _map[y + 1][x] == UNWALKABLE_WALL) {
		_sparksDir[i] = SOUTH;
		y += 1;
		return;
	} else if (x > 0 && _map[y][x - 1] == UNWALKABLE_WALL) {
		_sparksDir[i] = WEST;
		x -= 1;
		return;
	} else if (y > 0 && _map[y - 1][x] == UNWALKABLE_WALL) {
		_sparksDir[i] = NORTH;
		y -= 1;
		return;
	}
}

void ar::Qix::retrieveWalkable(int &y, int &x, const int &i) {
	if (searchWall(y, x, i) == 1)
		return ;
	else
		defaultMove(y, x, i);
}

void ar::Qix::useLastDir(int &y, int &x, const int &i) {
	if (_sparksDir[i] == NORTH) {
		if (y > 0 && (_map[y - 1][x] == WALL || _map[y - 1][x] == TRAIL ||
			      _map[y - 1][x] == SPARK || _map[y - 1][x] == BODY)) {
			y -= 1;
		} else {
			randomSparkPos(NORTH, y, x, i);
		}
	} else if (_sparksDir[i] == EAST) {
		if (x < _map.getWidth() - 1 &&
		    (_map[y][x + 1] == WALL || _map[y][x + 1] == TRAIL ||
		     _map[y][x + 1] == SPARK || _map[y][x + 1] == BODY)) {
			x += 1;
		} else {
			randomSparkPos(EAST, y, x, i);
		}
	} else if (_sparksDir[i] == SOUTH) {
		if (y < _map.getHeight() - 1 &&
		    (_map[y + 1][x] == WALL || _map[y + 1][x] == TRAIL ||
		     _map[y + 1][x] == SPARK || _map[y + 1][x] == BODY)) {
			y += 1;
		} else {
			randomSparkPos(SOUTH, y, x, i);
		}
	} else if (_sparksDir[i] == WEST) {
		if (x > 0 && (_map[y][x - 1] == WALL || _map[y][x - 1] == TRAIL ||
			      _map[y][x - 1] == SPARK || _map[y][x - 1] == BODY)) {
			x -= 1;
		} else {
			randomSparkPos(WEST, y, x, i);
		}
	}
}

void ar::Qix::followTrail(int &y, int &x, const int &i) {
	if (isTrail(y + 1, x) && _map[y][x] != TRAIL) {
		_sparksDir[i] = SOUTH;
		y += 1;
	} else if (isTrail(y - 1, x) && _map[y][x] != TRAIL) {
		_sparksDir[i] = NORTH;
		y -= 1;
	}  else if (isTrail(y, x + 1) && _map[y][x] != TRAIL) {
		_sparksDir[i] = EAST;
		x += 1;
	}  else if (isTrail(y, x - 1) && _map[y][x] != TRAIL) {
		_sparksDir[i] = WEST;
		x -= 1;
	} else {
		useLastDir(y, x, i);
	}
}

void ar::Qix::moveSparks() {
	for (size_t i = 0; i < _sparks.size(); i++) {
		int &y = _sparks[i].first;
		int &x = _sparks[i].second;

		if (_copymap[y][x] == UNWALKABLE_WALL) {
			_map[y][x] = _copymap[y][x];
			retrieveWalkable(y, x, i);
			_map[y][x] = SPARK;
		} else {

			if (isTrail(y, x))
				_map[y][x] = TRAIL;
			else
				_map[y][x] = _copymap[y][x];
			followTrail(y, x, i);
			_map[y][x] = SPARK;
		}
	}
}

int ar::Qix::checkSparkOnBody() {
	for (size_t i = 0; i < _sparks.size(); i++) {
		if (_sparks[i].first == _posy && _sparks[i].second == _posx) {
			for (size_t i = 0; i < _trailPos.size(); i++) {
				int posy = _trailPos[i].first;
				int posx = _trailPos[i].second;
				_map[posy][posx] = _copymap[posy][posx];
			}
			killBody();
			return 1;
		}
	}
	return 0;
}

int ar::Qix::checkKey(int &addposy, int &addposx)
{
	if (_key == ar::AR_UP) {
		if (_posy - 1 >= 0 && _map[_posy - 1][_posx] != CAPTURED_FLOOR &&
		    _map[_posy - 1][_posx] != UNWALKABLE_WALL && checkAround(_posy - 1, _posx, AR_UP) != 84)
			addposy = -1;
		else return 1;
	} else if (_key == ar::AR_RIGHT) {
		if (_posx + 1 <= _map.getWidth() - 1 && _map[_posy][_posx + 1] != CAPTURED_FLOOR &&
		    _map[_posy][_posx + 1] != UNWALKABLE_WALL && checkAround(_posy, _posx + 1, AR_RIGHT) != 84)
			addposx = 1;
		else return 1;
	} else if (_key == ar::AR_DOWN) {
		if (_posy + 1 <= _map.getHeight() - 1 && _map[_posy + 1][_posx] != CAPTURED_FLOOR &&
		    _map[_posy + 1][_posx] != UNWALKABLE_WALL && checkAround(_posy + 1, _posx, AR_DOWN) != 84)
			addposy = 1;
		else return 1;
	} else if (_key == ar::AR_LEFT && _map[_posy][_posx - 1] != CAPTURED_FLOOR &&
		   _map[_posy][_posx - 1] != UNWALKABLE_WALL && checkAround(_posy, _posx - 1, AR_LEFT) != 84) {
		if (_posx - 1 >= 0)
			addposx = -1;
		else return 1;
	}
	return 0;
}

void ar::Qix::retrievedWall() {
	for (const auto &elem : _trailPos) {
		_map[elem.first][elem.second] = WALL;
		_copymap[elem.first][elem.second] = WALL;
	}
	colorMap();
	_trailPos.clear();
	checkBlockedWall();
	checkEnd();
}

void ar::Qix::loopBody() {
	moveSparks();
	if (checkSparkOnBody() == 1)
		return resetTick();
	int newposx = _posx;
	int newposy = _posy;
	int addposx = 0;
	int addposy = 0;

	if (checkKey(addposy, addposx) == 1)
		return resetTick();

	newposx = _posx + addposx;
	newposy = _posy + addposy;

	if (_copymap[_posy][_posx] == FLOOR) {
		_map[_posy][_posx] = TRAIL;
		_trailPos.push_back({_posy, _posx});
	}
	else
		_map[_posy][_posx] = _copymap[_posy][_posx];

	if (_map[_posy][_posx] == TRAIL && _map[newposy][newposx] == WALL)
		retrievedWall();
	if (_map[newposy][newposx] == WALL) {
		_savePos.first = newposy;
		_savePos.second = newposx;
	}
	_map[newposy][newposx] = BODY;

	_posx = newposx;
	_posy = newposy;

	if (checkSparkOnBody() == 1)
		return resetTick();
	resetTick();
}

void ar::Qix::loop() {
	unsigned long long tick = tickMove();
	if (tick > _monsterSpeed && !_pause) {
		std::vector<std::pair<int, int>> tmp;

		tmp = getNewMonsterPos();
		if (displayMonster(tmp) == 1)
			return resetTick();
		_actualTimer = static_cast<int>(std::time(nullptr));
	}
	if (tick > 150 && !_pause) {
		loopBody();
		_actualTimer = static_cast<int>(std::time(nullptr));
	}
}

void ar::Qix::resetTick()
{
	_startTime = std::chrono::system_clock::now();
}

unsigned long long ar::Qix::tickMove() const
{
	return static_cast<unsigned long long int>
	(std::chrono::duration_cast<std::chrono::milliseconds>(
			std::chrono::system_clock::now() - _startTime).count());
}

const std::string ar::Qix::getGameName() const {
	return std::string("Qix");
}

void ar::Qix::setPause() {
	_pause = !_pause;
	if (!_pause) {
		_firstTimer += (_savePause - _actualTimer);
	}
}

extern "C" ar::IGame *createGame() {
	return new ar::Qix();
}

extern "C" void destroyGame(ar::IGame *ptr) {
	delete ptr;
}