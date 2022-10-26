#pragma once

#ifndef PLANETARYHANDLER_H
#define PLANETARYHANDLER_H

#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <time.h>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"

class PlanetaryHandler
{
public:
	PlanetaryHandler(int r, int posX, int posY, double mass, double initialV, float angle, sf::Color color);
	PlanetaryHandler();
	virtual ~PlanetaryHandler();

	void createPlanet(int r, int posX, int posY, double mass, double initialV, float angle, sf::Color color);
	void applyGravity();
	
	void render(sf::RenderWindow& window);
	void renderPath(sf::RenderWindow& window);

private:
	std::vector<sf::CircleShape> planets;
	std::vector<sf::CircleShape> path;
	std::vector<sf::Vector2f> velocities;
	std::vector<sf::Vector2f> accelerations;
	std::vector<double>	m_mass;


	const double G = 6.6742E-11;
};

#endif