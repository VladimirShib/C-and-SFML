//Moving ball with collision

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;
    constexpr float BALL_SIZE = 40;

    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Moving Ball");
    sf::Clock clock;

    sf::CircleShape shape(BALL_SIZE);
    shape.setOrigin(40, 40);
    shape.setPosition({200, 150});
    shape.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));

    sf::Vector2f speed = {500.f, 150.f};

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

        const float deltaTime = clock.restart().asSeconds();
        sf::Vector2f position = shape.getPosition();
        position += speed * deltaTime;

        if ((position.x + BALL_SIZE >= WINDOW_WIDTH) && (speed.x > 0))
        {
            speed.x = -speed.x;
        }
        if ((position.x - BALL_SIZE < 0) && (speed.x < 0))
        {
            speed.x = -speed.x;
        }
        if ((position.y + BALL_SIZE >= WINDOW_HEIGHT) && (speed.y > 0))
        {
            speed.y = -speed.y;
        }
        if ((position.y - BALL_SIZE < 0) && (speed.y < 0))
        {
            speed.y = -speed.y;
        }

        shape.setPosition(position);

        window.clear();
        window.draw(shape);
        window.display();
    }
}