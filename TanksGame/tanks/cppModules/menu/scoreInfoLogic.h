void setDigitTexture(sf::RectangleShape &digitShape, int digit)
{
    digitShape.setTexture(&numTextures[digit]);        
}

void initScoreInfo(scoreInfo &scoreInfo)
{
    scoreInfo.background.setSize(sf::Vector2f{WINDOW_WIDTH, WINDOW_HEIGHT});
    scoreInfo.background.setTexture(&scoreTexture);
    scoreInfo.background.setPosition({0, 0});

    scoreInfo.stage.setSize(sf::Vector2f{SCORE_NUM_WIDTH, SCORE_NUM_HEIGHT});
    scoreInfo.stage.setTexture(&numTextures[0]);
    scoreInfo.stage.setPosition({SCORE_STAGE_POS_X, SCORE_STAGE_POS_Y});

    scoreInfo.tanksNum1.setSize(sf::Vector2f{SCORE_NUM_WIDTH, SCORE_NUM_HEIGHT});
    scoreInfo.tanksNum1.setTexture(&numTextures[0]);
    scoreInfo.tanksNum1.setPosition({SCORE_TANKS_NUM_POS_X, SCORE_TANKS_NUM_POS_Y});

    scoreInfo.tanksNum2.setSize(sf::Vector2f{SCORE_NUM_WIDTH, SCORE_NUM_HEIGHT});
    scoreInfo.tanksNum2.setTexture(&numTextures[0]);
    scoreInfo.tanksNum2.setPosition({SCORE_TANKS_NUM_POS_X + SCORE_NUM_WIDTH, SCORE_TANKS_NUM_POS_Y});


    scoreInfo.simpleTankPoints1.setSize(sf::Vector2f{SCORE_NUM_WIDTH, SCORE_NUM_HEIGHT});
    scoreInfo.simpleTankPoints1.setTexture(&numTextures[0]);
    scoreInfo.simpleTankPoints1.setPosition({SCORE_TANKS_POINTS_POS_X, SCORE_TANKS_POINTS_POS_Y});

    scoreInfo.simpleTankPoints2.setSize(sf::Vector2f{SCORE_NUM_WIDTH, SCORE_NUM_HEIGHT});
    scoreInfo.simpleTankPoints2.setTexture(&numTextures[0]);
    scoreInfo.simpleTankPoints2.setPosition({SCORE_TANKS_POINTS_POS_X + SCORE_NUM_WIDTH, SCORE_TANKS_POINTS_POS_Y});

    scoreInfo.total1.setSize(sf::Vector2f{SCORE_NUM_WIDTH, SCORE_NUM_HEIGHT});
    scoreInfo.total1.setTexture(&numTextures[0]);
    scoreInfo.total1.setPosition({SCORE_TOTAL_POS_X, SCORE_TOTAL_POS_Y});

    scoreInfo.total2.setSize(sf::Vector2f{SCORE_NUM_WIDTH, SCORE_NUM_HEIGHT});
    scoreInfo.total2.setTexture(&numTextures[0]);
    scoreInfo.total2.setPosition({SCORE_TOTAL_POS_X + SCORE_NUM_WIDTH, SCORE_TOTAL_POS_Y});

    scoreInfo.total3.setSize(sf::Vector2f{SCORE_NUM_WIDTH, SCORE_NUM_HEIGHT});
    scoreInfo.total3.setTexture(&numTextures[0]);
    scoreInfo.total3.setPosition({SCORE_TOTAL_POS_X + 2 * SCORE_NUM_WIDTH, SCORE_TOTAL_POS_Y});

    scoreInfo.total4.setSize(sf::Vector2f{SCORE_NUM_WIDTH, SCORE_NUM_HEIGHT});
    scoreInfo.total4.setTexture(&numTextures[0]);
    scoreInfo.total4.setPosition({SCORE_TOTAL_POS_X + 3 * SCORE_NUM_WIDTH, SCORE_TOTAL_POS_Y});

    scoreInfo.total5.setSize(sf::Vector2f{SCORE_NUM_WIDTH, SCORE_NUM_HEIGHT});
    scoreInfo.total5.setTexture(&numTextures[0]);
    scoreInfo.total5.setPosition({SCORE_TOTAL_POS_X + 4 * SCORE_NUM_WIDTH, SCORE_TOTAL_POS_Y});
}


void checkDelaySetNextState(gameStates &gameStates, bool isVictory)
{
    scoreInfo &scoreInfo = gameStates.scoreInfo;
    sf::Clock clock = gameStates.time.effectClock;
    int timeToShow = int(clock.getElapsedTime().asSeconds());
    
    if (delayIsEquallTime(SCORE_MENU_DELAY, timeToShow))
    {
        if (isVictory)
        {
            scoreInfo.nextState = NEXT_LEVEL;
        }    
        else
        {
            scoreInfo.nextState = MAIN_MENU;
        }    
    }
}


void calcScoreSetTextures(gameStates &gameStates)
{
    scoreInfo &scoreInfo = gameStates.scoreInfo;
    int stageNum = gameStates.tanksWorld.level.levelNumber + 1;
    setDigitTexture(scoreInfo.stage, stageNum);

    int destroyedTanksNum = gameStates.tanksWorld.score.enemyDestroyed;
    int placeDigitIndex = 2;
    do 
    {
        int digit = destroyedTanksNum % ROUND_INDEX;
        switch (placeDigitIndex)
        {
            case 2:
                setDigitTexture(scoreInfo.tanksNum2, digit);
                break;
            case 1:
                setDigitTexture(scoreInfo.tanksNum1, digit);
                break;
        }
        placeDigitIndex--;        

    } while (destroyedTanksNum /= ROUND_INDEX);


    int tankPoints = SIMPLE_TANK_POINTS;
    placeDigitIndex = 2;
    do 
    {
        int digit = tankPoints % ROUND_INDEX;
        switch (placeDigitIndex)
        {
            case 2:
                setDigitTexture(scoreInfo.simpleTankPoints2, digit);
                break;
            case 1:
                setDigitTexture(scoreInfo.simpleTankPoints1, digit);
                break;
        }        
        placeDigitIndex--;        

    } while (tankPoints /= ROUND_INDEX);

    
    int total = gameStates.tanksWorld.score.enemyDestroyed * SIMPLE_TANK_POINTS;
    placeDigitIndex = 5; 

    do 
    {
        int digit = total % ROUND_INDEX;
    
        switch (placeDigitIndex)
        {
            case 5:
                setDigitTexture(scoreInfo.total5, digit);
                break;
            case 4:
                setDigitTexture(scoreInfo.total4, digit);
                break;
            case 3:
                setDigitTexture(scoreInfo.total3, digit);
                break;
            case 2:
                setDigitTexture(scoreInfo.total2, digit);
                break;
            case 1:
                setDigitTexture(scoreInfo.total1, digit);
                break;
        }        
        placeDigitIndex--;   
    } while (total /= ROUND_INDEX);
}

