#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Joystick.hpp>

#include "ball.hpp"
#include "player.hpp"
#include "renderer.hpp"
#include "textures.hpp"

using namespace game;

int main() {
	int Radius = 20;
	auto desktopVideoMode = sf::VideoMode::getFullscreenModes().front();
	int Width = desktopVideoMode.width;
	int Height = desktopVideoMode.height;
	sf::RenderWindow window(desktopVideoMode, "Silly game productions", sf::Style::Fullscreen);
	window.setFramerateLimit(240);

//    std::cout << sf::Joystick::isConnected(0) << std::endl;
//    std::cout << sf::Joystick::getButtonCount(0) << std::endl;
//    std::cout << sf::Joystick::hasAxis(0, sf::Joystick::X) << "|" << sf::Joystick::hasAxis(0, sf::Joystick::Y) << std::endl;
//    return 0;
	Renderer renderer;
	auto textures = new Textures();
	auto *game = new Game(
			std::vector<Object *>{
					new Player(Width / 2, Height / 2),
					new Ball(0, 0, Radius, 1, 1)},
			Width, Height, textures);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		renderer.render(&window, game);
		auto *g = game->nextMove();
		delete game;
		game = g;
	}

	return 0;
}