#include "ball.hpp"

namespace game
{
Object *Ball::nextMove(Game &game)
{
    int dx = m_dx;
    int dy = m_dy;
    if (m_x < 0 || m_x > game.width())
        dx = -dx;
    if (m_y < 0 || m_y > game.height())
        dy = -dy;

    auto *b = new Ball(m_x + dx, m_x + dy, m_radius, dx, dy);
    return b;
}

int Ball::x()
{
    return m_x;
};
int Ball::y()
{
    return m_y;
};

void Ball::render(sf::RenderWindow *window)
{
    sf::CircleShape shape(m_radius);
    shape.setFillColor(sf::Color::Magenta);
    shape.setScale(1.f, 1.f);
    shape.setPosition(m_x, m_y);
    window->draw(shape);
}

} // namespace game
