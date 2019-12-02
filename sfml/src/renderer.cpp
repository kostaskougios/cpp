#include "renderer.hpp"
#include <range/v3/algorithm/for_each.hpp>
#include "rendercontext.hpp"

namespace game {
	void Renderer::render(sf::RenderWindow *window, Game *game) {
		auto &state = game->getState();

		window->clear();

		RenderContext rc(*window, *game, textures);
		ranges::for_each(state, [&](Object *o) { o->render(rc); });
		window->display();
	}

} // namespace game
