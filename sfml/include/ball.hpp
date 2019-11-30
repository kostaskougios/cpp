#pragma once

#include "object.hpp"

namespace game
{
class Ball : public Object
{
private:
    int m_x;
    int m_y;
    int m_radius;

public:
    Ball(int x, int y, int radius) : m_x(x), m_y(y), m_radius(radius){};

    Ball move(int, int);

    void render(sf::RenderWindow *);
};

} // namespace game