void checkScoreInfoSetControl(int &gameControl, gameStates &gameStates)
{
    sf::Clock &clock = gameStates.time.effectClock;
    scoreInfo &scoreInfo = gameStates.scoreInfo;
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
}


checkLevelInfoSetControl(int &gameControl, gameStates &gameStates)
{
    sf::Clock &clock = gameStates.time.effectClock;
    levelInfo &levelInfo = gameStates.levelInfo;
    world &tanksWorld = gameStates.tanksWorld;

    if (levelInfo.startGame)
    {
        clock.restart().asSeconds();
        gameControl = START_GAME_PLAY;
        initTanksWorld(tanksWorld);
        levelInfo.startGame = false;
    }
}


void checkGameOveSetControl(int &gameControl, gameStates &gameStates)
{
    sf::Clock &clock = gameStates.time.effectClock;
    gameOver &gameOver = gameStates.gameOver;
    if (gameOver.showScore) 
    {
        clock.restart().asSeconds();
        gameControl = SHOW_SCORE_MENU_DEFEAT;
        gameOver.showScore = false;
    }
}


void checkMainMenuSetControl(int &gameControl, gameStates &gameStates)
{
    sf::Clock &clock = gameStates.time.effectClock;
    mainMenu &mainMenu = gameStates.mainMenu;

    if (mainMenu.startGame) 
    {
        clock.restart().asSeconds();
        gameControl = SHOW_LEVEL;
        mainMenu.startGame = false;
    }
}


checkGamePlaySetControl(int &gameControl, gameStates &gameStates)
{
    sf::Clock &clock = gameStates.time.effectClock;
    std::vector<levelData> &levels = gameStates.levels;
    world &tanksWorld = gameStates.tanksWorld;

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
