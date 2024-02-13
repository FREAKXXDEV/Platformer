#pragma once
#include <SFML/Graphics.hpp>

class Tile {
public:
	Tile(const float TILE_SIZE);
	void draw(sf::RenderWindow &window);

	void setPosition(float x, float y) { rect.setPosition(x, y); }
	sf::Vector2f getPosition() { return rect.getPosition() + rect.getSize() / 2.0f; }

protected:
	sf::RectangleShape rect;
};