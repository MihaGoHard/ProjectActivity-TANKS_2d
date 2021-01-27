void initBattleField(world &tanksWorld)
{
    sf::RectangleShape &battleField = tanksWorld.battleField;
    battleField.setSize(sf::Vector2f{FIELD_WIDTH, FIELD_HEIGHT});
    battleField.setPosition(FIELD_OFFSET_X, FIELD_OFFSET_Y);
    battleField.setFillColor(sf::Color(0x00, 0x00, 0x00));
}


void initLivesLabel(world &tanksWorld)
{
    sf::RectangleShape &livesLabel = tanksWorld.infoField.livesLabel;
    livesLabel.setSize(sf::Vector2f{LIVE_LABEL_WIDTH, LIVE_LABEL_HEIGHT});
    livesLabel.setPosition(LIVE_LABEL_START_POS_X, LIVE_LABEL_START_POS_Y);
    livesLabel.setTexture(&liveLabelTextures[tanksWorld.score.playerDestroyed]); 
}


void initTankLabels(world &tanksWorld)
{
    float offsetIndex = 1.4;
    int labelsColumnNum = 2;
    sf::Vector2f position = {TANK_LABEL_START_POS_X, TANK_LABEL_START_POS_Y};

    for(int labelNum = 1; labelNum <= tanksWorld.level.enemyNumDestroyToWin; labelNum++)
    {
        std::vector<sf::RectangleShape> &tankLabelsArr = tanksWorld.infoField.tankLabels;
        sf::RectangleShape tankLabel;
        tankLabel.setSize(sf::Vector2f({BARRIER_WIDTH, BARRIER_HEIGHT}));
        if (labelNum > 1)
        {
            sf::Vector2f prevLabelPos = tankLabelsArr[labelNum - labelsColumnNum].getPosition();
            if (labelNum % labelsColumnNum == 0)
            {
                position = {prevLabelPos.x + BARRIER_WIDTH * offsetIndex, prevLabelPos.y};
            }
            else
            {
                position = {prevLabelPos.x - BARRIER_WIDTH * offsetIndex, prevLabelPos.y + BARRIER_HEIGHT};    
            }    
        }
        tankLabel.setPosition(position);
        tankLabel.setTexture(&tankLabelTexture);
        tankLabelsArr.push_back(tankLabel);
    }    
}


void initGameInfoField(world &tanksWorld)
{
    gameInfoField infoField;
    infoField.box.setSize(sf::Vector2f{WINDOW_WIDTH, WINDOW_HEIGHT});
    infoField.box.setFillColor(sf::Color(0x60, 0x60, 0x60));
    tanksWorld.infoField = infoField;

    initTankLabels(tanksWorld);

    initLivesLabel(tanksWorld);
}


void updateTankLabels(world &tanksWorld)
{
    if (tanksWorld.enemyIsDestroyed && tanksWorld.infoField.tankLabels.size() != 0) 
    {
        tanksWorld.infoField.tankLabels.pop_back();
    }    
}


void updateLivesLabels(world &tanksWorld)
{
    if (tanksWorld.score.playerDestroyed < PLAYER_LIVES_NUM)
    {
        tanksWorld.infoField.livesLabel.setTexture(&liveLabelTextures[tanksWorld.score.playerDestroyed]);
    }           
}