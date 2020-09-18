// дом
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RectangleShape background;
    background.setSize({800, 600});
    background.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));

    sf::RectangleShape houseBox;
    houseBox.setSize({500, 250});
    houseBox.setPosition({150, 350});
    houseBox.setFillColor(sf::Color(0x8B, 0x45, 0x13));

    sf::RectangleShape houseDoor;
    houseDoor.setSize({80, 150});
    houseDoor.setPosition({200, 450});
    houseDoor.setFillColor(sf::Color(0x0, 0x0, 0x0));

    sf::ConvexShape houseRoof;
    houseRoof.setFillColor(sf::Color(0x80, 0x0, 0x0));
    houseRoof.setPosition(280, 240);
    houseRoof.setPointCount(4);
    houseRoof.setPoint(0, {0, 0});
    houseRoof.setPoint(1, {+240, 0});
    houseRoof.setPoint(2, {+420, 110});
    houseRoof.setPoint(3, {-180, 110});

    sf::RectangleShape housePipe1;
    housePipe1.setSize({44, 60});
    housePipe1.setPosition({460, 230});
    housePipe1.setFillColor(sf::Color(0x33, 0x33, 0x33));

    sf::RectangleShape housePipe2;
    housePipe2.setSize({64, 40});
    housePipe2.setPosition({450, 190});
    housePipe2.setFillColor(sf::Color(0x33, 0x33, 0x33));

    sf::CircleShape smoke1(20);
    smoke1.setPosition({473, 160});
    smoke1.setFillColor(sf::Color(0x70, 0x70, 0x70));

    sf::CircleShape smoke2(23);
    smoke2.setPosition({480, 125});
    smoke2.setFillColor(sf::Color(0x70, 0x70, 0x70));

    sf::CircleShape smoke3(26);
    smoke3.setPosition({490, 90});
    smoke3.setFillColor(sf::Color(0x70, 0x70, 0x70));

    sf::CircleShape smoke4(29);
    smoke4.setPosition({497, 55});
    smoke4.setFillColor(sf::Color(0x70, 0x70, 0x70));

    sf::RenderWindow window(sf::VideoMode({800, 600}), "Convex Shapes");
    window.clear();
    window.draw(background);
    window.draw(houseBox);
    window.draw(houseDoor);
    window.draw(houseRoof);
    window.draw(housePipe1);
    window.draw(smoke1);
    window.draw(smoke2);
    window.draw(smoke3);
    window.draw(smoke4);
    window.draw(housePipe2);
    window.display();

    sf::sleep(sf::seconds(10));
}