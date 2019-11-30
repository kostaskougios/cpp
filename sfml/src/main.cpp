#include <iostream>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "renderer.hpp"

using namespace game;

int main()
{
    int Width = 1024;
    int Height = 768;
    int Radius = 20;
    sf::RenderWindow window(sf::VideoMode(Width, Height), "Silly game production");
    window.setFramerateLimit(240);

    Renderer renderer();
    auto b = new Ball(0, 0, Radius);
    Game game(std::vector<Object *>{b});

    int dx = 1;
    int dy = 1;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        renderer.render(&window, game);
        if (b->x() < 0 || b->x() > Width - Radius)
            dx = -dx;
        if (b->y() < 0 || b->y() > Height - Radius)
            dy = -dy;
    }

    return 0;
}