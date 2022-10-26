#include <iostream>

#include "SystemState.h"

int main() 
{
	SystemState engine;

	while (engine.running())
	{
		// UPDATE
		engine.update();

		// RENDER
		engine.render();
	}

	return 0;
}