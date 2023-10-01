// Eye pupils that follow the cursor

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>

struct Eye
{
    const int eyePointCount = 100;
    const int pupilPointCount = 20;
    const sf::Vector2f eyeRadius = {70.f, 130.f};
    const sf::Vector2f pupilRadius = {20.f, 30.f};
    sf::ConvexShape eye;
    sf::ConvexShape pupil;
    //sf::Vector2f pupilOffset = {0.f, 0.f};
    float pupilRotation = 0;
};

struct BothEyes
{
    const sf::Vector2f leftEyePosition = {315, 300};
    const sf::Vector2f rightEyePosition = {485, 300};
    Eye leftEye;
    Eye rightEye;
};

void initEye(Eye &eye, sf::Vector2f position)
{
    eye.eye.setPosition(position);
    eye.eye.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    eye.eye.setPointCount(eye.eyePointCount);
    for (int pointNo = 0; pointNo < eye.eyePointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(eye.eyePointCount);
        sf::Vector2f point = {
            eye.eyeRadius.x * std::cos(angle),
            eye.eyeRadius.y * std::sin(angle)};
        eye.eye.setPoint(pointNo, point);
    }

    eye.pupil.setPosition(position);
    eye.pupil.setFillColor(sf::Color(0, 0, 0));
    eye.pupil.setPointCount(eye.pupilPointCount);
    for (int pointNo = 0; pointNo < eye.pupilPointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(eye.pupilPointCount);
        sf::Vector2f point = {
            eye.pupilRadius.x * std::cos(angle),
            eye.pupilRadius.y * std::sin(angle)};
        eye.pupil.setPoint(pointNo, point);
    }
}

void initEyes(BothEyes &eyes)
{
    initEye(eyes.leftEye, eyes.leftEyePosition);
    initEye(eyes.rightEye, eyes.rightEyePosition);
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

sf::Vector2f toEuclidean(float radius, float angle)
{
    return {
        radius * std::cos(angle),
        radius * std::sin(angle)};
}

void updatePupilPosition(const sf::Vector2f &mousePosition, Eye &eye)
{
    const sf::Vector2f eyeCenter = eye.eye.getPosition();
    float radius = std::sqrt(std::pow(mousePosition.x - eyeCenter.x, 2.0) + std::pow(mousePosition.y - eyeCenter.y, 2.0));
    if (radius > 45)
    {
        radius = 45;
    }
    const sf::Vector2f pupilOffset = toEuclidean(radius, eye.pupilRotation);
    eye.pupil.setPosition(eye.eye.getPosition() + pupilOffset);
}

void update(const sf::Vector2f &mousePosition, Eye &eye)
{
    const sf::Vector2f delta = mousePosition - eye.eye.getPosition();
    eye.pupilRotation = atan2(delta.y, delta.x);
    updatePupilPosition(mousePosition, eye);
}

void redrawFrame(sf::RenderWindow &window, BothEyes &eyes)
{
    window.clear();
    window.draw(eyes.leftEye.eye);
    window.draw(eyes.leftEye.pupil);
    window.draw(eyes.rightEye.eye);
    window.draw(eyes.rightEye.pupil);
    window.display();
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Eyes",
        sf::Style::Default, settings);

    BothEyes eyes;
    sf::Vector2f mousePosition;

    initEyes(eyes);
    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, eyes.leftEye);
        update(mousePosition, eyes.rightEye);
        redrawFrame(window, eyes);
    }
}