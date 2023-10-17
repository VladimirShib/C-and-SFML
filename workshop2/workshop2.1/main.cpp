//Moving balls without collision

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <vector>

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;
constexpr float BALL_RADIUS = 40;

struct Ball
{
    sf::CircleShape shape;
    sf::Vector2f speed = {500.f, 150.f};
};

void initBalls(std::vector<Ball> &balls)
{
    const int ballCount = 5;
    const std::vector<sf::Color> colors = {{0xFF, 0, 0}, {0xFF, 0x80, 0}, {0xFF, 0xFF, 0}, {0, 0xFF, 0}, {0, 0xFF, 0xFF}};

    for (float i = 1.f; i <= ballCount; i++)
    {
        Ball ball;
        ball.shape.setRadius(BALL_RADIUS);
        ball.shape.setOrigin(BALL_RADIUS, BALL_RADIUS);
        ball.shape.setPosition({100 * i, 80 * i});
        ball.shape.setFillColor(sf::Color(colors[i - 1]));
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

void update(std::vector<Ball> &balls, sf::Clock &clock)
{
    const float deltaTime = clock.restart().asSeconds();

    for (Ball &ball : balls)
    {
        sf::Vector2f position = ball.shape.getPosition();
        position += ball.speed * deltaTime;

        if ((position.x + BALL_RADIUS >= WINDOW_WIDTH) && (ball.speed.x > 0))
        {
            ball.speed.x = -ball.speed.x;
        }
        if ((position.x - BALL_RADIUS < 0) && (ball.speed.x < 0))
        {
            ball.speed.x = -ball.speed.x;
        }
        if ((position.y + BALL_RADIUS >= WINDOW_HEIGHT) && (ball.speed.y > 0))
        {
            ball.speed.y = -ball.speed.y;
        }
        if ((position.y - BALL_RADIUS < 0) && (ball.speed.y < 0))
        {
            ball.speed.y = -ball.speed.y;
        }

        ball.shape.setPosition(position);
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

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Moving balls", sf::Style::Default, settings);

    std::vector<Ball> balls;
    initBalls(balls);

    while (window.isOpen())
    {
        pollEvents(window);
        update(balls, clock);
        redrawFrame(window, balls);
    }
}