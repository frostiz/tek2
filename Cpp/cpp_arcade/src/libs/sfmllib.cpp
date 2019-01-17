//
// EPITECH PROJECT, 2018
// Sfmllib.cpp
// File description:
// sfml
//

#include <iostream>
#include <sstream>
#include <cstring>
#include <cmath>
#include "libs/sfmllib.hpp"

ar::sfmllib::sfmllib()
{
	_screenWidth = 1600;
	_screenHeight = 900;
	_screenSize.x = 1600;
	_screenSize.y = 900;
	_window = new sf::RenderWindow(
		sf::VideoMode(_screenSize.x + 1, _screenSize.y), "sfml window");
	if (!_window) {
		throw std::invalid_argument("Could not create window");
	}
	_window->setSize(sf::Vector2u(_screenSize.x, _screenSize.y));
	if (!_font.loadFromFile("./resources/arial.ttf")) {
		throw std::invalid_argument("Could not load arial.ttf");
	}
	_text.setFont(_font);
	_text.setCharacterSize(30);
	_tmpText.setFont(_font);
	_tmpText.setCharacterSize(30);
	_currentGame = 0;
	_username.setFont(_font);
	_username.setCharacterSize(30);
	_username.setFillColor(sf::Color::White);
	_events = {
		{{false, sf::Keyboard::Up}, ar::Event::AR_UP},
		{{false, sf::Keyboard::Down}, ar::Event::AR_DOWN},
		{{false, sf::Keyboard::Left}, ar::Event::AR_LEFT},
		{{false, sf::Keyboard::Right}, ar::Event::AR_RIGHT},
		{{false, sf::Keyboard::Return}, ar::Event::AR_VALIDATE},
		{{false, sf::Keyboard::Num3}, ar::Event::AR_PREV_GRAPH_LIB},
		{{false, sf::Keyboard::Num4}, ar::Event::AR_NEXT_GRAPH_LIB},
		{{false, sf::Keyboard::Quote}, ar::Event::AR_NEXT_GRAPH_LIB},
		{{false, sf::Keyboard::P}, ar::Event::AR_PAUSE},
		{{false, sf::Keyboard::Num1}, ar::Event::AR_PREV_GAME},
		{{false, sf::Keyboard::Num2}, ar::Event::AR_NEXT_GAME},
		{{false, sf::Keyboard::Escape}, ar::Event::AR_EXIT},
		{{false, sf::Keyboard::R}, ar::Event::AR_RESTART},
		{{false, sf::Keyboard::M}, ar::Event::AR_MENU}};
}

ar::sfmllib::~sfmllib()
{
	_window->close();
}

void ar::sfmllib::destroyMenu()
{
	return;
}

ar::Event ar::sfmllib::getEvent(int &realKey)
{
	sf::Event event;

	realKey = -1;
	if (_window->pollEvent(event)) {
		if (event.type == sf::Event::KeyPressed) {
			realKey = event.key.code;
		}
		if (event.type == sf::Event::KeyPressed) {
			if (_events.find({event.key.shift, event.key.code}) !=
				_events.end())
				return _events[{event.key.shift,
					event.key.code}];
			else
				return ar::AR_UNKNOWN;
		}
	}
	return AR_UNKNOWN;
}

bool ar::sfmllib::canHandleSprites()
{
	return true;
}

void ar::sfmllib::loadResources(const std::string &filePath,
	const std::map<unsigned char, ar::spriteCoords> &sprites)
{
	sf::Texture texture;
	sf::Vector2f rect_size;

	_filePath = filePath;
	_sprites = sprites;
	rect_size.x = 20;
	rect_size.y = 20;
	sf::RectangleShape square(rect_size);
	_textures.clear();
	for (auto it = _sprites.begin(); it != _sprites.end(); it++) {
		sf::RectangleShape rectangle;
		texture.loadFromFile(_filePath,
			sf::IntRect(it->second.x, it->second.y,
				it->second.width, it->second.height));
		_textures[it->first] = texture;
		rectangle.setSize(
			sf::Vector2f(it->second.height, it->second.width));
		rectangle.setTexture(&texture);
		rectangle.setPosition(it->second.y, it->second.x);
		_window->draw(rectangle);
	}
}

void ar::sfmllib::refreshUsername(std::string &name, int realKey)
{
	if (realKey >= sf::Keyboard::A && realKey < sf::Keyboard::Z) {
		name += (realKey) + 65;
	} else if (realKey == sf::Keyboard::BackSpace && name.size() > 0) {
		name.pop_back();
	}
	if (name.size() != 0) {
		_username.setString(name);
		_window->draw(_username);
	}
}

void ar::sfmllib::initMenu(const std::vector<std::string> &menuChoices,
	__attribute__((unused))const std::string &menuName,
	const std::vector<std::string> &lib)
{
	_menuChoices = menuChoices;
	_libChoices = lib;
}

void ar::sfmllib::loadResources(
	const std::map<unsigned char, ar::colorVector> &colors)
{
	_colors = colors;
}

std::vector<std::string> ar::sfmllib::refreshIt(sf::Text &title)
{
	sf::Font font;
	float currentYPos = _screenSize.x / (strlen("ARCADE") * 2);

	if (!font.loadFromFile("resources/font/mexcellent 3d.ttf")) {
		throw std::invalid_argument("Could not load font");
	}
	title.setString("ARCADE");
	title.setFont(font);
	title.setCharacterSize(static_cast<unsigned int>(currentYPos));
	title.setPosition(static_cast<float>(
		_screenSize.x - (_screenSize.x * (0.63))), 0);
	title.setFillColor(sf::Color::Magenta);
	_window->draw(title);
	std::vector<std::string> titles;
	titles.push_back("HIGHSCORE");
	titles.push_back("GAME");
	titles.push_back("LIB");
	return titles;
}

void ar::sfmllib::displayMenu(float xPos, float yPos,
	const std::vector<ar::userInterface> &dataArray)
{
	float heightAvailable = yPos + 60;
	float widthAvailable = xPos;
	for (size_t j = 0; j < _menuChoices.size(); ++j) {
		_text.setString(_menuChoices[j]);
		_text.setPosition(
			static_cast<float>((widthAvailable + xPos / 2) -
				((_menuChoices.size() * 60) / 2)),
			heightAvailable);
		_text.setCharacterSize(60);
		if (j == _currentGame) {
			_text.setFillColor(sf::Color::Red);
		} else {
			_text.setFillColor(sf::Color::White);
		}
		_window->draw(_text);
		if (j == _currentGame && _currentGame < dataArray.size()) {
			DisplayScore(xPos, yPos + 60,
				const_cast<userInterface &>(dataArray[_currentGame]));
		}
		heightAvailable += 70;
	}
	heightAvailable = yPos + 60;
	widthAvailable += xPos;
	for (size_t j = 0; j < _libChoices.size(); ++j) {
		_text.setString(_libChoices[j]);
		_text.setPosition(
			static_cast<float>((widthAvailable + xPos / 4) -
				((_menuChoices.size() * 60) / 2)),
			heightAvailable);
		_text.setCharacterSize(60);
		_text.setFillColor(sf::Color::White);
		_window->draw(_text);
		heightAvailable += 70;
	}
}

int ar::sfmllib::refreshMenu(const ar::Event &key,
	const std::vector<ar::userInterface> &dataArray)
{
	sf::RectangleShape background(sf::Vector2f(_screenSize.x, _screenSize.y));
	sf::Texture texture;
	sf::Font font;
	sf::Text title;

	if (key == ar::Event::AR_UP && _currentGame > 0) {
		_currentGame--;
	}
	else if (key == AR_DOWN && _currentGame < _menuChoices.size() - 1) {
		_currentGame++;
	}
	if (texture.loadFromFile("./resources/sfml_menu.png")) {
		background.setTexture(&texture);
		background.setPosition(0, 0);
		_window->draw(background);
	} else {
		throw std::invalid_argument("Could not load sfml_menu.png");
	}
	std::vector<std::string> titles = refreshIt(title);
	float currentYPos = _screenSize.x / (strlen("ARCADE") * 2);
	if (!font.loadFromFile("resources/font/Chinese Takeaway.ttf")) {
		throw std::invalid_argument("Could not load font");
	}
	float heightAvailable = _screenSize.y - currentYPos;
	float xPos = static_cast<float>(
		_screenSize.x - (_screenSize.x * (2.0 / 3.0)));
	float yPos = static_cast<float>(
		heightAvailable - (heightAvailable * (6.0 / 8.0)));
	float widthAvailable = 0;
	_text.setFont(font);
	_text.setFillColor(sf::Color::White);
	for (const auto &it : titles) {
		_text.setString(it);
		_text.setPosition(
			static_cast<float>((widthAvailable + xPos / 2) -
				((it.size() * 60) / 4)), yPos);
		_text.setCharacterSize(30 * 2);
		widthAvailable += xPos;
		_window->draw(_text);
	}
	displayMenu(xPos, yPos, dataArray);
	_window->draw(_username);
	_window->display();
	return static_cast<int>(_currentGame);
}

void ar::sfmllib::writeDataInGame(const ar::userInterface &UI)
{
	_tmpText.setFillColor(sf::Color::White);
	std::string data;
	std::stringstream ss;
	ss << UI.score;
	data = "Score ";
	data += ss.str();
	_tmpText.setString(data);
	_tmpText.setPosition(_screenWidth / 2 + 150, 0);
	_window->draw(_tmpText);
	ss.str(std::string());
	_tmpText.setFillColor(sf::Color::White);
	int seconds = UI.time;
	int minutes = seconds / 60;
	seconds = seconds % 60;
	ss << minutes << ":" << seconds;
	data = "Time ";
	data += ss.str();
	_tmpText.setString(data);
	_tmpText.setPosition(_screenWidth / 2 + 150, 50);
	_window->draw(_tmpText);
	ss.str(std::string());
	_tmpText.setFillColor(sf::Color::White);
	_tmpText.setString(UI.username);
	_tmpText.setPosition(_screenWidth / 2 + 150, 100);
	_window->draw(_tmpText);
}

void ar::sfmllib::displayGame(const ar::userInterface &UI, ar::Map &map)
{
	int i = 0;
	int j = 0;
	int start = 0;
	int end = 0;

	_window->clear(sf::Color::Black);
	writeDataInGame(UI);
	sf::Vector2f rect_size;
	size_t squareSize;
	if (_screenSize.x >= _screenSize.y) {
		squareSize = _screenSize.y;
	} else {
		squareSize = _screenSize.x;
	}
	if (map.getWidth() > map.getHeight()) {
		squareSize /= map.getWidth();
	} else {
		squareSize /= map.getHeight();
	}
	rect_size.x = squareSize;
	rect_size.y = squareSize;
	sf::RectangleShape square(rect_size);
	while (i < map.getHeight()) {
		while (j < map.getWidth()) {
			if (map[i][j] >= 0 && map[i][j] < 100) {
				if (map[i][j] != '2' - 48) {
					square.setTexture(&_textures[2]);
					square.setPosition(
						(float)start + (j * squareSize),
						(float)end + (i * squareSize));
					_window->draw(square);
					square.setTexture(
						&_textures[map[i][j]]);
					square.setPosition(
						(float)start + (j * squareSize),
						(float)end + (i * squareSize));
				} else {
					square.setTexture(
						&_textures[map[i][j]]);
					square.setPosition(
						(float)start + (j * squareSize),
						(float)end + (i * squareSize));
				}
			}
			j++;
			_window->draw(square);
		}
		j = 0;
		i++;
	}
	_window->display();
}

void ar::sfmllib::DisplayScore(float x, float y, ar::userInterface &user)
{
	y += 70;
	std::vector<std::string> desc{"Name : ", "Score : ", "Time : "};
	_text.setFillColor(sf::Color::White);
	_text.setString(desc[0] + user.username);
	_text.setPosition(static_cast<float>(x / 5), y);
	_text.setCharacterSize(60);
	_window->draw(_text);
	y += 70;
	std::string tmp = std::to_string(user.score);
	_text.setString(desc[1] + tmp);
	_text.setPosition(static_cast<float>(x / 5), y);
	_text.setCharacterSize(60);
	_window->draw(_text);
	y += 70;
	tmp = std::to_string(user.time);
	_text.setString(desc[2] + tmp);
	_text.setPosition(static_cast<float>(x / 5), y);
	_text.setCharacterSize(60);
	_window->draw(_text);
}

extern "C" ar::IDisplay *createDisplay()
{
	return new ar::sfmllib;
}

extern "C" void destroyDisplay(ar::IDisplay *ptr)
{
	delete ptr;
}
