// Draw a flower in one go. Radius is defined by formula.

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;

int main()
{
    constexpr int pointCount = 200;
    const sf::Vector2f center = {400, 300};
    const int rotationRadius = 50;
    const int angleSpeed = 3;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Polar Rose",
        sf::Style::Default, settings);

    sf::Clock clock;

    sf::ConvexShape flower;
    flower.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));

    flower.setPointCount(pointCount);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        const float time = clock.getElapsedTime().asSeconds();
        const float x = rotationRadius * std::cos(time * angleSpeed);
        const float y = rotationRadius * std::sin(time * angleSpeed);
        const sf::Vector2f offset = {x, y};
        flower.setPosition(center + offset);

        for (int pointNo = 0; pointNo < pointCount; ++pointNo)
        {
            float angle = float(2 * M_PI * pointNo) / float(pointCount);
            float flowerRadius = 200 * std::sin(6 * angle);
            sf::Vector2f point = {
                flowerRadius * std::cos(angle),
                flowerRadius * std::sin(angle)
            };
            flower.setPoint(pointNo, point);
        }

        window.clear();
        window.draw(flower);
        window.display();
    }
}