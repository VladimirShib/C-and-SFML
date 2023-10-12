// Draw an arrow with outline

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

struct Arrow
{
    sf::ConvexShape shape;
    sf::Vector2f position = {400, 300};
};

void initArrow(Arrow &arrow)
{
    //arrow.position = {400, 300};

    arrow.shape.setPosition(arrow.position);
    arrow.shape.setPointCount(7);
    arrow.shape.setPoint(0, {0, -25});
    arrow.shape.setPoint(1, {0, -50});
    arrow.shape.setPoint(2, {50, 0});
    arrow.shape.setPoint(3, {0, 50});
    arrow.shape.setPoint(4, {0, 25});
    arrow.shape.setPoint(5, {-50, 25});
    arrow.shape.setPoint(6, {-50, -25});
    arrow.shape.setFillColor(sf::Color(0xFF, 0xFF, 0));
    arrow.shape.setOutlineColor(sf::Color(0, 0, 0));
    arrow.shape.setOutlineThickness(2);
}

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

void redrawFrame(sf::RenderWindow &window, Arrow &arrow)
{
    window.clear(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(arrow.shape);
    window.display();
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Arrow", sf::Style::Default, settings);

    Arrow arrow;

    initArrow(arrow);
    while (window.isOpen())
    {
        pollEvents(window);
        redrawFrame(window, arrow);
    }
}