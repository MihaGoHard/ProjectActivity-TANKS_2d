void setBoomBonus(tank &currTank, world &tanksWorld)
{
    std::vector<tank> &tanks = tanksWorld.tanks;
    switch (currTank.id) 
    { 
        case PLAYER_ID:
            tanksWorld.enemyIsDestroyed = true;
            tanksWorld.score.enemyDestroyed = tanksWorld.score.enemyDestroyed + (tanks.size() - 1);
            break;
        default:
            tanksWorld.playerIsDestroyed = true;    
            tanksWorld.score.playerDestroyed = tanksWorld.score.playerDestroyed + 1;
    }
    
    for (int j = 0; j < tanks.size(); j++)
    {
        if (tanks[j].id != currTank.id)
        {
            sf::Vector2f tankPosition = tanks[j].box.getPosition();
            if (currTank.id == PLAYER_ID)
            {
                tanks[j].eraseTank = true;
                if (tanksWorld.infoField.tankLabels.size() != 0)
                { 
                    tanksWorld.infoField.tankLabels.pop_back();
                }    
            }
            else if (currTank.id != PLAYER_ID && tanks[j].id == PLAYER_ID)
            {
                tanks[j].eraseTank = true;
            }    

            initExplosion(tanksWorld, tankPosition.x, tankPosition.y, BIG_EXPLOSION);           
        }    
    }
}


void setTimeBonus(tank &currTank, world &tanksWorld)
{
    std::vector<tank> &tanks = tanksWorld.tanks;
    tanksWorld.bonusStruct.activeBonus = TIME_BONUS;
    for (int j = 0; j < tanks.size(); j++)
    {
        if (tanks[j].id != currTank.id)
        {
            if (currTank.id == PLAYER_ID)
            {
                tanks[j].state = FREEZE;
                tanksWorld.bonusStruct.enemyBonus = false;
            }    
            if (currTank.id != PLAYER_ID && tanks[j].id == PLAYER_ID)
            {
                tanks[j].state = FREEZE;
                tanksWorld.bonusStruct.enemyBonus = true;
            }    
        }    
    }
}


void setSpeedBonus(tank &currTank, world &tanksWorld)
{
    tanksWorld.bonusStruct.activeBonus = SPEED_BONUS;
    currTank.speed = tanksWorld.level.bonusSpeed;
    tanksWorld.bonusStruct.tankId = currTank.id;
}


void setArmorBonus(tank &currTank, world &tanksWorld)
{
    tanksWorld.bonusStruct.activeBonus = ARMOR_BONUS;
    currTank.state = ARMOR;
    tanksWorld.bonusStruct.tankId = currTank.id;
}


sf::Vector2f calcBonusPosition(std::vector<std::vector<int>> map)
{
    sf::Vector2f newPosition = {0, 0};

    int minPos = 1;
    int maxXpos = 23;
    int maxYpos = 15;
    float randX = rand() % maxXpos + minPos;
    float randY = rand() % maxYpos + minPos; 

    if (map[randY][randX] == EMPTY_PLACE)
    {
        newPosition = {randX * BIG_BARRIER_WIDTH + FIELD_OFFSET_X, randY * BIG_BARRIER_HEIGHT + FIELD_OFFSET_Y};
    }    
    
    return newPosition;
}


void initBonus(world &tanksWorld, int resetTime)
{   
    sf::Vector2f bonusPosition = calcBonusPosition(tanksWorld.level.map);
    
    if (bonusPosition.x != 0 && bonusPosition.y != 0)
    {
        bonus bonus;
        bonus.type = rand() % SPEED_BONUS + BOOM_BONUS;
        bonus.resetTime = resetTime;
        bonus.box.setSize(sf::Vector2f{TANK_WIDTH, TANK_HEIGHT});
        switch (bonus.type)
        {
            case BOOM_BONUS:
                bonus.box.setTexture(&boomBonusTexture);
                break;
            case TIME_BONUS:
                bonus.box.setTexture(&timeBonusTexture);
                break;
            case ARMOR_BONUS:
                bonus.box.setTexture(&baseBonusTexture);  
                break;
            case SPEED_BONUS:
                bonus.box.setTexture(&speedBonusTexture);   
                break;   
        }        
        bonus.box.setPosition(bonusPosition);
        tanksWorld.bonusStruct.bonuses.push_back(bonus);
        tanksWorld.time.bonusClock.restart().asSeconds();
        
    }        
}


void initUpdateBonus(world &tanksWorld)
{
    sf::Clock &clock = tanksWorld.time.bonusClock;
    std::vector<bonus> &bonuses = tanksWorld.bonusStruct.bonuses;

    int timeToShow = int(clock.getElapsedTime().asSeconds());

    if (timeToShow % BONUS_APPEAR_TIME == 0 && timeToShow != 0 && bonuses.size() == 0 && tanksWorld.bonusStruct.activeBonus == NO_BONUS) 
    {
        initBonus(tanksWorld, BONUS_RESET_TIME);  
    }    

    if (tanksWorld.bonusStruct.activeBonus == BOOM_BONUS)
    {
        tanksWorld.bonusStruct.activeBonus = NO_BONUS; 
    }       
    else if (timeToShow == BONUS_EFFECT_LENGTH)
    {    
        std::vector<tank> &tanks= tanksWorld.tanks;
        switch(tanksWorld.bonusStruct.activeBonus)
        {
            case TIME_BONUS:
                for (int j = 0; j < tanks.size(); j++)
                {
                    if (tanksWorld.bonusStruct.enemyBonus && tanks[j].id == PLAYER_ID)
                    {
                        tanks[j].state = SIMPLE;
                    }    
                    else if (tanks[j].id != PLAYER_ID && tanks[j].state == FREEZE)
                    {
                        tanks[j].state = SIMPLE;       
                    } 
                }       
                break;
                
            case SPEED_BONUS:
                for (int j = 0; j < tanks.size(); j++)
                {
                    if (tanksWorld.bonusStruct.tankId == tanks[j].id)
                    {
                        tanks[j].speed = tanksWorld.level.tanksSpeed;
                    } 
                }       
                break;

            case ARMOR_BONUS:
                for (int j = 0; j < tanks.size(); j++)
                {
                    if (tanksWorld.bonusStruct.tankId == tanks[j].id)
                    {
                        tanks[j].state = SIMPLE;
                    }
                }        
                break;
        }        
        tanksWorld.bonusStruct.tankId = UNSET_ID;
        tanksWorld.bonusStruct.activeBonus = NO_BONUS;
        tanksWorld.time.bonusClock.restart().asSeconds();
    }    


    for (int i = 0; i < bonuses.size(); i++)
    {
        if (((timeToShow % bonuses[i].resetTime == 0) && (timeToShow != 0)) ||  bonuses[i].eraseBonus)
        {   
            if (!bonuses[i].eraseBonus)
            {
                tanksWorld.time.bonusClock.restart().asSeconds();
            }    
            bonuses.erase(bonuses.begin() + i);
        }    
    }        
}