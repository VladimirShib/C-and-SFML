// An arrow follows mouse cursor

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>

struct Arrow
{
    sf::ConvexShape shape;
};

void initArrow(Arrow &arrow)
{
    arrow.shape.setPosition({400, 300});
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

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    mousePosition = {float(event.x), float(event.y)};
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove, mousePosition);
            break;
        default:
            break;
        }
    }
}

void update(const sf::Vector2f &mousePosition, Arrow &arrow, sf::Clock &clock)
{
    constexpr float maxSpeed = 200.f;
    constexpr float rotateSpeed = 90.f;
    const float deltaTime = clock.restart().asSeconds();
    const sf::Vector2f currentPosition = arrow.shape.getPosition();

    if (currentPosition != mousePosition)
    {
        const sf::Vector2f motion = mousePosition - currentPosition;
        const float vectorLength = std::sqrt(motion.x * motion.x + motion.y * motion.y);
        const sf::Vector2f direction = {
            motion.x / vectorLength,
            motion.y / vectorLength
        };
        const float distance = maxSpeed * deltaTime;
        arrow.shape.setPosition(currentPosition + direction * distance);
    
        float angle = toDegrees(atan2(motion.y, motion.x));
        if (angle < 0)
        {
            angle = 360 + angle;
        }
        const float currentAngle = arrow.shape.getRotation();
        if (angle != currentAngle)
        {
            float deltaAngle = angle - currentAngle;
            if (deltaAngle > 0 && deltaAngle < 180 || deltaAngle < -180)
            {
                arrow.shape.rotate(rotateSpeed * deltaTime);
            }
            else
            {
                arrow.shape.rotate(-(rotateSpeed * deltaTime));
            }
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

    sf::Clock clock;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Arrow follows mouse", sf::Style::Default, settings);

    Arrow arrow;
    sf::Vector2f mousePosition;

    initArrow(arrow);
    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, arrow, clock);
        redrawFrame(window, arrow);
    }
}