void processMainGamePlay(sf::RenderWindow &window, world &tanksWorld)
{
    tanksWorld.time.dt = tanksWorld.time.mainClock.restart().asSeconds();  

    checkShellCollision(tanksWorld);
        
    updateScore(tanksWorld);
    updateTankLabels(tanksWorld);
    updateLivesLabels(tanksWorld);
    
    setTanksMoveSolution(tanksWorld);
    initTanksAfterDestroy(tanksWorld);
    
    updateBarriers(tanksWorld);
    updateShells(tanksWorld);
    initResetBonus(tanksWorld);
    updateTanks(tanksWorld);

    drawTanksWorld(window, tanksWorld);

    gameKeyboardEvents(window, tanksWorld);
}


void processMainMenu(sf::RenderWindow &window, gameStates &gameStates) 
{
    mainMenu &mainMenu = gameStates.mainMenu;
    mainMenu.dt = gameStates.time.dt;

    initMainMenu(mainMenu);
    mainMenuKeyboardEvents(window, mainMenu);
    updateMenuElemsSetSolutions(mainMenu);
    drawMainMenu(window, mainMenu);
}


void processShowLevel(sf::RenderWindow &window, gameStates &gameStates)
{        
    setLevelNumber(gameStates);
    checkDelaySetLevelSolution(gameStates);
    drawLevelInfo(window, gameStates);
}


void processGameOver(sf::RenderWindow &window,  gameStates &gameStates)
{
    gameOver &gameOver = gameStates.gameOver;
    gameOver.dt = gameStates.time.dt;
    sf::Clock clock = gameStates.time.effectClock;
    world tanksWorld = gameStates.tanksWorld;
    
    initGameOver(gameOver);
    raiseGameOverImg(gameOver, clock);
    drawTanksWorld(window, tanksWorld);
    drawGameOver(window, gameOver);
}


void processScoreInfo(sf::RenderWindow &window, gameStates &gameStates, bool isVictory)
{
    calcScoreSetTextures(gameStates);
    checkDelaySetNextState(gameStates, isVictory);
    drawScoreInfo(window, gameStates);
}