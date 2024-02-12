#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <settings.h>

class Game {
public:
	Game();
	void run(const float framesPerSecond);

private:
	void processEvents();
	void update(sf::Time time);
	void render();
	void setupLevel();

private:
	sf::RenderWindow window;
	sf::View view;
};
