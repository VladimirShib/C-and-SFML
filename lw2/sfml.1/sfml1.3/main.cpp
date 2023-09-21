// Draw a house

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RectangleShape bg;
    bg.setSize({800, 600});
    bg.setPosition({0, 0});
    bg.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));

    sf::RectangleShape walls;
    walls.setSize({450, 230});
    walls.setPosition({175, 330});
    walls.setFillColor(sf::Color(0x4D, 0x2E, 0x0B));

    sf::RectangleShape door;
    door.setSize({70, 160});
    door.setPosition({225, 400});
    door.setFillColor(sf::Color(0x0, 0x0, 0x0));

    sf::ConvexShape roof;
    roof.setPosition({120, 215});
    roof.setPointCount(4);
    roof.setPoint(0, {0, 115});
    roof.setPoint(1, {160, 0});
    roof.setPoint(2, {390, 0});
    roof.setPoint(3, {560, 115});
    roof.setFillColor(sf::Color(0x5D, 0x1E, 0x17));

    sf::RectangleShape chimney1;
    chimney1.setSize({35, 60});
    chimney1.setPosition({470, 210});
    chimney1.setFillColor(sf::Color(0x3B, 0x38, 0x38));

    sf::RectangleShape chimney2;
    chimney2.setSize({55, 40});
    chimney2.setPosition({460, 170});
    chimney2.setFillColor(sf::Color(0x3B, 0x38, 0x38));

    sf::CircleShape smoke1(18);
    smoke1.setOrigin(18, 18);
    smoke1.setPosition({500, 160});
    smoke1.setFillColor(sf::Color(0xBF, 0xBF, 0xBF));

    sf::CircleShape smoke2(20);
    smoke2.setOrigin(20, 20);
    smoke2.setPosition({515, 145});
    smoke2.setFillColor(sf::Color(0xBF, 0xBF, 0xBF));

    sf::CircleShape smoke3(25);
    smoke3.setOrigin(25, 25);
    smoke3.setPosition({535, 125});
    smoke3.setFillColor(sf::Color(0xBF, 0xBF, 0xBF));

    sf::CircleShape smoke4(27);
    smoke4.setOrigin(27, 27);
    smoke4.setPosition({560, 100});
    smoke4.setFillColor(sf::Color(0xBF, 0xBF, 0xBF));

    sf::RenderWindow window(sf::VideoMode({800, 600}), "A house");
    window.clear();
    window.draw(bg);
    window.draw(walls);
    window.draw(door);
    window.draw(roof);
    window.draw(chimney1);
    window.draw(smoke1);
    window.draw(chimney2);
    window.draw(smoke2);
    window.draw(smoke3);
    window.draw(smoke4);
    window.display();

    sf::sleep(sf::seconds(5));
}