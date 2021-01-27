void drawMainMenu(sf::RenderWindow &window, mainMenu mainMenu)
{
    window.draw(mainMenu.mainBackground);
    window.draw(mainMenu.choicePointer.box);
}


void drawGameOver(sf::RenderWindow &window, gameOver gameOver)
{
    window.draw(gameOver.gameOverImg);
}


void drawLevelInfo(sf::RenderWindow &window, gameStates gameStates)
{
    levelInfo &levelInfo = gameStates.levelInfo;
    window.draw(levelInfo.background);
    window.draw(levelInfo.stageLabel);
}


void drawScoreInfo(sf::RenderWindow &window, gameStates gameStates)
{
    scoreInfo &scoreInfo = gameStates.scoreInfo;
    window.draw(scoreInfo.background);
    window.draw(scoreInfo.stage);
    window.draw(scoreInfo.tanksNum1);
    window.draw(scoreInfo.tanksNum2);

    window.draw(scoreInfo.simpleTankPoints1);
    window.draw(scoreInfo.simpleTankPoints2);
    
    window.draw(scoreInfo.total1);
    window.draw(scoreInfo.total2);
    window.draw(scoreInfo.total3);
    window.draw(scoreInfo.total4);
    window.draw(scoreInfo.total5);
}