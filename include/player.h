#pragma once
#include <tile.h>
#include <filesystem>
#include <iostream>

class Player : public Tile {
public:
	Player(const float SIZE);
	void update(float deltaTime);
	void setTexture(sf::Texture &texture) { rect.setTexture(&texture); }
	void resetFallingTime() { fallingTime = 0.f; }

private:
	void getInput();
	void move(float deltaTime);

private:
	sf::Vector2f direction;

	const float SPEED;
	const float GRAVITY;

	float fallingTime;
};