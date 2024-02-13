#include "player.h"

Player::Player(const float SIZE) 
	: Tile(SIZE)
	, velocity()
	, direction()
	, SPEED(300.f)
	, GRAVITY(980.f)
	, fallingTime(0.f) 
	, isGrounded(false) {

	rect.setSize(sf::Vector2f(64, 48));
}

void Player::update(float deltaTime) {
	getInput();
	move(deltaTime);
}

void Player::getInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		direction.x = -1;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
		direction.x = 1;
	else direction.x = 0;
}

void Player::move(float deltaTime) {
	velocity = sf::Vector2f(direction * SPEED * deltaTime);
	applyGravity(deltaTime);

	rect.move(velocity);
}

void Player::applyGravity(float deltaTime) {
	if (!isGrounded)
		fallingTime += deltaTime; 

	velocity.y += GRAVITY * fallingTime * deltaTime;
	if (velocity.y > 1.5f * GRAVITY)
		velocity.y = 1.5f * GRAVITY;
	isGrounded = false;
}
