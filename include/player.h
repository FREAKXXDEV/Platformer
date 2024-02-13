#pragma once
#include <tile.h>
#include <filesystem>
#include <iostream>

class Player : public Tile {
public:
	Player(const float SIZE);
	void update(float deltaTime);
	void setTexture(sf::Texture &texture) { rect.setTexture(&texture); }

	void applyGravity(float deltaTime);
	void resetFallingTime() { fallingTime = 0.f; }
	void grounded(bool isGrounded) { this->isGrounded = isGrounded; }

private:
	void getInput();
	void move(float deltaTime);

private:
	sf::Vector2f velocity;
	sf::Vector2f direction;
	const float SPEED;

	const float GRAVITY;
	float fallingTime;
	bool isGrounded;
};