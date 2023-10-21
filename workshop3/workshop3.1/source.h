#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

constexpr int BALL_RADIUS = 60;

struct Ball
{
    sf::CircleShape shape;
    sf::Font font;
    sf::Text text;
    float velocityY;
    float floor = 540.f;
};

void initBall(Ball &ball);
void update(Ball &ball, sf::Clock &clock);