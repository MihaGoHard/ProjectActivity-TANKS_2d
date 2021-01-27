void initGameStates(gameStates &gameStates, int &gameControl)
{
    initTextures();
    
    initLevels(gameStates.levels);
            
    initLevelInfo(gameStates.levelInfo); 

    initScoreInfo(gameStates.scoreInfo);

    initGameOver(gameStates.gameOver);

    initMainMenu(gameStates.mainMenu);

    gameStates.tanksWorld.level = gameStates.levels[START_LEVEL];

    gameControl = OPEN_MAIN_MENU;
}