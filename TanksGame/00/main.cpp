#include "./cppModules/gameLibsModules.h"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Purum-pum-pum", sf::Style::Default, settings);        
        

    gameStates gameStates;
    int gameControl;
    srand(time(0));

    initGameStates(gameStates, gameControl);

    while (window.isOpen())
    {
        window.clear();

        updateControlProcessState(window, gameControl, gameStates);

        window.display();
    }
}