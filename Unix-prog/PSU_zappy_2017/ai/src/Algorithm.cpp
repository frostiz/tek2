/*
** EPITECH PROJECT, 2018
** ai
** File description:
** Algorithm.cpp
*/

#include "CommandHandler.hpp"
#include "Algorithm.hpp"
#include "Moves.hpp"
#include "ParseUtils.hpp"

Algorithm::Algorithm(Ai *ai)
	: _ai(ai)
{
	_focus = NONE;
	_food = 9;
	_linemate = 0;
	_deraumere = 0;
	_sibur = 0;
	_mendiane = 0;
	_phiras = 0;
	_thystame = 0;
	_timeLeft = 126;
	_elevationLevel = 1;
	_ai->setLvl(_elevationLevel);	
	_foodFocus = 10;
	_changeMove = 0;
	_forkTimer = 0;
	_newFork = 0;
	_cmd = new CommandHandler(_ai);
	initVector();
	initMap();
	initInventory();
	initIncantation();
}

void 	Algorithm::initInventory() {
	_invKeys["food"] = std::bind(&Algorithm::setFood, this, std::placeholders::_1);
	_invKeys["linemate"] = std::bind(&Algorithm::setLinemate, this, std::placeholders::_1);
	_invKeys["deraumere"] = std::bind(&Algorithm::setDeraumere, this, std::placeholders::_1);
	_invKeys["sibur"] = std::bind(&Algorithm::setSibur, this, std::placeholders::_1);
	_invKeys["mendiane"] = std::bind(&Algorithm::setMendiane, this, std::placeholders::_1);
	_invKeys["phiras"] = std::bind(&Algorithm::setPhiras, this, std::placeholders::_1);
	_invKeys["thystame"] = std::bind(&Algorithm::setThystame, this, std::placeholders::_1);
}

void 	Algorithm::initVector()
{
	_gets.push_back(std::bind(&::Algorithm::getLinemate,this));
	_gets.push_back(std::bind(&::Algorithm::getDeraumere, this));
	_gets.push_back(std::bind(&::Algorithm::getSibur, this));
	_gets.push_back(std::bind(&::Algorithm::getMendiane, this));
	_gets.push_back(std::bind(&::Algorithm::getPhiras, this));
	_gets.push_back(std::bind(&::Algorithm::getThystame, this));
	_opts.push_back(std::bind(&::Algorithm::optLinemate,this));
	_opts.push_back(std::bind(&::Algorithm::optDeraumere, this));
	_opts.push_back(std::bind(&::Algorithm::optSibur, this));
	_opts.push_back(std::bind(&::Algorithm::optMendiane, this));
	_opts.push_back(std::bind(&::Algorithm::optPhiras, this));
	_opts.push_back(std::bind(&::Algorithm::optThystame, this));
}

void 	Algorithm::initMap()
{
	_resourcesString[Resources::FOOD] = "food";
	_resourcesString[Resources::LINEMATE] = "linemate";
	_resourcesString[Resources::DERAUMERE] = "deraumere";
	_resourcesString[Resources::SIBUR] = "sibur";
	_resourcesString[Resources::MENDIANE] = "mendiane";
	_resourcesString[Resources::PHIRAS] = "phiras";
	_resourcesString[Resources::THYSTAME] = "thystame";
	_resourcesAdd[Resources::FOOD] = std::bind(&Algorithm::addFood, this);
	_resourcesAdd[Resources::LINEMATE] = std::bind(&Algorithm::addLinemate, this);
	_resourcesAdd[Resources::DERAUMERE] = std::bind(&Algorithm::addDeraumere, this);
	_resourcesAdd[Resources::SIBUR] = std::bind(&Algorithm::addSibur, this);
	_resourcesAdd[Resources::MENDIANE] = std::bind(&Algorithm::addMendiane, this);
	_resourcesAdd[Resources::PHIRAS] = std::bind(&Algorithm::addPhiras, this);
	_resourcesAdd[Resources::THYSTAME] = std::bind(&Algorithm::addThystame, this);
}

void 	Algorithm::initIncantation()
{
	_setElevation[1] = std::bind(&Algorithm::elevationOne, this);
	_setElevation[2] = std::bind(&Algorithm::elevationTwo, this);
	_setElevation[3] = std::bind(&Algorithm::elevationThree, this);
	_setElevation[4] = std::bind(&Algorithm::elevationFour, this);
	_setElevation[5] = std::bind(&Algorithm::elevationFive, this);
	_setElevation[6] = std::bind(&Algorithm::elevationSix, this);
	_setElevation[7] = std::bind(&Algorithm::elevationSeven, this);
	_canElevation[1] = std::bind(&Algorithm::canElevationOne, this);
	_canElevation[2] = std::bind(&Algorithm::canElevationTwo, this);
	_canElevation[3] = std::bind(&Algorithm::canElevationThree, this);
	_canElevation[4] = std::bind(&Algorithm::canElevationFour, this);
	_canElevation[5] = std::bind(&Algorithm::canElevationFive, this);
	_canElevation[6] = std::bind(&Algorithm::canElevationSix, this);
	_canElevation[7] = std::bind(&Algorithm::canElevationSeven, this);
}

int	Algorithm::getFood() const
{
	return _food;
}

int	Algorithm::getLinemate() const
{
	return _linemate;
}

int	Algorithm::getDeraumere() const
{
	return _deraumere;
}

int	Algorithm::getSibur() const
{
	return _sibur;
}

int	Algorithm::getMendiane() const
{
	return _mendiane;
}

int	Algorithm::getPhiras() const
{
	return _phiras;
}

int	Algorithm::getThystame() const
{
	return _thystame;
}

void	Algorithm::setFood(int value)
{
	_food = value;
}

void	Algorithm::setLinemate(int value)
{
	_linemate = value;
}

void	Algorithm::setDeraumere(int value)
{
	_deraumere = value;
}

void	Algorithm::setSibur(int value)
{
	_sibur = value;
}

void	Algorithm::setMendiane(int value)
{
	_mendiane = value;
}

void	Algorithm::setPhiras(int value)
{
	_phiras = value;
}

void	Algorithm::setThystame(int value)
{
	_thystame = value;
}

int	Algorithm::getNewFork() const
{
	return _newFork;
}

int	Algorithm::getElevationLevel() const
{
	return _elevationLevel;
}

void 	Algorithm::addFood() {
	_food++;
}

void 	Algorithm::addLinemate() {
	_linemate++;
}

void 	Algorithm::addDeraumere() {
	_deraumere++;
}

void 	Algorithm::addSibur() {
	_sibur++;
}

void 	Algorithm::addMendiane() {
	_mendiane++;
}

void 	Algorithm::addPhiras() {
	_phiras++;
}

void 	Algorithm::addThystame() {
	_thystame++;
}

void 	Algorithm::collect(Resources focus)
{
	_cmd->executeCommand(CommandType::TAKE, _resourcesString[focus]);
	_resourcesAdd[focus]();	
	_timeLeft -= 7;
	_forkTimer--;
	_focus = NONE;
}

void	Algorithm::optLinemate()
{
	if (_focus == NONE) {
		_focus = LINEMATE;
	}
}

void	Algorithm::optDeraumere()
{
	if (_focus == NONE) {
		_focus = DERAUMERE;
	}
}

void	Algorithm::optSibur()
{
	if (_focus == NONE) {
		_focus = SIBUR;
	}
}

void	Algorithm::optMendiane()
{
	if (_focus == NONE) {
		_focus = MENDIANE;
	}
}

void	Algorithm::optPhiras()
{
	if (_focus == NONE) {
		_focus = PHIRAS;
	}
}

void	Algorithm::optThystame()
{
	if (_focus == NONE) {
		_focus = THYSTAME;
	}
}

void 	Algorithm::findAction()
{
	if (_food < _foodFocus) {
		_focus = FOOD;
	} else {
		int i = 0;
		int val = 100;
		int save = 0;
		int tmp = 0;

		for (auto current : _gets) {
			tmp = current();
			if (tmp < val) {
				val = tmp;
				if (i != 5 || (i == 5 && getThystame() < 1))
					save = i;
			}
			i++;
		}
		if (getSibur() > 10)
			_focus = FOOD;
		else
			_opts[save]();
	}
}

void 	Algorithm::checkEat()
{
	while (_timeLeft <= 0) {
		if (_food > 0) {
			_food--;
			_timeLeft += 126;
		} else {
			_ai->setDead(true);
			break;
		}
	}
}

void 	Algorithm::goToFocus()
{
	Moves *moves = new Moves(_ai);
	int value = this->findFocus();
	while (value == -1) {
		if (_changeMove == 5) {
			_cmd->executeCommand(CommandType::RIGHT);
			_cmd->executeCommand(CommandType::FORWARD);
			_cmd->executeCommand(CommandType::FORWARD);
			_cmd->executeCommand(CommandType::LEFT);
			_changeMove = 0;
			_timeLeft -= 28;
			_forkTimer -= 4;
		}
		_cmd->executeCommand(CommandType::FORWARD);
		_timeLeft -= 7;
		_forkTimer--;
		value = this->findFocus();
		_changeMove++;
	}
	int time = moves->moveTo(value);
	_changeMove++;
	_timeLeft -= time;
	_forkTimer -= time / 7;
}

int 	Algorithm::findFocus()
{
	CommandReturn *cmdReturn = new CommandReturn();
	cmdReturn = _cmd->look();
	_timeLeft -= 7;
	_forkTimer--;
	if (_food < _foodFocus)
		_focus = FOOD;
	std::vector<std::vector<std::string>> indexes = cmdReturn->getIndexes();
	for (unsigned int i = 0; i < indexes.size(); i++) {
		for (auto current : indexes.at(i)) {
			if (current == _resourcesString[_focus])
				return i;
		}
	}
	return -1;
}

void 	Algorithm::clearLinemate()
{
	_cmd->executeCommand(CommandType::TAKE, _resourcesString[LINEMATE]);
	_forkTimer--;
	while (_ai->getStatus() != KO) {
		_cmd->executeCommand(CommandType::TAKE, _resourcesString[LINEMATE]);
		_forkTimer--;
	}
}

void 	Algorithm::clearDeraumere()
{
	_cmd->executeCommand(CommandType::TAKE, _resourcesString[DERAUMERE]);
	_forkTimer--;
	while (_ai->getStatus() == OK) {
		_cmd->executeCommand(CommandType::TAKE, _resourcesString[DERAUMERE]);
		_forkTimer--;
	}
}

void 	Algorithm::clearSibur()
{
	_cmd->executeCommand(CommandType::TAKE, _resourcesString[SIBUR]);
	_forkTimer--;
	while (_ai->getStatus() == OK) {
		_cmd->executeCommand(CommandType::TAKE, _resourcesString[SIBUR]);
		_forkTimer--;
	}
}

void 	Algorithm::clearMendiane()
{
	_cmd->executeCommand(CommandType::TAKE, _resourcesString[MENDIANE]);
	_forkTimer--;
	while (_ai->getStatus() == OK) {
		_cmd->executeCommand(CommandType::TAKE, _resourcesString[MENDIANE]);
		_forkTimer--;
	}
}

void 	Algorithm::clearPhiras()
{
	_cmd->executeCommand(CommandType::TAKE, _resourcesString[PHIRAS]);
	_forkTimer--;
	while (_ai->getStatus() == OK) {
		_cmd->executeCommand(CommandType::TAKE, _resourcesString[PHIRAS]);
		_forkTimer--;
	}
}

void 	Algorithm::clearThystame()
{
	_cmd->executeCommand(CommandType::TAKE, _resourcesString[THYSTAME]);
	_forkTimer--;
	while (_ai->getStatus() == OK) {
		_cmd->executeCommand(CommandType::TAKE, _resourcesString[THYSTAME]);
		_forkTimer--;
	}
}

void 	Algorithm::clearMap()
{
	clearLinemate();
	clearDeraumere();
	clearSibur();
	clearMendiane();
	clearPhiras();
	clearThystame();

}

int 	Algorithm::canElevationOne() const
{
	if (getLinemate() >= 1 && _newFork >= 0 && _food >= _foodFocus) {
		return 0;
	}
	return 1;
}

void 	Algorithm::setIncantationOne()
{
	_cmd->executeCommand(CommandType::SET, _resourcesString[LINEMATE]);
}

void 	Algorithm::elevationOne()
{
	clearMap();
	setIncantationOne();
	_cmd->executeCommand(INCANTATION);
	if (_ai->getStatus() != KO) {
		_elevationLevel++;
		_forkTimer -= 42;
		_ai->setLvl(_elevationLevel);
	} else {
		clearMap();
	}
}

int 	Algorithm::canElevationTwo() const
{
	if (getLinemate() >= 1 && getDeraumere() >= 1 &&
		getSibur() >= 1 && _newFork >= 1 && _food >= _foodFocus) {
		_ai->setIncantationState(Incantation::READY);
		_cmd->sendReady();
		return 0;
	}
	return 1;
}

void 	Algorithm::setIncantationTwo()
{
	_cmd->executeCommand(CommandType::SET, _resourcesString[LINEMATE]);
	_cmd->executeCommand(CommandType::SET, _resourcesString[DERAUMERE]);
	_cmd->executeCommand(CommandType::SET, _resourcesString[SIBUR]);
}

void 	Algorithm::elevationTwo()
{
	clearMap();
	setIncantationTwo();
	_cmd->executeCommand(INCANTATION);
	if (_ai->getStatus() != KO) {
		_elevationLevel++;
		_forkTimer -= 42;
		_ai->setLvl(_elevationLevel);
	} else {
		clearMap();
	}
}

int 	Algorithm::canElevationThree() const
{
	if (getLinemate() >= 2 && getSibur() >= 1 &&
		getPhiras() >= 2 && _newFork >= 1 && _food >= _foodFocus) {
		return 0;
	}
	return 1;
}

void 	Algorithm::setIncantationThree()
{
	_cmd->executeCommand(CommandType::SET, _resourcesString[LINEMATE]);
	_cmd->executeCommand(CommandType::SET, _resourcesString[LINEMATE]);
	_cmd->executeCommand(CommandType::SET, _resourcesString[SIBUR]);
	_cmd->executeCommand(CommandType::SET, _resourcesString[PHIRAS]);
	_cmd->executeCommand(CommandType::SET, _resourcesString[PHIRAS]);
}

void 	Algorithm::elevationThree()
{
	setIncantationThree();
	_cmd->executeCommand(INCANTATION);
	if (_ai->getStatus() != KO) {
		_elevationLevel++;
		_forkTimer -= 42;
		_ai->setLvl(_elevationLevel);

	} else {
		clearMap();
	}
}

int 	Algorithm::canElevationFour() const
{
	if (getLinemate() >= 1 && getDeraumere() >= 1 &&
		getSibur() >= 2 && getPhiras() >= 1 &&
		_newFork >= 3 && _food >= _foodFocus) {
		return 0;
	}
	return 1;
}

void 	Algorithm::setIncantationFour()
{
	_cmd->executeCommand(CommandType::SET, _resourcesString[LINEMATE]);
	_cmd->executeCommand(CommandType::SET, _resourcesString[DERAUMERE]);
	_cmd->executeCommand(CommandType::SET, _resourcesString[SIBUR]);
	_cmd->executeCommand(CommandType::SET, _resourcesString[SIBUR]);
	_cmd->executeCommand(CommandType::SET, _resourcesString[PHIRAS]);
}

void 	Algorithm::elevationFour()
{
	setIncantationFour();
	_cmd->executeCommand(INCANTATION);
	if (_ai->getStatus() != KO) {
		_elevationLevel++;
		_forkTimer -= 42;
		_ai->setLvl(_elevationLevel);

	} else {
		clearMap();
	}
}

int 	Algorithm::canElevationFive() const
{
	if (getLinemate() >= 1 && getDeraumere() >= 2 &&
		getSibur() >= 1 && getMendiane() >= 3 &&
		_newFork >= 3 && _food >= _foodFocus) {
		return 0;
	}
	return 1;
}

void 	Algorithm::setIncantationFive()
{
	_cmd->executeCommand(CommandType::SET, _resourcesString[LINEMATE]);
	_cmd->executeCommand(CommandType::SET, _resourcesString[DERAUMERE]);
	_cmd->executeCommand(CommandType::SET, _resourcesString[DERAUMERE]);
	_cmd->executeCommand(CommandType::SET, _resourcesString[SIBUR]);
	_cmd->executeCommand(CommandType::SET, _resourcesString[MENDIANE]);
	_cmd->executeCommand(CommandType::SET, _resourcesString[MENDIANE]);
	_cmd->executeCommand(CommandType::SET, _resourcesString[MENDIANE]);
}

void 	Algorithm::elevationFive()
{
	setIncantationFive();
	_cmd->executeCommand(INCANTATION);
	if (_ai->getStatus() != KO) {
		_elevationLevel++;
		_forkTimer -= 42;
		_ai->setLvl(_elevationLevel);

	} else {
		clearMap();
	}

}

int 	Algorithm::canElevationSix() const
{
	if (getLinemate() >= 1 && getDeraumere() >= 2 &&
		getSibur() >= 3 && getPhiras() >= 1 &&
		_newFork >= 5 && _food >= _foodFocus) {
		return 0;
	}
	return 1;
}

void 	Algorithm::setIncantationSix()
{
	_cmd->executeCommand(CommandType::SET, _resourcesString[LINEMATE]);
	_cmd->executeCommand(CommandType::SET, _resourcesString[DERAUMERE]);
	_cmd->executeCommand(CommandType::SET, _resourcesString[DERAUMERE]);
	_cmd->executeCommand(CommandType::SET, _resourcesString[SIBUR]);
	_cmd->executeCommand(CommandType::SET, _resourcesString[SIBUR]);
	_cmd->executeCommand(CommandType::SET, _resourcesString[SIBUR]);
	_cmd->executeCommand(CommandType::SET, _resourcesString[PHIRAS]);
}

void 	Algorithm::elevationSix()
{
	setIncantationSix();
	_cmd->executeCommand(INCANTATION);
	if (_ai->getStatus() != KO) {
		_elevationLevel++;
		_forkTimer -= 42;
		_ai->setLvl(_elevationLevel);

	} else {
		clearMap();
	}
}

int 	Algorithm::canElevationSeven() const
{
	if (getLinemate() >= 2 && getDeraumere() >= 2 &&
		getSibur() >= 2 && getMendiane() >= 2 &&
		getPhiras() >= 2 && getThystame() >= 1 &&
		_newFork >= 5 && _food >= _foodFocus) {
		return 0;
	}
	return 1;
}

void 	Algorithm::setIncantationSeven()
{
	_cmd->executeCommand(CommandType::SET, _resourcesString[LINEMATE]);
	_cmd->executeCommand(CommandType::SET, _resourcesString[LINEMATE]);
	_cmd->executeCommand(CommandType::SET, _resourcesString[DERAUMERE]);
	_cmd->executeCommand(CommandType::SET, _resourcesString[DERAUMERE]);
	_cmd->executeCommand(CommandType::SET, _resourcesString[SIBUR]);
	_cmd->executeCommand(CommandType::SET, _resourcesString[SIBUR]);
	_cmd->executeCommand(CommandType::SET, _resourcesString[PHIRAS]);
	_cmd->executeCommand(CommandType::SET, _resourcesString[PHIRAS]);
	_cmd->executeCommand(CommandType::SET, _resourcesString[THYSTAME]);
}

void 	Algorithm::elevationSeven()
{
	setIncantationSeven();
	_cmd->executeCommand(INCANTATION);
	if (_ai->getStatus() != KO) {
		_elevationLevel++;
		_forkTimer -= 42;
		_ai->setLvl(_elevationLevel);

	} else {
		clearMap();
	}
}

void Algorithm::refreshInventory()
{
	ParseUtils parser = ParseUtils();
	std::vector<std::string> out = _cmd->inventory();
	_timeLeft--;
	for (auto current : out) {
		std::vector<std::string> tmp = parser.split(current, ' ');
		if (tmp.size() < 2)
			return;
		try {
			int value = std::stoi(tmp.at(1));
			if (_invKeys.find(tmp.at(0)) == _invKeys.end())
				return;
			_invKeys[tmp.at(0)](value);
		} catch (std::exception &e) {}
	}
}

void 	Algorithm::checkElevation()
{
	if (_ai->getDead() == false) {
		this->refreshInventory();
		if (_canElevation[_elevationLevel]() == 0) {
			_setElevation[_elevationLevel]();
			this->refreshInventory();
		}
	}
}

int 	Algorithm::getConnectNbr() const
{
	int value = _cmd->connectNbr();
	return value;
}

void 	Algorithm::checkFork()
{
	if (_food >= 2 && _forkTimer <= 0 && _newFork < getConnectNbr()) {
		_cmd->executeCommand(FORK);
		_forkTimer = 85;
		_timeLeft += 84;
		_food--;
		_newFork++;
	}
}

void 	Algorithm::live()
{
	while (_ai->getDead() == false) {
			checkEat();
			checkFork();
			findAction();
			if (_focus != NONE && _ai->getDead() == false) {
				goToFocus();
				collect(_focus);
			}
			checkElevation();
	}
}