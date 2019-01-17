/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** cpp_arcade file
*/

#include <vector>
#include <ncurses.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "Arcade.hpp"
#include "libs/NcursesLib.hpp"

ar::NcursesLib::NcursesLib()
{
	_currentGame = 0;
	initscr();
	noecho();
	curs_set(0);
	keypad(stdscr, true);
	std::map<unsigned char, colorVector> colors;
	this->loadResources(colors);
	timeout(0);
}

ar::NcursesLib::~NcursesLib()
{
	clear();
	endwin();
}

void ar::NcursesLib::initMenu(const std::vector<std::string> &menuChoices,
	__attribute__((unused))const std::string &menuName,
	const std::vector<std::string> &lib)
{
	clear();
	_menuChoices.clear();
	_libChoices.clear();
	_menuChoices = menuChoices;
	_libChoices = lib;
}


void ar::NcursesLib::loadResources(const std::map<unsigned char, colorVector> &colors)
{
	clear();
	start_color();
	_colors = colors;
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_color(static_cast<short>(8),
		   static_cast<short>(static_cast<double>((255 * 1000) / 255)),
		   static_cast<short>(static_cast<double>((102 * 1000) / 255)),
		   static_cast<short>(static_cast<double>((1 * 1000) / 255)));
	init_pair(7, 8, COLOR_BLACK);
	init_pair(8, 8, COLOR_WHITE);
	std::for_each(_colors.begin(), _colors.end(),
		[](std::pair<unsigned char, ar::colorVector> element) {
			ar::colorVector count = element.second;
			init_color(static_cast<short>(element.first + 10),
				static_cast<short>(static_cast<double>((count.red * 1000) / 255)),
				static_cast<short>(static_cast<double>((count.green * 1000) / 255)),
				static_cast<short>(static_cast<double>((count.blue * 1000) / 255)));
			init_pair(static_cast<short>(element.first + MENU_COLORS),
				static_cast<short>(element.first + 10),
				static_cast<short>(element.first + 10));
		});
}

void ar::NcursesLib::refreshUsername(std::string &name, int realKey)
{
	(void)name;
	(void)realKey;
	if (realKey >= 'a' && realKey < 'z') {
		name += (realKey);
	} else if (realKey == KEY_BACKSPACE &&
		   name.size() > 0) {
		name.pop_back();
		clear();
	}
	_username = name;
}

void ar::NcursesLib::displayAsciiArt(int &begin_y)
{
	int begin_x = COLS / 2 - 40;

	if (COLS < 0)
		begin_x = 0;
	showStrInColor(begin_y, begin_x,	"            :::      :::::::::    ::::::::       :::      :::::::::   :::::::::::", COLOR_PAIR(1));
	showStrInColor(++begin_y, begin_x,	"         :+: :+:    :+:    :+:  :+:    :+:    :+: :+:    :+:    :+:  :+:         ", COLOR_PAIR(7));
	showStrInColor(++begin_y, begin_x,	"       +:+   +:+   +:+    +:+  +:+          +:+   +:+   +:+    +:+  +:+          ", COLOR_PAIR(3));
	showStrInColor(++begin_y, begin_x,	"     +#++:++#++:  +#++:++#:   +#+         +#++:++#++:  +#+    +:+  +#++:++#      ", COLOR_PAIR(2));
	showStrInColor(++begin_y, begin_x,	"    +#+     +#+  +#+    +#+  +#+         +#+     +#+  +#+    +#+  +#+            ", COLOR_PAIR(6));
	showStrInColor(++begin_y, begin_x,	"   #+#     #+#  #+#    #+#  #+#    #+#  #+#     #+#  #+#    #+#  #+#             ", COLOR_PAIR(4));
	showStrInColor(++begin_y, begin_x,	"  ###     ###  ###    ###   ########   ###     ###  #########   ##########       ", COLOR_PAIR(5));
}

void ar::NcursesLib::displayLibs(int &begin_y)
{
	size_t bigger = 0;

	for (size_t i = 0; i < _libChoices.size(); i++) {
		if (_libChoices[i].size() > bigger)
			bigger = _libChoices[i].size();
	}
	attron(A_UNDERLINE);
	attron(A_BOLD);
	showStrInColor(begin_y, 2 * COLS / 3 - ((COLS / 3) / 2) - 5, "[LIBRARIES]", COLOR_PAIR(7));
	attroff(A_UNDERLINE);
	attroff(A_BOLD);
	begin_y += 3;
	for (size_t i = 0; i < _libChoices.size(); i++) {
		if (_libChoices[i] == "lib_arcade_ncurses.so") {
			std::string tmp;

			tmp = "<-- " + _libChoices[i] + " -->";
			showStrInColor(begin_y + i * 2, 2 * COLS / 3 - ((COLS /
				3) / 2) - tmp.size() / 2, tmp.c_str(), COLOR_PAIR(7));
		}
		else
			mvprintw(begin_y + i * 2, 2 * COLS / 3 - ((COLS /
				3) / 2) - _libChoices[i].size() / 2, _libChoices[i].c_str());
	}
}

void ar::NcursesLib::displayGames(int &begin_y)
{
	size_t bigger = 0;

	for (size_t i = 0; i < _menuChoices.size(); i++) {
		if (_menuChoices[i].size() > bigger)
			bigger = _menuChoices[i].size();
	}
	attron(A_UNDERLINE);
	attron(A_BOLD);
	begin_y -= 3;
	showStrInColor(begin_y, 3 * COLS / 3 - ((COLS / 3) / 2) - 7, "[SELECT A GAME]", COLOR_PAIR(7));
	attroff(A_UNDERLINE);
	attroff(A_BOLD);
	begin_y += 3;
	for (size_t i = 0; i < _menuChoices.size(); i++) {
		if (i == _currentGame) {
			std::string tmp;
			tmp = "<-- " + _menuChoices[i] + " -->";
			showStrInColor(begin_y + i * 2, 3 * COLS / 3 - ((COLS / 3) / 2) - tmp.size() / 2, tmp.c_str(), COLOR_PAIR(7));
		} else {
			mvprintw(begin_y + i * 2, 3 * COLS / 3 - ((COLS / 3) / 2) - _menuChoices[i].size() / 2, _menuChoices[i].c_str());
		}
	}
}

void ar::NcursesLib::displayUser(int &begin_y, const std::vector<userInterface> &dataArray)
{
	size_t bigger = 0;

	for (size_t i = 0; i < _menuChoices.size(); i++) {
		if (_menuChoices[i].size() > bigger)
			bigger = _menuChoices[i].size();
	}
	attron(A_UNDERLINE);
	attron(A_BOLD);
	begin_y -= 3;
	showStrInColor(begin_y, 1 * COLS / 3 - ((COLS / 3) / 2) - 8, "[USER INTERFACE]", COLOR_PAIR(7));
	attroff(A_UNDERLINE);
	attroff(A_BOLD);
	begin_y += 3;
	std::string score;
	std::string time;
	std::string user;
	std::stringstream ss;

	if (_currentGame < dataArray.size())
		ss << dataArray[_currentGame].score;
	else
		ss << "0";
	score = ss.str();
	ss.str(std::string());
	if (_currentGame < dataArray.size())
		ss << dataArray[_currentGame].time;
	else
		ss << "0";
	time = ss.str();
	if (_currentGame < dataArray.size())
		user = dataArray[_currentGame].username;
	else
		ss << "0";


	mvprintw(begin_y, 1 * COLS / 3 - ((COLS / 3) / 2) - 5 - user.size() / 2, "Username: ");
	showStrInColor(begin_y, 1 * COLS / 3 - ((COLS / 3) / 2) + 5 - user.size() / 2, user, COLOR_PAIR(7));
	mvprintw(begin_y + 1 * 2, 1 * COLS / 3 - ((COLS / 3) / 2) - 4, "Score: ");
	showStrInColor(begin_y + 1 * 2, 1 * COLS / 3 - ((COLS / 3) / 2) + 5 - score.size() / 2, score, COLOR_PAIR(7));
	mvprintw(begin_y + 2 * 2, 1 * COLS / 3 - ((COLS / 3) / 2) - 3, "Time: ");
	showStrInColor(begin_y + 2 * 2, 1 * COLS / 3 - ((COLS / 3) / 2) + 4 - time.size() / 2, time, COLOR_PAIR(7));
}

int ar::NcursesLib::refreshMenu(const ar::Event &key, const std::vector<userInterface> &dataArray)
{
	(void)dataArray;
	//clear();
	if (key == AR_UP && _currentGame > 0) {
		_currentGame--;
	}
	if (key == AR_DOWN && _currentGame < _menuChoices.size() - 1) {
		_currentGame++;
	}
	int begin_y = 5;
	displayAsciiArt(begin_y);
	begin_y += 8;
	displayLibs(begin_y);
	displayGames(begin_y);
	displayUser(begin_y, dataArray);
	mvprintw(0, 0, "Username : [%s]", _username.c_str());
	//refresh();
	return static_cast<int>(_currentGame);
}

void ar::NcursesLib::destroyMenu()
{
}

ar::Event ar::NcursesLib::getEvent(int &realKey)
{
	ar::Event key;

	realKey = getch();
	switch (realKey) {
	case KEY_UP:
		clear();
		key = AR_UP;
		break;
	case KEY_DOWN:
		clear();
		key = AR_DOWN;
		break;
	case 27:
		clear();
		endwin();
		key = AR_EXIT;
		break;
	case 112:
		key = AR_PAUSE;
		break;
	case 51:
		key = AR_PREV_GRAPH_LIB;
		break;
	case 52:
		key = AR_NEXT_GRAPH_LIB;
		break;
	case KEY_RIGHT:
		key = AR_RIGHT;
		break;
	case KEY_LEFT:
		key = AR_LEFT;
		break;
	case 10:
		key = AR_VALIDATE;
		break;
	case KEY_RESIZE:
		key = AR_UNKNOWN;
		clear();
		break;
	case 'r':
		key = AR_RESTART;
		break;
	case 'm':
		key = AR_MENU;
		break;
	default:
		key = AR_UNKNOWN;
		break;
	}
	return key;
}

bool ar::NcursesLib::canHandleSprites()
{
	return false;
}

void ar::NcursesLib::showStrInColor(const int &y, const int &x, const std::string &str, const int &pair)
{
	if (pair != -1)
		attron(pair);
	mvprintw(y, x, str.c_str());
	if (pair != -1)
		attroff(pair);
}

void ar::NcursesLib::displayGame(const userInterface &UI, Map &map)
{
	(void)UI;
	(void)map;
	int begin_x = COLS / 2 - map.getWidth();
	int begin_y = LINES / 2 - map.getHeight() / 2;
	std::string user = UI.username;
	if (UI.username.empty())
		user = "Unknown";
	mvprintw(begin_y - 3, COLS / 2 - UI.username.size() / 2 - 5, "Username: %s", user.c_str());
	mvprintw(begin_y - 2, COLS / 2 - UI.username.size() / 2 - 3, "Score: %s", std::to_string(UI.score).c_str());
	mvprintw(begin_y - 4, COLS / 2 - UI.username.size() / 2 - 3, "Time: %s", std::to_string(UI.time).c_str());

	begin_y++;
	begin_x++;
	int x = 0;
	int y = 0;
	for (y = 0; y < map.getHeight(); y++) {
		for (x = 0; x < map.getWidth(); x++) {
			int cell = map.getAtPos(y, x);
			if (static_cast<int>(COLOR_PAIR(cell)) != 0) {
				this->showStrInColor(begin_y + y, begin_x + x * 2, "00", COLOR_PAIR(cell + MENU_COLORS));
			} else {
				this->showStrInColor(begin_y + y, begin_x + x * 2, "  ", -1);
			}
		}
	}
}

void ar::NcursesLib::loadResources(
	const __attribute__((unused))std::string &filePath,
	const __attribute__((unused))std::map<unsigned char, ar::spriteCoords> &sprites
)
{
}

extern "C" ar::IDisplay *createDisplay()
{
	return new ar::NcursesLib;
}

extern "C" void destroyDisplay(ar::IDisplay *ptr)
{
	delete ptr;
}