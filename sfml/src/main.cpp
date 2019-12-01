#include <iostream>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "player.hpp"
#include "renderer.hpp"

using namespace game;

int main()
{
    int Width = 1024;
    int Height = 768;
    int Radius = 20;
    sf::RenderWindow window(sf::VideoMode(Width, Height), "Silly game productions");
    window.setFramerateLimit(240);

    Renderer renderer;
    auto *game = new Game(std::vector<Object *>{
                              new Player(Width / 2, Height / 2),
                              new Ball(0, 0, Radius, 1, 1)},
                          Width, Height);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        renderer.render(&window, game);
        auto *g = game->nextMove();
        delete game;
        game = g;
    }

    return 0;
}