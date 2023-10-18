//Moving balls with collision. Each ball's speed is random

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <cmath>
#include <random>

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;
constexpr float BALL_RADIUS = 40;
constexpr int BALL_COUNT = 5;

struct Ball
{
    sf::CircleShape shape;
    sf::Vector2f speed;
};

struct PRNG
{
    std::mt19937 engine;
};

void initGenerator(PRNG &generator)
{
    std::random_device device;
    generator.engine.seed(device());
}

float getRandomFloat(PRNG &generator, float minValue, float maxValue)
{
    std::uniform_real_distribution<float> distribution(minValue, maxValue);
    return distribution(generator.engine);
}

sf::Vector2f getRandomSpeed(PRNG &generator, float min, float max)
{
    return {
        getRandomFloat(generator, min, max),
        getRandomFloat(generator, min, max)
    };
}

void initBalls(PRNG &generator, std::vector<Ball> &balls)
{
    const std::vector<sf::Color> colors = {{0xFF, 0, 0}, {0xFF, 0x80, 0}, {0xFF, 0xFF, 0}, {0, 0xFF, 0}, {0, 0xFF, 0xFF}};
    const float minSpeed = 150.f;
    const float maxSpeed = 500.f;

    for (float i = 1.f; i <= BALL_COUNT; i++)
    {
        Ball ball;
        ball.shape.setRadius(BALL_RADIUS);
        ball.shape.setOrigin(BALL_RADIUS, BALL_RADIUS);
        ball.shape.setPosition({100 * i, 80 * i});
        ball.shape.setFillColor(sf::Color(colors[i - 1]));
        ball.speed = getRandomSpeed(generator, minSpeed, maxSpeed);
        balls.push_back(ball);
    }
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

float distance(sf::Vector2f one, sf::Vector2f two)
{
    float dx = one.x - two.x;
    float dy = one.y - two.y;

    return std::sqrt(dx * dx + dy * dy);
}

float dotProduct(sf::Vector2f one, sf::Vector2f two)
{
    return one.x * two.x + one.y * two.y;
}

sf::Vector2f calculateSpeed(sf::Vector2f thisSpeed, sf::Vector2f otherSpeed, sf::Vector2f thisPosition, sf::Vector2f otherPosition)
{
    float dividend = dotProduct(thisSpeed - otherSpeed, thisPosition - otherPosition);
    float divisor = distance(thisPosition, otherPosition) * distance(thisPosition, otherPosition);
    sf::Vector2f multiplication = dividend / divisor * (thisPosition - otherPosition);

    return thisSpeed - multiplication;
}

void update(std::vector<Ball> &balls, sf::Clock &clock)
{
    const float deltaTime = clock.restart().asSeconds();

    for (int i = 0; i < balls.size(); ++i)
    {
        Ball &first = balls[i];

        sf::Vector2f positionFirst = first.shape.getPosition();
        positionFirst += first.speed * deltaTime;

        for (int j = i + 1; j < balls.size(); ++j)
        {
            Ball &second = balls[j];

            sf::Vector2f positionSecond = second.shape.getPosition();
            if (distance(positionFirst, positionSecond) <= BALL_RADIUS * 2)
            {
                sf::Vector2f firstSpeed = first.speed;

                first.speed = calculateSpeed(first.speed, second.speed, positionFirst, positionSecond);
                second.speed = calculateSpeed(second.speed, firstSpeed, positionSecond, positionFirst);
            }
        }

        if ((positionFirst.x + BALL_RADIUS >= WINDOW_WIDTH) && (first.speed.x > 0))
        {
            first.speed.x = -first.speed.x;
        }
        if ((positionFirst.x - BALL_RADIUS < 0) && (first.speed.x < 0))
        {
            first.speed.x = -first.speed.x;
        }
        if ((positionFirst.y + BALL_RADIUS >= WINDOW_HEIGHT) && (first.speed.y > 0))
        {
            first.speed.y = -first.speed.y;
        }
        if ((positionFirst.y - BALL_RADIUS < 0) && (first.speed.y < 0))
        {
            first.speed.y = -first.speed.y;
        }

        first.shape.setPosition(positionFirst);
    }
}

void redrawFrame(sf::RenderWindow &window, std::vector<Ball> &balls)
{
    window.clear();
    for (Ball &ball : balls)
    {
        window.draw(ball.shape);
    }
    window.display();
}

int main()
{
    sf::Clock clock;
    PRNG generator;
    initGenerator(generator);

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Moving balls", sf::Style::Default, settings);

    std::vector<Ball> balls;
    initBalls(generator, balls);

    while (window.isOpen())
    {
        pollEvents(window);
        update(balls, clock);
        redrawFrame(window, balls);
    }
}