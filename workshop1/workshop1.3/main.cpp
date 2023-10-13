// Cat sprite

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

void initSprite(sf::Sprite &sprite, sf::Texture &texture)
{
    if (!texture.loadFromFile("cat.png"))
    {
        perror("Couldn't load texture \"cat\".");
        return;
    }
    
    sprite.setTexture(texture);
    sprite.setPosition({400, 300});
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

void redrawFrame(sf::RenderWindow &window, sf::Sprite sprite, sf::Texture texture)
{
    window.clear(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(sprite);
    window.display();
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Cat sprite", sf::Style::Default, settings);

    sf::Texture texture;
    sf::Sprite sprite;
    initSprite(sprite, texture);

    while (window.isOpen())
    {
        pollEvents(window);
        redrawFrame(window, sprite, texture);
    }
}