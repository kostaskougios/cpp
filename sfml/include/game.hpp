#pragma once

#include <vector>
#include "object.hpp"
#include "textures.hpp"

namespace game {

	class Object;

	class Game {
	private:
		int m_width;
		int m_height;
		std::vector<Object *> m_state;
		Textures *m_textures;

	public:
		Game(std::vector<Object *> state, int width, int height, Textures *textures) : m_width(width), m_height(height),
																					   m_state(state),
																					   m_textures(textures) {};

		~Game();

		std::vector<Object *> &getState();

		Game *nextMove();

		int width();

		int height();
	};

} // namespace game