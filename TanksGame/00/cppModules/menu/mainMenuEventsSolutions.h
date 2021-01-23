void mainMenuKeyboardEvents(sf::RenderWindow &window, mainMenu &mainMenu)
{
    sf ::Keyboard ::isKeyPressed(sf ::Keyboard ::Return)
        ? mainMenu.control.enter = true
        : mainMenu.control.enter = false;

    /*sf ::Keyboard ::isKeyPressed(sf ::Keyboard ::Up)    для перемещения указателя в меню 
        ? mainMenu.control.up = true
        : mainMenu.control.up = false;

    sf ::Keyboard ::isKeyPressed(sf ::Keyboard ::Down)
        ? mainMenu.control.down = true
        : mainMenu.control.down = false;*/
}