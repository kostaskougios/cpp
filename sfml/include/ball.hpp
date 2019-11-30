#pragma once

#include "object.hpp"
#include "game.hpp"

namespace game
{
class Ball : public Object
{
private:
    int m_x;
    int m_y;
    int m_radius;
    int m_dx;
    int m_dy;

public:
    Ball(int x, int y, int radius, int dx, int dy) : m_x(x), m_y(y), m_radius(radius), m_dx(dx), m_dy(dy){};

    int x();
    int y();

    Object *nextMove(Game &game);

    void render(sf::RenderWindow *);
};

} // namespace game