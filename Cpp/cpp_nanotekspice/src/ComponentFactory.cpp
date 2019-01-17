/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** cpp_nanotekspice file
*/

#include "ComponentFactory.hpp"

nts::ComponentFactory::ComponentFactory()
	: _actions(
	{
		{"input", [this](const std::string &value) { return createInput(value); }},
		{"output", [this](const std::string &value) { return createOutput(value); }},
		{"4081", [this](const std::string &value) { return create4081(value); }},
		{"4071", [this](const std::string &value) { return create4071(value); }},
		{"4069", [this](const std::string &value) { return create4069(value); }},
		{"4030", [this](const std::string &value) { return create4030(value); }},
		{"4001", [this](const std::string &value) { return create4001(value); }},
		{"4011", [this](const std::string &value) { return create4011(value); }},
		{"true", [this](const std::string &value) { return createTrue(value); }},
		{"false", [this](const std::string &value) { return createFalse(value); }},
		{"clock", [this](const std::string &value) { return createClock(value); }},
	}
)
{

}

nts::ComponentFactory::~ComponentFactory()
{

}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::createComponent(const std::string &type, const std::string &value) {
	return _actions[type](value);
}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::createOutput(const std::string &value) const noexcept
{
	return std::unique_ptr<nts::IComponent>(new Output(value));
}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::create4081(const std::string &value) const noexcept
{
	return std::unique_ptr<nts::IComponent>(new c4081(value));
}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::create4071(const std::string &value) const noexcept
{
	return std::unique_ptr<nts::IComponent>(new c4071(value));
}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::create4069(const std::string &value) const noexcept
{
	return std::unique_ptr<nts::IComponent>(new c4069(value));
}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::create4030(const std::string &value) const noexcept
{
	return std::unique_ptr<nts::IComponent>(new c4030(value));
}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::create4001(const std::string &value) const noexcept
{
	return std::unique_ptr<nts::IComponent>(new c4001(value));
}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::create4011(const std::string &value) const noexcept
{
	return std::unique_ptr<nts::IComponent>(new c4011(value));
}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::createInput(const std::string &value) const noexcept
{
	return std::unique_ptr<nts::IComponent>(new Input(value));
}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::createTrue(const std::string &value) const noexcept
{
	return std::unique_ptr<nts::IComponent>(new True(value));
}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::createFalse(const std::string &value) const noexcept
{
	return std::unique_ptr<nts::IComponent>(new False(value));
}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::createClock(const std::string &value) const noexcept
{
	return std::unique_ptr<nts::IComponent>(new Clock(value));
}
