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
    sf::Clock &clock = gameStates.time.effectClock;
    levelInfo &levelInfo = gameStates.levelInfo;
    scoreInfo &scoreInfo = gameStates.scoreInfo;
    gameOver &gameOver = gameStates.gameOver;
    mainMenu &mainMenu = gameStates.mainMenu;
    world &tanksWorld = gameStates.tanksWorld;
    std::vector<levelData> &levels = gameStates.levels; 

    switch (scoreInfo.nextState)
    {
        case NEXT_LEVEL:
            scoreInfo.nextState = WAIT;
            clock.restart().asSeconds();
            tanksWorld.level = levels[tanksWorld.level.levelNumber + 1];
            initTanksWorld(tanksWorld);
            gameControl = SHOW_LEVEL;
            break;             

        case MAIN_MENU:
            scoreInfo.nextState = WAIT;
            clock.restart().asSeconds();
            tanksWorld.level = levels[0];
            gameControl = OPEN_MAIN_MENU;
            break;    
    }
 
    

    if (levelInfo.startGame)
    {
        gameControl = START_GAME_PLAY;
        initTanksWorld(tanksWorld);
        levelInfo.startGame = false;
    }


    if (gameOver.showScore) 
    {
        clock.restart().asSeconds();
        gameControl = SHOW_SCORE_MENU_DEFEAT;
        gameOver.showScore = false;
    }


    if (mainMenu.startGame) 
    {
        clock.restart().asSeconds();
        gameControl = SHOW_LEVEL;
        mainMenu.startGame = false;
    }


    if (tanksWorld.worldStatus == LOSS)
    {
        clock.restart().asSeconds();
        gameControl = SHOW_GAME_OVER;
        tanksWorld.worldStatus = GAMEPLAY;
        initScoreInfo(gameStates.scoreInfo);
    }
    

    if (tanksWorld.worldStatus == WIN) 
    {
        tanksWorld.worldStatus = GAMEPLAY;
        
        int levelsNum = levels.size() - 1;

        if (tanksWorld.level.levelNumber == levelsNum)
        {
            gameControl = OPEN_MAIN_MENU; 
            gameStates.tanksWorld.level = gameStates.levels[START_LEVEL];   
        }    
        else
        {
            clock.restart().asSeconds();
            gameControl = SHOW_SCORE_MENU_VICTORY;
        }         
        initScoreInfo(gameStates.scoreInfo);
    }
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

