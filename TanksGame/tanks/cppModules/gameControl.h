void gamePollEvents(sf::RenderWindow &window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
        }
    }
}


void updateGameControl(int &gameControl, gameStates &gameStates)
{
    gameStates.time.dt = gameStates.time.dtClock.restart().asSeconds(); 

    checkScoreInfoSetControl(gameControl, gameStates);
    
    checkLevelInfoSetControl(gameControl, gameStates);
    
    checkGameOveSetControl(gameControl, gameStates);

    checkMainMenuSetControl(gameControl, gameStates);
    
    checkGamePlaySetControl(gameControl, gameStates);
}


void processGameState(sf::RenderWindow &window, int &gameControl, gameStates &gameStates) 
{
    gamePollEvents(window);
    switch (gameControl)
    {
        case SHOW_LEVEL:
            processShowLevel(window, gameStates);
            break;
        case SHOW_SCORE_MENU_VICTORY:
            processScoreInfo(window, gameStates, true);
            break;
        case SHOW_SCORE_MENU_DEFEAT:
            processScoreInfo(window, gameStates, false);
            break;
        case START_GAME_PLAY:
            processMainGamePlay(window, gameStates.tanksWorld);
            break;
        case SHOW_GAME_OVER:
            processGameOver(window, gameStates);
            break;             

        default:
            processMainMenu(window, gameStates);
    }
}


void updateControlProcessState(sf::RenderWindow &window, int &gameControl, gameStates &gameStates) 
{
    updateGameControl(gameControl, gameStates);
    processGameState(window, gameControl, gameStates);
}