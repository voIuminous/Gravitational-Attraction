#include "SystemState.h"

// PRIVATE FUNCTIONS
void SystemState::initVariables()
{
	this->window = nullptr;

	this->Planets.reset(new PlanetaryHandler(60, 500, 360, 33000, 0.0, -180, sf::Color::Red));
	//Planets->createPlanet(10, 600, 250, 4000, 0.45, 50, sf::Color::Magenta);
	Planets->createPlanet(5, 300, 500, 2000, 0.5, 60, sf::Color::White);
	//Planets->createPlanet(60, 800, 360, 33000, 0.0, 30, sf::Color::Blue);
}

void SystemState::initWindow()
{
	this->videoMode.height = 720;
	this->videoMode.width = 1024;
	this->window.reset(new sf::RenderWindow(this->videoMode, "Gravity"));
}

// CONSTRUCTORS - DESTRUCTORS
SystemState::SystemState()
{
	this->initVariables();
	this->initWindow();
}

SystemState::~SystemState()
{

}

// ACCESSORS
const bool SystemState::running() const
{
	return this->window->isOpen();
}

// PUBLIC FUNCTIONS
void SystemState::pollEvents() {
	while (this->window->pollEvent(ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		}
	}
}

void SystemState::update()
{
	this->pollEvents();
	this->Planets->applyGravity();

	sf::Vector2i mousePos = sf::Mouse::getPosition(*this->window);
	sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

	this->window->setFramerateLimit(144);
}

void SystemState::render()
{
	this->window->clear(sf::Color::Black);

	// DRAW OBJECTS v
	Planets->renderPath(*window);
	Planets->render(*window);

	this->window->display();
}