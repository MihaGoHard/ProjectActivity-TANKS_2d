// имя
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({1200, 800}), "title");

    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({1200, 800});
    shape1.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(shape1);

    // draw letter S
    sf::CircleShape sCircle1(95);
    sCircle1.setPosition({60, 72});
    sCircle1.setFillColor(sf::Color(0x00, 0x00, 0x00));
    window.draw(sCircle1);

    sf::CircleShape sCircle2(75);
    sCircle2.setPosition({80, 92});
    sCircle2.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(sCircle2);

    sf::RectangleShape sBox1;
    sBox1.setSize({100, 200});
    sBox1.setRotation(50);
    sBox1.setPosition({265, 71});
    sBox1.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(sBox1);

    sf::CircleShape sCircle3(100);
    sCircle3.setPosition({50, 242});
    sCircle3.setFillColor(sf::Color(0x00, 0x00, 0x00));
    window.draw(sCircle3);

    sf::CircleShape sCircle4(80);
    sCircle4.setPosition({70, 262});
    sCircle4.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(sCircle4);

    sf::RectangleShape sBox3;
    sBox3.setSize({80, 100});
    sBox3.setRotation(72);
    sBox3.setPosition({120, 257});
    sBox3.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(sBox3);

    sf::RectangleShape sBox2;
    sBox2.setSize({80, 25});
    sBox2.setRotation(17);
    sBox2.setPosition({87, 244});
    sBox2.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(sBox2);

    // draw letter M

    sf::RectangleShape mBox1;
    mBox1.setSize({410, 20});
    mBox1.setRotation(100);
    mBox1.setPosition({350, 65});
    mBox1.setFillColor(sf::Color(0x0, 0x0, 0x0));
    window.draw(mBox1);

    sf::RectangleShape mBox2;
    mBox2.setSize({420, 20});
    mBox2.setRotation(70);
    mBox2.setPosition({350, 65});
    mBox2.setFillColor(sf::Color(0x0, 0x0, 0x0));
    window.draw(mBox2);

    sf::RectangleShape mBox3;
    mBox3.setSize({420, 20});
    mBox3.setRotation(110);
    mBox3.setPosition({637, 65});
    mBox3.setFillColor(sf::Color(0x0, 0x0, 0x0));
    window.draw(mBox3);

    sf::RectangleShape mBox4;
    mBox4.setSize({410, 20});
    mBox4.setRotation(80);
    mBox4.setPosition({640, 65});
    mBox4.setFillColor(sf::Color(0x0, 0x0, 0x0));
    window.draw(mBox4);

    sf::RectangleShape mBox5;
    mBox5.setSize({410, 30});
    mBox5.setPosition({270, 44});
    mBox5.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(mBox5);

    sf::RectangleShape mBox6;
    mBox6.setSize({500, 35});
    mBox6.setPosition({250, 440});
    mBox6.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(mBox6);

    // draw letter B

    sf::CircleShape bCircle1(95);
    bCircle1.setPosition({730, 72});
    bCircle1.setFillColor(sf::Color(0x00, 0x00, 0x00));
    window.draw(bCircle1);

    sf::CircleShape bCircle2(75);
    bCircle2.setPosition({750, 92});
    bCircle2.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(bCircle2);

    sf::CircleShape bCircle3(100);
    bCircle3.setPosition({730, 242});
    bCircle3.setFillColor(sf::Color(0x00, 0x00, 0x00));
    window.draw(bCircle3);

    sf::CircleShape bCircle4(80);
    bCircle4.setPosition({750, 262});
    bCircle4.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(bCircle4);

    sf::RectangleShape bBox1;
    bBox1.setSize({100, 400});
    bBox1.setPosition({725, 60});
    bBox1.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(bBox1);

    sf::RectangleShape bBox2;
    bBox2.setSize({20, 370});
    bBox2.setPosition({765, 72});
    bBox2.setFillColor(sf::Color(0x0, 0x0, 0x0));
    window.draw(bBox2);

    sf::RectangleShape bBox3;
    bBox3.setSize({60, 20});
    bBox3.setPosition({765, 72});
    bBox3.setFillColor(sf::Color(0x0, 0x0, 0x0));
    window.draw(bBox3);

    sf::RectangleShape bBox4;
    bBox4.setSize({64, 22});
    bBox4.setPosition({765, 241});
    bBox4.setFillColor(sf::Color(0x0, 0x0, 0x0));
    window.draw(bBox4);

    sf::RectangleShape bBox5;
    bBox5.setSize({60, 20});
    bBox5.setPosition({765, 422});
    bBox5.setFillColor(sf::Color(0x0, 0x0, 0x0));
    window.draw(bBox5);

    window.display();

    sf::sleep(sf::seconds(10));
}