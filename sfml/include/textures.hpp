#pragma once

#include <SFML/Graphics.hpp>

namespace game {
	class Textures {
	private:
		void loadFromFile(std::string, sf::Texture &);

	public:
		sf::Texture player1Texture;
		sf::Sprite player1;

		Textures();
	};

} // namespace game
