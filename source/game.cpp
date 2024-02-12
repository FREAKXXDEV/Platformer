#include "game.h"

Game::Game()
	: window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Platformer", sf::Style::Close) 
	, view(sf::Vector2f(), sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT)) {

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

	// TODO: Update Game Objects

	view.setCenter(window.getSize().x / 2.0f, window.getSize().y / 2.0f);
	window.setView(view);
}

void Game::render() {
	window.clear();

	//TODO: Render Game Objects	
	window.display();
}

void Game::setupLevel() {
	// TODO
}