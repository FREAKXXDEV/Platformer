#include "game.h"

Game::Game()
	: window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Platformer", sf::Style::Close) 
	, view(sf::Vector2f(), sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT)) 
	, player(new Player(TILE_SIZE)) {

	playerTexture.loadFromFile("graphics/player.png");
	setupLevel();
}

void Game::run(const float framesPerSecond) {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time TimePerFrame = sf::seconds(1.f / framesPerSecond);
	while (window.isOpen())
	{
		processEvents();
		bool canRender = false;
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			canRender = true;
			update(TimePerFrame);
		}
		if (canRender)
			render();
	}
}

void Game::processEvents() {
	sf::Event evnt;

	while (window.pollEvent(evnt)) {
		switch (evnt.type) {
		case sf::Event::Closed:
			window.close();
			break;
		}
	}
}

void Game::update(sf::Time time) {
	float deltaTime = time.asSeconds();

	player->update(deltaTime);
	checkCollisions();

	view.setCenter(player->getPosition());
	window.setView(view);
}

void Game::render() {
	window.clear();

	for (auto it = tiles.begin(); it != tiles.end(); ++it)
		(*it)->draw(window);
	player->draw(window);
	window.display();
}

void Game::setupLevel() {
	for (size_t i = 0; i < map.size(); ++i) {
		for (size_t j = 0; j < map[i].size(); ++j) {
			float x = (float)j * TILE_SIZE;
			float y = (float)i * TILE_SIZE;

			if (map[i][j] == 'X') {
				Tile *tile = new Tile(TILE_SIZE);
				tile->setPosition(x, y);
				tiles.push_back(tile);
			}
			if (map[i][j] == 'P') {
				Player *player = new Player(TILE_SIZE);
				player->setPosition(x, y);
				player->setTexture(playerTexture);
				this->player = player;
			}
		}
	}
}

void Game::checkCollisions() {
	for (auto it = tiles.begin(); it != tiles.end(); ++it) {
		Collider playerCollider = player->getCollider();
		Collider tileCollider = (*it)->getCollider();
		playerCollider.onCollision(tileCollider);
	}
}