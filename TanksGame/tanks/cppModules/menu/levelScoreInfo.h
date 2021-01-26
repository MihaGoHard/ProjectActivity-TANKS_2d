void initLevelInfo(levelInfo &levelInfo)
{
    levelInfo.background.setSize(sf::Vector2f{WINDOW_WIDTH, WINDOW_HEIGHT});
    levelInfo.background.setFillColor(sf::Color(0x60, 0x60, 0x60));
    levelInfo.background.setPosition({0, 0});

    levelInfo.stageLabel.setSize(sf::Vector2f{LEVEL_INFO_WIDTH, LEVEL_INFO_HEIGHT});
    levelInfo.stageLabel.setTexture(&stage1Texture);
    levelInfo.stageLabel.setPosition({650, 350});
}


void setLevelNumer(levelInfo &levelInfo, int levelNum)
{
    switch (levelNum)
    {
        case 0:
            levelInfo.stageLabel.setTexture(&stage1Texture);
            break;
        case 1:
            levelInfo.stageLabel.setTexture(&stage2Texture);
            break;
        case 2:
            levelInfo.stageLabel.setTexture(&stage3Texture);
            break;
        case 3:
            levelInfo.stageLabel.setTexture(&stage4Texture);
            break;
        case 4:
            levelInfo.stageLabel.setTexture(&stage5Texture);
            break;
        case 5:
            levelInfo.stageLabel.setTexture(&stage6Texture);
            break;
        case 6:
            levelInfo.stageLabel.setTexture(&stage7Texture);
            break;
        case 7:
            levelInfo.stageLabel.setTexture(&stage8Texture);
            break;
        case 8:
            levelInfo.stageLabel.setTexture(&stage9Texture);
            break;
        case 9:
            levelInfo.stageLabel.setTexture(&stage10Texture);     
            break;   
    }    
}


void initScoreInfo(scoreInfo &scoreInfo)
{
    scoreInfo.background.setSize(sf::Vector2f{WINDOW_WIDTH, WINDOW_HEIGHT});
    scoreInfo.background.setTexture(&scoreTexture);
    scoreInfo.background.setPosition({0, 0});

    scoreInfo.stage.setSize(sf::Vector2f{SCORE_NUM_WIDTH, SCORE_NUM_HEIGHT});
    scoreInfo.stage.setTexture(&num0Texture);
    scoreInfo.stage.setPosition({SCORE_STAGE_POS_X, SCORE_STAGE_POS_Y});

    scoreInfo.tanksNum1.setSize(sf::Vector2f{SCORE_NUM_WIDTH, SCORE_NUM_HEIGHT});
    scoreInfo.tanksNum1.setTexture(&num0Texture);
    scoreInfo.tanksNum1.setPosition({SCORE_TANKS_NUM_POS_X, SCORE_TANKS_NUM_POS_Y});

    scoreInfo.tanksNum2.setSize(sf::Vector2f{SCORE_NUM_WIDTH, SCORE_NUM_HEIGHT});
    scoreInfo.tanksNum2.setTexture(&num0Texture);
    scoreInfo.tanksNum2.setPosition({SCORE_TANKS_NUM_POS_X + SCORE_NUM_WIDTH, SCORE_TANKS_NUM_POS_Y});


    scoreInfo.simpleTankPoints1.setSize(sf::Vector2f{SCORE_NUM_WIDTH, SCORE_NUM_HEIGHT});
    scoreInfo.simpleTankPoints1.setTexture(&num0Texture);
    scoreInfo.simpleTankPoints1.setPosition({SCORE_TANKS_POINTS_POS_X, SCORE_TANKS_POINTS_POS_Y});

    scoreInfo.simpleTankPoints2.setSize(sf::Vector2f{SCORE_NUM_WIDTH, SCORE_NUM_HEIGHT});
    scoreInfo.simpleTankPoints2.setTexture(&num0Texture);
    scoreInfo.simpleTankPoints2.setPosition({SCORE_TANKS_POINTS_POS_X + SCORE_NUM_WIDTH, SCORE_TANKS_POINTS_POS_Y});

    scoreInfo.total1.setSize(sf::Vector2f{SCORE_NUM_WIDTH, SCORE_NUM_HEIGHT});
    scoreInfo.total1.setTexture(&num0Texture);
    scoreInfo.total1.setPosition({SCORE_TOTAL_POS_X, SCORE_TOTAL_POS_Y});

    scoreInfo.total2.setSize(sf::Vector2f{SCORE_NUM_WIDTH, SCORE_NUM_HEIGHT});
    scoreInfo.total2.setTexture(&num0Texture);
    scoreInfo.total2.setPosition({SCORE_TOTAL_POS_X + SCORE_NUM_WIDTH, SCORE_TOTAL_POS_Y});

    scoreInfo.total3.setSize(sf::Vector2f{SCORE_NUM_WIDTH, SCORE_NUM_HEIGHT});
    scoreInfo.total3.setTexture(&num0Texture);
    scoreInfo.total3.setPosition({SCORE_TOTAL_POS_X + 2 * SCORE_NUM_WIDTH, SCORE_TOTAL_POS_Y});

    scoreInfo.total4.setSize(sf::Vector2f{SCORE_NUM_WIDTH, SCORE_NUM_HEIGHT});
    scoreInfo.total4.setTexture(&num0Texture);
    scoreInfo.total4.setPosition({SCORE_TOTAL_POS_X + 3 * SCORE_NUM_WIDTH, SCORE_TOTAL_POS_Y});

    scoreInfo.total5.setSize(sf::Vector2f{SCORE_NUM_WIDTH, SCORE_NUM_HEIGHT});
    scoreInfo.total5.setTexture(&num0Texture);
    scoreInfo.total5.setPosition({SCORE_TOTAL_POS_X + 4 * SCORE_NUM_WIDTH, SCORE_TOTAL_POS_Y});
}


void setDigitTexture(sf::RectangleShape &digitShape, int digit)
{
    switch (digit)
    {
        case 0:
            digitShape.setTexture(&num0Texture);
            break;
        case 1:
            digitShape.setTexture(&num1Texture);
            break;
        case 2:
            digitShape.setTexture(&num2Texture);
            break;
        case 3:
            digitShape.setTexture(&num3Texture);
            break;
        case 4:
            digitShape.setTexture(&num4Texture);
            break;
        case 5:
            digitShape.setTexture(&num5Texture);
            break;
        case 6:
            digitShape.setTexture(&num6Texture);    
            break;
        case 7:
            digitShape.setTexture(&num7Texture);
            break;
        case 8:
            digitShape.setTexture(&num8Texture);
            break;
        case 9:
            digitShape.setTexture(&num9Texture);
            break;
    }        
}


void calcScoreSetTextures(scoreInfo &scoreInfo, gameStates gameStates)
{
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