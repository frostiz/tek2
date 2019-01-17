/*
** EPITECH PROJECT, 2018
** ai
** File description:
** Algorithm.hpp
*/

#ifndef ALGORITHM_HPP_
#define ALGORITHM_HPP_

#include <vector>
#include <functional>
#include <map>
#include <string>
#include "Ai.hpp"

class Ai;
class CommandHandler;

class Algorithm {
public:
	enum Resources {
		FOOD,
		LINEMATE,
		DERAUMERE,
		SIBUR,
		MENDIANE,
		PHIRAS,
		THYSTAME,
		NONE
	};

	Algorithm(Ai *);
	~Algorithm() = default;
	int getFood() const;
	int getLinemate() const;
	int getDeraumere() const;
	int getSibur() const;
	int getMendiane() const;
	int getPhiras() const;
	int getThystame() const;
	int getNewFork() const;
	int getElevationLevel() const;
	void setFood(int);
	void setLinemate(int);
	void setDeraumere(int);
	void setSibur(int);
	void setMendiane(int);
	void setPhiras(int);
	void setThystame(int);
	void setNewFork(int);
	void setElevationLevel(int);
	void refreshInventory();
	void live();

private:
	void initVector();
	void initInventory();
	void initMap();
	void initIncantation();
	void optLinemate();
	void optDeraumere();
	void optSibur();
	void optMendiane();
	void optPhiras();
	void optThystame();
	void addFood();
	void addLinemate();
	void addDeraumere();
	void addSibur();
	void addMendiane();
	void addPhiras();
	void addThystame();
	void checkEat();
	void collect(Resources);
	void findAction();
	void goToFocus();
	void checkElevation();
	void elevationOne();
	void elevationTwo();
	void elevationThree();
	void elevationFour();
	void elevationFive();
	void elevationSix();
	void elevationSeven();
	void setIncantationOne();
	void setIncantationTwo();
	void setIncantationThree();
	void setIncantationFour();
	void setIncantationFive();
	void setIncantationSix();
	void setIncantationSeven();
	void checkFork();
	void clearLinemate();
	void clearDeraumere();
	void clearSibur();
	void clearMendiane();
	void clearPhiras();
	void clearThystame();
	void clearMap();
	int getConnectNbr() const;
	int canElevationOne() const;
	int canElevationTwo() const;
	int canElevationThree() const;
	int canElevationFour() const;
	int canElevationFive() const;
	int canElevationSix() const;
	int canElevationSeven() const;
	int findFocus();
	Resources					_focus;
	std::vector<std::function<int()>>		_gets;
	std::vector<std::function<void()>>		_opts;
	std::map<Resources, std::string> 		_resourcesString;
	std::map<Resources, std::function<void()>>	_resourcesAdd;
	std::map<int, std::function<void()>>		_setElevation;
	std::map<int, std::function<int()>>		_canElevation;
	std::map<std::string, std::function<void(int)>>	_invKeys;
	int 						_timeLeft;
	int 						_elevationLevel;
	int 						_food;
	int 						_linemate;
	int 						_deraumere;
	int 						_sibur;
	int 						_mendiane;
	int 						_phiras;
	int 						_thystame;
	int 						_foodFocus;
	int 						_forkTimer;
	int						_changeMove;
	int 						_newFork;
	Ai						*_ai;
	CommandHandler					*_cmd;
};

#endif /*ALGORITHM_HPP_*/