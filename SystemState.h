#pragma once

#ifndef SYSTEMSTATE_H
#define SYSTEMSTATE_H

#include <memory>
#include <fstream>
#include <iostream>
#include <string>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"

#include "PlanetaryHandler.h"

class SystemState
{
public:
	// CONSTRUCTOR -- DECONSTRUCTOR
	SystemState();
	virtual ~SystemState();

	// ACCESSORS
	const bool running() const;

	// PUBLIC FUNCTIONS
	void pollEvents();
	void update();
	void render();

private:
	// PRIVATE VARIABLES
	std::unique_ptr<sf::RenderWindow> window; // pointer because we want to be able to delete it when we want so we dynamically allocate it.
	sf::VideoMode videoMode;
	sf::Event ev;

	std::unique_ptr<PlanetaryHandler> Planets;

	// PRIVATE FUNCTIONS
	void initVariables();
	void initWindow();
};

#endif