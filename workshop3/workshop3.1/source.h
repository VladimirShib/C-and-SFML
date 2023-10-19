#pragma once
#include <SFML/Graphics.hpp>

struct Ball
{
    sf::CircleShape shape;
    sf::Font font;
    sf::Text text;
};

void initBall(Ball &ball);