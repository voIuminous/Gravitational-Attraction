#include "PlanetaryHandler.h"

// CONSTRUCTORS & DESTRUCTORS
PlanetaryHandler::PlanetaryHandler(int r, int posX, int posY, double mass, double initialV, float angle, sf::Color color)
{

	sf::CircleShape planet;
	planet.setRadius(r);
	planet.setPosition(posX, posY);
	planet.setOrigin(planet.getRadius(), planet.getRadius());
	planet.setFillColor(color);

	sf::Vector2f temp = sf::Vector2f(initialV * cos(angle), initialV * sin(angle));

	m_mass.push_back(mass);
	accelerations.push_back(sf::Vector2f(0, 0));
	velocities.push_back(temp);
	planets.push_back(planet);
}

PlanetaryHandler::PlanetaryHandler()
{
	sf::CircleShape planet;
	planet.setRadius(20);
	planet.setPosition(400, 400);
	planet.setOrigin(planet.getRadius(), planet.getRadius());

	sf::Vector2f temp = sf::Vector2f(0 * cos(0), 0 * sin(0));

	m_mass.push_back(3.14159265 * pow(planet.getRadius(), 2));
	accelerations.push_back(sf::Vector2f(0, 0));
	velocities.push_back(temp);
	planets.push_back(planet);
}

PlanetaryHandler::~PlanetaryHandler()
{

}

// PRIVATE FUNCTIONS

// PUBLIC FUNCTIONS
void PlanetaryHandler::createPlanet(int r, int posX, int posY, double mass, double initialV, float angle, sf::Color color)
{
	
	sf::CircleShape planet;
	planet.setRadius(r);
	planet.setPosition(posX, posY);
	planet.setOrigin(planet.getRadius(), planet.getRadius());
	planet.setFillColor(color);

	sf::Vector2f temp = sf::Vector2f(initialV * cos(angle), initialV * sin(angle));

	m_mass.push_back(mass);
	accelerations.push_back(sf::Vector2f(0, 0));
	velocities.push_back(temp);
	planets.push_back(planet);
}

void PlanetaryHandler::applyGravity()
{
	for (int i = 0; i < planets.size(); i++)
	{
		for (int j = 0; j < planets.size(); j++)
		{
			if (i != j)
			{
				double distanceBetweenX = planets[j].getPosition().x - planets[i].getPosition().x;
				double distanceBetweenY = planets[j].getPosition().y - planets[i].getPosition().y;

				double distanceBetween = sqrt(pow(distanceBetweenX, 2) + pow(distanceBetweenY, 2));

				double angle = 180 * atan(distanceBetweenY / distanceBetweenX) / 3.14159265359;

				double F = (G * m_mass[i] * m_mass[j]) / pow(distanceBetween, 2);

				// if the value gets below 1 or -1 (ex: 0.05) the force will act really weird
				if (distanceBetweenX >= 1 || distanceBetweenX <= -1)
				{
					this->accelerations[i].x = m_mass[j] / m_mass[i] * F * distanceBetweenX;
				}
				if (distanceBetweenY >= 1 || distanceBetweenY <= -1)
				{
					this->accelerations[i].y = m_mass[j] / m_mass[i] * F * distanceBetweenY;
				}

				velocities[i].x += accelerations[i].x;
				velocities[i].y += accelerations[i].y;

				//std::cout << distanceBetweenX << "    " << distanceBetweenY << '\n';
				// std::cout << accelerations[i].x << "             " << accelerations[i].y << std::endl;

				sf::CircleShape pathObj;
				pathObj.setFillColor(sf::Color(255, 255, 255));
				pathObj.setRadius(5);
				pathObj.setOrigin(pathObj.getRadius(), pathObj.getRadius());
				pathObj.setPosition(planets[i].getPosition().x, planets[i].getPosition().y);

				path.push_back(pathObj);

				planets[i].move(velocities[i].x, velocities[i].y);
			}
		}
	}
}

void PlanetaryHandler::render(sf::RenderWindow& window)
{
	for (int i = 0; i < planets.size(); i++)
	{
		window.draw(this->planets[i]);
	}
}

void PlanetaryHandler::renderPath(sf::RenderWindow& window)
{
	int counter = 0;
	for (int i = 0; i < path.size(); i++)
	{
		counter++;
		if (counter % 10 == 0)
		{
			window.draw(this->path[i]);

		}
	}
}
