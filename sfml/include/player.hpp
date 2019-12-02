#pragma once

#include "object.hpp"

namespace game {

	class Player : public Object {
	private:
		int m_x;
		int m_y;
		float m_scale;
		float m_dScale;

	public:
		Player(int x, int y, float scale = 1, float dScale = 0.005) : m_x(x), m_y(y), m_scale(scale),
																	  m_dScale(dScale) {};

		void render(RenderContext &context);

		Object *nextMove(Game &);
	};

} // namespace game