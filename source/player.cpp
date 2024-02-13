#include "player.h"

Player::Player(const float SIZE)
	: Tile(SIZE)
	, direction()
	, SPEED(300.f) 
	, GRAVITY(980.f) 
	, fallingTime(0.f) {

	rect.setSize(sf::Vector2f(64, 48));
}

void Player::update(float deltaTime) {
	getInput();
	move(deltaTime);

	std::cout << fallingTime << '\n';
}

void Player::getInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		direction.x = -1;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
		direction.x = 1;
	else direction.x = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		direction.y = -1;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		direction.y = 1;
	else direction.y = 0;
}

void Player::move(float deltaTime) {
	fallingTime += deltaTime;

	sf::Vector2f velocity(direction * SPEED * deltaTime);
	velocity.y += GRAVITY * fallingTime * deltaTime;
	if (velocity.y > GRAVITY)
		velocity.y = GRAVITY;

	rect.move(velocity);
}

