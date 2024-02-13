#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <settings.h>
#include <tile.h>
#include <player.h>
#include <collider.h>

class Game {
public:
	Game();
	void run(const float framesPerSecond);

private:
	void processEvents();
	void update(sf::Time time);
	void render();
	void setupLevel();
	void checkCollisions();

private:
	sf::RenderWindow window;
	sf::View view;
	
	std::vector<Tile*> tiles;
	Player *player;

	sf::Texture playerTexture;
};
