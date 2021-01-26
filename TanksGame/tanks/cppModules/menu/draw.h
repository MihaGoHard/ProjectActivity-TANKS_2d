void drawMainMenu(sf::RenderWindow &window, mainMenu mainMenu)
{
    window.draw(mainMenu.mainBackground);
    window.draw(mainMenu.choicePointer.box);
}


void drawGameOver(sf::RenderWindow &window, gameOver gameOver)
{
    window.draw(gameOver.gameOverImg);
}


void drawLevelInfo(sf::RenderWindow &window, levelInfo levelInfo)
{
    window.draw(levelInfo.background);
    window.draw(levelInfo.stageLabel);
}


void drawNum(sf::RectangleShape &digitShape, int digit)
{
    switch (digit)
    {
        case 0:
            digitShape.setTexture(&num0Texture);
        case 1:
            digitShape.setTexture(&num1Texture);
        case 2:
            digitShape.setTexture(&num2Texture);
        case 3:
            digitShape.setTexture(&num3Texture);
        case 4:
            digitShape.setTexture(&num4Texture);
        case 5:
            digitShape.setTexture(&num5Texture);
        case 6:
            digitShape.setTexture(&num6Texture);    
        case 7:
            digitShape.setTexture(&num7Texture);
        case 8:
            digitShape.setTexture(&num8Texture);
        case 9:
            digitShape.setTexture(&num9Texture);
    }    
}

void drawScoreInfo(sf::RenderWindow &window, scoreInfo scoreInfo)
{
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