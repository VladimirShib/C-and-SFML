//Wave moving ball (like sin graph) with collision on X axis

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;

int main()
{
    constexpr float BALL_SIZE = 40;

    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Wave Moving Ball");
    sf::Clock clock;

    const sf::Vector2f position = {10, 350};
    float speedX = 100.f;
    float elapsedTime = 0.f;

    sf::CircleShape ball(BALL_SIZE);
    ball.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));

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

        constexpr float amplitudeY = 80.f;
        constexpr float periodY = 2;

        const float deltaTime = clock.restart().asSeconds();
        elapsedTime += deltaTime;
        const float wavePhase = elapsedTime * float(2 * M_PI);
        const float offsetY = amplitudeY * std::sin(wavePhase / periodY);

        float positionX = ball.getPosition().x;
        positionX += speedX * deltaTime;
        ball.setPosition(positionX, position.y + offsetY);

        if ((positionX + BALL_SIZE * 2 >= WINDOW_WIDTH) && (speedX > 0))
        {
            speedX = -speedX;
        }
        if ((positionX < 0) && (speedX < 0))
        {
            speedX = -speedX;
        }

        window.clear();
        window.draw(ball);
        window.display();
    }
}