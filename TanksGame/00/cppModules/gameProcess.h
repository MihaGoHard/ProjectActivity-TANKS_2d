void processMainGamePlay(sf::RenderWindow &window, world &tanksWorld)
{
    tanksWorld.time.dt = tanksWorld.time.mainClock.restart().asSeconds();  

    checkShellCollision(tanksWorld);
        
    updateScore(tanksWorld);
    updateTankLabels(tanksWorld);
    updateLivesLabels(tanksWorld);
    
    checkTankCollisionSetMoveSollution(tanksWorld);
    checkTanksDestroyInitNewTanks(tanksWorld);
    
    updateBarriers(tanksWorld);
    updateShells(tanksWorld);
    initUpdateBonus(tanksWorld);
    updateTanks(tanksWorld);

    drawTanksWorld(window, tanksWorld);

    gameKeyboardEvents(window, tanksWorld);
}

void processMainMenu(sf::RenderWindow &window, gameStates &gameStates) 
{
    mainMenu &mainMenu = gameStates.mainMenu;
    mainMenu.dt = gameStates.time.dt;
    if (!mainMenu.mainMenuInited)
    {
        initMainMenu(mainMenu);
        mainMenu.mainMenuInited = true;
    }    
    mainMenuKeyboardEvents(window, mainMenu);
    updateMenuElemsSetSolutions(mainMenu);
    drawMainMenu(window, mainMenu);
}

void processShowLevel(sf::RenderWindow &window, gameStates &gameStates)
{   
    sf::Clock clock = gameStates.time.effectClock;     
    levelInfo &levelInfo = gameStates.levelInfo;
    int levelNum = gameStates.tanksWorld.level.levelNumber;
    setLevelNumer(levelInfo, levelNum);
    int timeToShow = int(clock.getElapsedTime().asSeconds());

    if (timeToShow % 3 == 0 && timeToShow != 0)
        levelInfo.startGame = true;

    drawLevelInfo(window, levelInfo);
}

void processGameOver(sf::RenderWindow &window,  gameStates &gameStates)
{
    gameOver &gameOver = gameStates.gameOver;
    gameOver.dt = gameStates.time.dt;
    sf::Clock clock = gameStates.time.effectClock;
    world tanksWorld = gameStates.tanksWorld;
    
    if (!gameOver.gameOverInited)
    {
        initGameOver(gameOver);
        gameOver.gameOverInited = true;
    }    
    
    raiseGameOverImg(gameOver, gameStates.time.effectClock);
    
    drawTanksWorld(window, tanksWorld);

    drawGameOver(window, gameOver);
}



void processScoreInfo(sf::RenderWindow &window, gameStates &gameStates, bool isVictory)
{
    sf::Clock clock = gameStates.time.effectClock;

    scoreInfo &scoreInfo = gameStates.scoreInfo;

    calcScoreSetTextures(scoreInfo, gameStates);
    
    int timeToShow = int(clock.getElapsedTime().asSeconds());
    
    if (timeToShow % 5 == 0 && timeToShow != 0)
    {
        if (isVictory)
            scoreInfo.nextState = NEXT_LEVEL;
        else
            scoreInfo.nextState = MAIN_MENU;
    }    
    
    drawScoreInfo(window, scoreInfo);
}