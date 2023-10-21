/*
Write initials in a ball. The ball jumps in a loop.
*/

#include <SFML/Window.hpp>
#include "source.h"

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;

void pollEvents(sf::RenderWindow &window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        default:
            break;
        }
    }
}

void redrawFrame(sf::RenderWindow &window, const Ball &ball)
{
    window.clear(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(ball.shape);
    window.draw(ball.text);
    window.display();
}

int main()
{
    sf::Clock clock;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Jumping ball", sf::Style::Default, settings);

    Ball ball;
    initBall(ball);

    while (window.isOpen())
    {
        pollEvents(window);
        update(ball, clock);
        redrawFrame(window, ball);
    }
}