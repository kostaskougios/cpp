#include "player.hpp"

namespace game
{
void Player::render(RenderContext &context)
{
    sf::Sprite &sprite = context.textures.player1;
    sprite.setPosition(sf::Vector2f(100, 100));
    context.window.draw(sprite);
}

Object *Player::nextMove(Game &)
{
    return new Player(m_x, m_y);
}

} // namespace game
