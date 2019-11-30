#include "ball.hpp"

namespace game
{
Ball Ball::move(int dx, int dy)
{
    return Ball(m_x + dx, m_x + dy, m_radius);
}

void Ball::render(sf::RenderWindow *window)
{
    sf::CircleShape shape(m_radius);
    shape.setFillColor(sf::Color::Magenta);
    shape.setScale(1.f, 1.f);
    window->draw(shape);
}

} // namespace game
