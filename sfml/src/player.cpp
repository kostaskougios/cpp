#include <iostream>
#include "player.hpp"

namespace game {
	void Player::render(RenderContext &context) {
		sf::Sprite &sprite = context.textures.player1;
		sprite.setPosition(sf::Vector2f(m_x, m_y));
		context.window.draw(sprite);
	}

	Object *Player::nextMove(Game &game) {
		sf::Joystick::update();
		float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X) / 10;
		float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y) / 10;

		int newX = m_x + x;
		int newY = m_y + y;
		if (newX < 0) newX = 0;
		if (newX > game.width() - 50) newX = game.width() - 50;
		if (newY < 0) newY = 0;
		if (newY > game.height() - 50) newY = game.height() - 50;

		return new Player(newX, newY);
	}

} // namespace game
