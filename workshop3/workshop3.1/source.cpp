#include "source.h"

void initBall(Ball &ball)
{
    ball.shape.setRadius(BALL_RADIUS);
    ball.shape.setOrigin(BALL_RADIUS, BALL_RADIUS);
    ball.shape.setPosition({400, 500});
    ball.shape.setFillColor(sf::Color(0xFF, 0xC0, 0));
    ball.shape.setOutlineColor(sf::Color(0x2F, 0x55, 0x97));
    ball.shape.setOutlineThickness(7);

    if (!ball.font.loadFromFile("arial.ttf"))
    {
        perror("Couldn't load font \"arial\".");
    }

    ball.text.setString("SVV");
    ball.text.setFont(ball.font);
    ball.text.setCharacterSize(30);
    ball.text.setOrigin(sf::Vector2f(ball.text.getLocalBounds().width * 0.5, ball.text.getLocalBounds().height * 0.5 + 5));
    ball.text.setPosition({400, 500});
    ball.text.setFillColor(sf::Color(0, 0, 0));
}

void update(Ball &ball, sf::Clock &clock)
{
    const float deltaTime = clock.restart().asSeconds();
    const float gravity = 700.f;

    sf::Vector2f position = ball.shape.getPosition();
    if (position.y >= ball.floor)
    {
        ball.velocityY = -800.f;
    }

    position.y += ball.velocityY * deltaTime;
    ball.velocityY += gravity * deltaTime;

    ball.shape.setPosition(position);
    ball.text.setPosition(position);
}