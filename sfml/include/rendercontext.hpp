#pragma once

#include <SFML/Graphics.hpp>
#include "textures.hpp"

namespace game {
	class Game;

	struct RenderContext {
		sf::RenderWindow &window;
		Game &game;
		Textures &textures;

		RenderContext(sf::RenderWindow &w, Game &g, Textures &t) : window(w), game(g), textures(t) {};
	};

} // namespace game
