#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>

const sf::Vector2f LEFT_EYE_POS = {250, 300};
const sf::Vector2f RIGHT_EYE_POS = {500, 300};
constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;

struct Eye
{
    sf::ConvexShape eyeBall;
    sf::ConvexShape eyePupil;
    sf::Vector2f position;
    float rotation = -90;
    float angle = 0;
};

sf::Vector2f toEuclidean(float radius, float angle)
{
    return {
        radius * std::cos(angle),
        radius * std::sin(angle)};
}

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    mousePosition =
        {
            float(event.x),
            float(event.y)};
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

void drawEllips(sf::ConvexShape &shape, const sf::Vector2f &radius)
{
    constexpr int pointCount = 200;
    shape.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = {
            radius.x * std::sin(angle),
            radius.y * std::cos(angle)};
        shape.setPoint(pointNo, point);
    }
}

initEye(Eye &eye, sf::Vector2f eyePos)
{

    eye.position = eyePos;
    const sf::Vector2f eyeBallRadius = {110.f, 110.f};
    const sf::Vector2f eyePupilRadius = {16.f, 16.f};

    eye.eyeBall.setRotation(eye.rotation);
    eye.eyePupil.setRotation(eye.rotation);

    eye.eyeBall.setPosition(eye.position);
    eye.eyePupil.setPosition(eye.position);

    eye.eyeBall.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    eye.eyePupil.setFillColor(sf::Color(0x00, 0x00, 0x00));

    drawEllips(eye.eyeBall, eyeBallRadius);
    drawEllips(eye.eyePupil, eyePupilRadius);
}

void updateEye(const sf::Vector2f &mousePosition, Eye &eye, bool isLeft)
{
    sf::Vector2f commonVector = mousePosition;
    sf::Vector2f delta = mousePosition - eye.position;
    eye.angle = std::atan2(delta.y, delta.x);

    sf::Vector2f trackRadius = {80.f, 80.f};
    sf::Vector2f pupilPos = eye.eyePupil.getPosition();

    isLeft
        ? commonVector = (LEFT_EYE_POS - mousePosition)
        : commonVector = (RIGHT_EYE_POS - mousePosition);

    float lengthV = std::sqrt(std::pow(commonVector.x, 2) + std::pow(commonVector.y, 2));

    std::cout << lengthV << std::endl;

    lengthV > 50
        ? eye.eyePupil.setPosition({eye.position.x + (trackRadius.x * std::cos(eye.angle)), eye.position.y + (trackRadius.y * std::sin(eye.angle))})
        : eye.eyePupil.setPosition(mousePosition);
}

void drawEye(sf::RenderWindow &window, Eye &eye)
{
    window.draw(eye.eyeBall);
    window.draw(eye.eyePupil);
}

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Arrow follows mouse", sf::Style::Default, settings);

    Eye leftEye;
    Eye rightEye;
    sf::Vector2f mousePosition;

    initEye(leftEye, LEFT_EYE_POS);
    initEye(rightEye, RIGHT_EYE_POS);

    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        window.clear();
        updateEye(mousePosition, leftEye, true);
        updateEye(mousePosition, rightEye, false);
        drawEye(window, leftEye);
        drawEye(window, rightEye);
        window.display();
    }
}