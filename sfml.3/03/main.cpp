#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    mousePosition = {float(event.x), float(event.y)};
}

void init(sf::ConvexShape &pointer)
{
    pointer.setPointCount(3);
    pointer.setPoint(0, {40, 0});
    pointer.setPoint(1, {-20, -20});
    pointer.setPoint(2, {-20, 20});
    pointer.setPosition({400, 300});
    pointer.setFillColor(sf::Color(0xFF, 0x80, 0x00));
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

float getResultAngle(float pointerCurrAngle, float mouseCurrAngle, float maxAngle)
{
    float resultAngle = pointerCurrAngle;

    if (mouseCurrAngle < 0)
    {
        mouseCurrAngle += 360;
    }

    float deltaAngle = mouseCurrAngle - pointerCurrAngle;

    if (!(deltaAngle > -180 && deltaAngle < 180))
    {
        deltaAngle = pointerCurrAngle - mouseCurrAngle;
    }

    std::cout << deltaAngle << std::endl;
    //std::cout << mouseCurrAngle << std::endl;
    //std::cout << pointerCurrAngle << std::endl;

    if (!(deltaAngle > -1 && deltaAngle < 1))
    {
        deltaAngle < 0
            ? resultAngle = pointerCurrAngle - maxAngle
            : resultAngle = pointerCurrAngle + maxAngle;
    }

    return resultAngle;
}

void update(const sf::Vector2f &mousePosition, sf::ConvexShape &pointer, float maxDegrees, sf::Clock &clock)
{
    const float dt = clock.restart().asSeconds();

    const float maxAngle = maxDegrees * dt;

    float pointerDegreesCurrAngle = pointer.getRotation();

    const sf::Vector2f deltaPosition = mousePosition - pointer.getPosition();

    const float mouseRadiansCurrAngle = atan2(deltaPosition.y, deltaPosition.x);

    const float mouseDegreesCurrAngle = toDegrees(mouseRadiansCurrAngle);

    float resultDegreesAngle = getResultAngle(pointerDegreesCurrAngle, mouseDegreesCurrAngle, maxAngle);

    pointer.setRotation(resultDegreesAngle);
}

void redrawFrame(sf::RenderWindow &window, sf::ConvexShape &pointer)
{
    window.clear();
    window.draw(pointer);
    window.display();
}

int main()
{
    sf::Clock clock;
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;
    bool changeAngle = false;
    const float maxDegrees = 50;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Pointer follows mouse", sf::Style::Default, settings);

    sf::ConvexShape pointer;
    sf::Vector2f mousePosition;

    init(pointer);
    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, pointer, maxDegrees, clock);
        redrawFrame(window, pointer);
    }
}