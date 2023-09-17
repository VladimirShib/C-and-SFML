// Draw my initials (SVV)

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Initials");
    
    window.clear();

    sf::RectangleShape first1;
    first1.setSize({ 230, 20 });
    first1.setPosition({ 25, 142 });
    first1.setFillColor(sf::Color(0xFF, 0x7F, 0x0));
    window.draw(first1);

    sf::RectangleShape first2;
    first2.setSize({ 20, 124 });
    first2.setPosition({ 25, 162 });
    first2.setFillColor(sf::Color(0xFF, 0x7F, 0x0));
    window.draw(first2);

    sf::RectangleShape first3;
    first3.setSize({ 230, 20 });
    first3.setPosition({ 25, 286 });
    first3.setFillColor(sf::Color(0xFF, 0x7F, 0x0));
    window.draw(first3);

    sf::RectangleShape first4;
    first4.setSize({ 20, 124 });
    first4.setPosition({ 235, 306 });
    first4.setFillColor(sf::Color(0xFF, 0x7F, 0x0));
    window.draw(first4);

    sf::RectangleShape first5;
    first5.setSize({ 230, 20 });
    first5.setPosition({ 25, 430 });
    first5.setFillColor(sf::Color(0xFF, 0x7F, 0x0));
    window.draw(first5);

    sf::RectangleShape second1;
    second1.setSize({ 20, 320 });
    second1.setRotation(-20);
    second1.setPosition({ 275, 150 });
    second1.setFillColor(sf::Color(0xFF, 0x7F, 0x0));
    window.draw(second1);

    sf::RectangleShape second2;
    second2.setSize({ 20, 320 });
    second2.setRotation(20);
    second2.setPosition({ 497, 143 });
    second2.setFillColor(sf::Color(0xFF, 0x7F, 0x0));
    window.draw(second2);

    sf::RectangleShape third1;
    third1.setSize({ 20, 320 });
    third1.setRotation(-20);
    third1.setPosition({ 535, 150 });
    third1.setFillColor(sf::Color(0xFF, 0x7F, 0x0));
    window.draw(third1);

    sf::RectangleShape third2;
    third2.setSize({ 20, 320 });
    third2.setRotation(20);
    third2.setPosition({ 757, 143 });
    third2.setFillColor(sf::Color(0xFF, 0x7F, 0x0));
    window.draw(third2);

    window.display();
    
    sf::sleep(sf::seconds(5));
}