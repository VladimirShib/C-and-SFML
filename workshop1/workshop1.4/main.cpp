// Cat follows the red pointer, both being sprites

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>

void initCat(sf::Sprite &sprite, sf::Texture &texture)
{
    if (!texture.loadFromFile("cat.png"))
    {
        perror("Couldn't load texture \"cat\".");
        return;
    }

    sprite.setTexture(texture);
    sprite.setPosition({200, 300});
}

void initPointer(sf::Sprite &sprite, sf::Texture &texture)
{
    if (!texture.loadFromFile("pointer.png"))
    {
        perror("Couldn't load texture \"pointer\".");
        return;
    }

    sprite.setTexture(texture);
    sprite.setPosition({600, 300});
}

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

void onMouseClick(const sf::Event::MouseButtonEvent &event, sf::Vector2f &clickCoords)
{
    clickCoords = {float(event.x), float(event.y)};
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &clickCoords)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                onMouseClick(event.mouseButton, clickCoords);
            }
            break;
        default:
            break;
        }
    }
}

void updatePointer(sf::Vector2f &clickCoords, sf::Sprite &sprite, sf::Texture texture)
{
    sprite.setOrigin(sf::Vector2f(sprite.getTexture()->getSize().x * 0.5, sprite.getTexture()->getSize().y * 0.5));
    sprite.setPosition(clickCoords);
}

void updateCat(sf::Vector2f clickCoords, sf::Sprite &sprite, sf::Texture texture, sf::Clock &clock)
{
    constexpr float maxSpeed = 200.f;
    const float deltaTime = clock.restart().asSeconds();
    const sf::Vector2f currentPosition = sprite.getPosition();
    const sf::Vector2f currentPositionRounded = {
        std::round(currentPosition.x),
        std::round(currentPosition.y)
	};

    if (currentPositionRounded != clickCoords)
    {
        const sf::Vector2f motion = clickCoords - currentPosition;
        const float vectorLength = std::sqrt(motion.x * motion.x + motion.y * motion.y);
        const sf::Vector2f direction = {
            motion.x / vectorLength,
            motion.y / vectorLength
		};
        const float distance = maxSpeed * deltaTime;
        sprite.setOrigin(sf::Vector2f(sprite.getTexture()->getSize().x * 0.5, sprite.getTexture()->getSize().y * 0.5));
        sprite.setPosition(currentPosition + direction * distance);

        float angle = toDegrees(atan2(motion.y, motion.x));
        if (angle < 0)
        {
            angle = 360 + angle;
        }

        if (angle <= 90 || angle >= 270)
        {
            sprite.setScale(1, 1);
        }
        else
        {
            sprite.setScale(-1, 1);
        }
    }
}

void redrawFrame(sf::RenderWindow &window, sf::Sprite cat, sf::Sprite pointer, sf::Texture catTexture, sf::Texture pointerTexture)
{
    window.clear(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(pointer);
    window.draw(cat);
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
        "Cat follows the pointer", sf::Style::Default, settings);

    sf::Texture textureCat;
    sf::Texture texturePointer;
    sf::Sprite cat;
    sf::Sprite pointer;
    sf::Vector2f clickCoords;

    initCat(cat, textureCat);
    initPointer(pointer, texturePointer);

    while (window.isOpen())
    {
        pollEvents(window, clickCoords);
        updatePointer(clickCoords, pointer, texturePointer);
        updateCat(clickCoords, cat, textureCat, clock);
        redrawFrame(window, cat, pointer, textureCat, texturePointer);
    }
}