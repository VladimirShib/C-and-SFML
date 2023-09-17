// Draw a traffic light using circles and rectangles

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Traffic light");
    
    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({ 190, 560 });
    shape1.setPosition({ 305, 20 });
    shape1.setFillColor(sf::Color(0x5B, 0x5B, 0x5B));
    window.draw(shape1);

    sf::CircleShape shape2(75);
    shape2.setPosition({ 325, 55 });
    shape2.setFillColor(sf::Color(0x0, 0xFF, 0x0));
    window.draw(shape2);

    sf::CircleShape shape3(75);
    shape3.setPosition({ 325, 225 });
    shape3.setFillColor(sf::Color(0xFF, 0xFF, 0x0));
    window.draw(shape3);

    sf::CircleShape shape4(75);
    shape4.setPosition({ 325, 395 });
    shape4.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape4);

    window.display();
    
    sf::sleep(sf::seconds(5));
}