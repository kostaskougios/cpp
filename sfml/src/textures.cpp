#include "textures.hpp"
#include <exception>

namespace game {
	Textures::Textures() {
		loadFromFile("textures/kostas.png", player1Texture);
		player1.setTexture(player1Texture);
	}

	void Textures::loadFromFile(std::string file, sf::Texture &t) {
		if (!t.loadFromFile("textures/kostas.png"))
			throw std::exception();
	}

} // namespace game