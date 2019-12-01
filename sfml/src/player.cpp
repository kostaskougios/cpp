#include "player.hpp"

namespace game
{
void Player::render(sf::RenderWindow *window)
{
}

Object *Player::nextMove(Game &)
{
    return new Player(m_x, m_y);
}

} // namespace game
