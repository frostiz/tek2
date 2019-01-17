/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** cpp_nanotekspice file
*/

#ifndef CPP_NANOTEKSPICE_ENGINE_HPP
#define CPP_NANOTEKSPICE_ENGINE_HPP

namespace nts {
	class Engine
	{
		public:
		Engine(char **av);
		~Engine();

		void	start();
		private:
		char	**_args;
	};
}

#endif //CPP_NANOTEKSPICE_ENGINE_HPP
