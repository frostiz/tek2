//
// EPITECH PROJECT, 2018
// Core.hpp
// File description:
// Core
//

#ifndef CPP_ARCADE_CORE_HPP
#define CPP_ARCADE_CORE_HPP

#include <iostream>
#include "coreProgram/Menu.hpp"
#include "coreProgram/Game.hpp"

namespace ar {
	class Core {
		public:
		Core(const char *arg);
		~Core();

		bool CoreFunction();

		private:
		Event Menu();

		bool Game(ar::Event &event);

		ar::Menu _menu;
		ar::Game _game;

		std::string _arg;
	};
}

#endif //CPP_ARCADE_CORE_HPP
