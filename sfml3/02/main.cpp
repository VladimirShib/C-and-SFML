// Print mouse coordinates on click and release

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

// Опрашивает и обрабатывает доступные события в цикле
// Polls and handles available event in loop
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
        case sf::Event::MouseButtonPressed:
            std::cout << "Mouse pressed,"
                      << " x = " << event.mouseButton.x
                      << " y = " << event.mouseButton.y << "\n";
            break;
        case sf::Event::MouseButtonReleased:
            std::cout << "Mouse released,"
                      << " x = " << event.mouseButton.x
                      << " y = " << event.mouseButton.y << "\n";
            break;
        default:
            break;
        }
    }
}

// Рисует и выводит один кадр
// Draws and displays one frame
void redrawFrame(sf::RenderWindow &window)
{
    window.clear();
    window.display();
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Print mouse events");

    while (window.isOpen())
    {
        pollEvents(window);
        redrawFrame(window);
    }
}