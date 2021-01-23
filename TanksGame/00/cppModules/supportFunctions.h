bool checkCollision(sf::RectangleShape firstRect, sf::RectangleShape secondRect)
{
    bool intersects = false;

    if (firstRect.getGlobalBounds().intersects(secondRect.getGlobalBounds()))
        intersects = true;

    return intersects;
}