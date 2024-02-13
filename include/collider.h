#pragma once
#include <SFML/Graphics.hpp>

class Collider {
public:
	Collider(sf::RectangleShape &rect);
	bool onCollision(Collider other);

private:
	sf::RectangleShape &rect;
};