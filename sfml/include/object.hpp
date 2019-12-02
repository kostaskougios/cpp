#pragma once

#include <SFML/Graphics.hpp>
#include "game.hpp"
#include "rendercontext.hpp"

namespace game {
	class Game;

	class Object {
	public:
		virtual ~Object() {};

		virtual void render(RenderContext &context) = 0;

		virtual Object *nextMove(Game &game) = 0;
	};
} // namespace game