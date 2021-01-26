void mainMenuKeyboardEvents(sf::RenderWindow &window, mainMenu &mainMenu)
{
    sf::Keyboard::isKeyPressed(sf::Keyboard::Return)
        ? mainMenu.control.enter = true
        : mainMenu.control.enter = false;
}