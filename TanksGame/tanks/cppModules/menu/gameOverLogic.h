void initGameOver(gameOver &gameOver)
{
    if (!gameOver.gameOverInited)
    {    
        sf::RectangleShape &gameOverImg = gameOver.gameOverImg;
        gameOverImg.setSize(sf::Vector2f{GAME_OVER_WIDTH, GAME_OVER_HEIGHT});
        gameOverImg.setPosition(GAME_OVER_START_POSITION_X, GAME_OVER_START_POSITION_Y);
        gameOverImg.setTexture(&gameOverTexture);
        gameOver.gameOverInited = true;
    }    
}


void raiseGameOverImg(gameOver &gameOver, sf::Clock &clock)
{
    int timeToShow = int(clock.getElapsedTime().asSeconds());
    sf::RectangleShape &gameOverImg = gameOver.gameOverImg;
    sf::Vector2f gameOverImgPosition = gameOverImg.getPosition();
    
    if (gameOverImgPosition.y >= GAME_OVER_LIMIT_POSITION_Y)
    {
        gameOverImg.setPosition(GAME_OVER_START_POSITION_X, gameOverImgPosition.y - RAISE_SPEED_GAME_OVER * gameOver.dt);
        clock.restart().asSeconds();
    }    
    else if (delayIsEquallTime(GAME_OVER_DELAY, timeToShow))
    {
        gameOver.showScore = true;
        gameOver.gameOverInited = false;
    }    
}