#include "tile.h"

Tile::Tile(const float TILE_SIZE)
	: rect(sf::Vector2f(TILE_SIZE, TILE_SIZE)) {

}

void Tile::draw(sf::RenderWindow &window) {
	window.draw(rect);
}