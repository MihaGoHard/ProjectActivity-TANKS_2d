void initLevelInfo(levelInfo &levelInfo)
{
    levelInfo.background.setSize(sf::Vector2f{WINDOW_WIDTH, WINDOW_HEIGHT});
    levelInfo.background.setFillColor(sf::Color(0x60, 0x60, 0x60));
    levelInfo.background.setPosition({0, 0});

    levelInfo.stageLabel.setSize(sf::Vector2f{LEVEL_INFO_WIDTH, LEVEL_INFO_HEIGHT});
    levelInfo.stageLabel.setTexture(&stage1Texture);
    levelInfo.stageLabel.setPosition(STAGE_LABEL_POSITION);
}


void checkDelaySetLevelSolution(gameStates &gameStates)
{
    sf::Clock clock = gameStates.time.effectClock;
    levelInfo &levelInfo = gameStates.levelInfo;
    int timeToShow = int(clock.getElapsedTime().asSeconds());

    if (delayIsEquallTime(SHOW_LEVEL_DELAY, timeToShow))
    {
        levelInfo.startGame = true;
    }
}


void setLevelNumber(gameStates &gameStates)
{
    levelInfo &levelInfo = gameStates.levelInfo;
    int levelNum = gameStates.tanksWorld.level.levelNumber;

    levelInfo.stageLabel.setTexture(&stageTextures[levelNum]);
}
