//
// EPITECH PROJECT, 2018
// LaunchLibraries.hpp
// File description:
// LauncheLibraries
//

#ifndef CPP_ARCADE_LAUNCHLIBRARIES_HPP
#define CPP_ARCADE_LAUNCHLIBRARIES_HPP

#include "interfaces/IDisplay.hpp"
#include "interfaces/IGame.hpp"

namespace ar {
	class LaunchLibraries {
		public:
		static ar::IDisplay *LaunchLibs(const std::string &,
			void *&open
		);

		//Charge une librairie de jeu
		//Peux throw une execption
		static ar::IGame *LaunchGame(const std::string &,
			std::vector<void *> &open
		);
	};
}

#endif //CPP_ARCADE_LAUNCHLIBRARIES_HPP
