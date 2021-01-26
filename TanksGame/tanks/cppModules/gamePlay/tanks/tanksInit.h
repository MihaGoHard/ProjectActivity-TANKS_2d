void setMainTankProps(tank &tank, world tanksWorld)
{
    tank.id = PLAYER_ID;
    tank.speed = tanksWorld.level.tanksSpeed;
    tank.shootFreaquency = tanksWorld.level.shootFreaquency;
    tank.box.setPosition(START_PLAYER_POS);
    tank.box.setTexture(&mainTankUpTexture);
}

void setEnemyTankProps(tank &tank, world &tanksWorld)
{
    float xPos = 0;
    float yPos = 0;
    sf::Vector2f appearPlace;
    int appearPosition = rand() % APPEAR_POS_3 + APPEAR_POS_1;
    if (tanksWorld.startPosition.firstAppearenceCount <= APPEAR_POS_3)
    {
        appearPlace = FIRST_ENEMY_POS;
        if (!tanksWorld.startPosition.secondPos)
        {
            appearPlace = SECOND_ENEMY_POS;
            tanksWorld.startPosition.secondPos = true;
        }
        else if (!tanksWorld.startPosition.thirdPos)
        {
            appearPlace = THIRD_ENEMY_POS;
            tanksWorld.startPosition.thirdPos = true;
        }
        tanksWorld.startPosition.firstAppearenceCount++;
    }
    else
    {
        switch (appearPosition)
        {
            case APPEAR_POS_1:
                appearPlace = FIRST_ENEMY_POS;
                break;
            case APPEAR_POS_2:
                appearPlace = SECOND_ENEMY_POS;
                break;
            case APPEAR_POS_3:
                appearPlace = THIRD_ENEMY_POS;
                break;
        }    
    }

    tank.speed = tanksWorld.level.tanksSpeed;
    tank.shootFreaquency = tanksWorld.level.shootFreaquency;
    tank.direction = DOWN;
    tank.id = rand() % 4000;
    tank.box.setPosition(appearPlace);
    tank.box.setTexture(&enemyTankUpTexture);    
}


void initTank(world &tanksWorld, bool mainTank)
{
    tank tank;
    tank.box.setSize(sf::Vector2f{TANK_WIDTH, TANK_HEIGHT});
    if (mainTank)
    {
        setMainTankProps(tank, tanksWorld);
    }
    else
    {
        setEnemyTankProps(tank, tanksWorld);
    }    
    tanksWorld.tanks.push_back(tank);
}


void initAllTanks(world &tanksWorld)
{
    initTank(tanksWorld, true);

    for (int i = 0; i < 3; i++)
    {
        initTank(tanksWorld, false);
    }    
}


void calcProbabillityInitTank(world &tanksWorld)
{
    int minNumOnField = tanksWorld.level.minEnemyNumOnField;
    int maxNumOnField = tanksWorld.level.maxEnemyNumOnField;
    int middleNumOnField = maxNumOnField - minNumOnField;
    
    if (tanksWorld.tanks.size() <= minNumOnField)
    {
        if (probabillityEqualRand(OFTEN_APPEAR_FREAQUENCY))
        {
            initTank(tanksWorld, false);
        }    
    }    
    else if (tanksWorld.tanks.size() > minNumOnField && tanksWorld.tanks.size() <= middleNumOnField)
    {
        if (probabillityEqualRand(MIDDLE_APPEAR_FREAQUENCY))
        {
            initTank(tanksWorld, false);
        }    
    }       
    else if (tanksWorld.tanks.size() > middleNumOnField && tanksWorld.tanks.size() <= maxNumOnField)
    {
        if (probabillityEqualRand(RARELY_APPEAR_FREAQUENCY))
        {
            initTank(tanksWorld, false);
        }    
    }
}

void initTanksAfterDestroy(world &tanksWorld)
{
    int maxNumOnField = tanksWorld.level.maxEnemyNumOnField;
    sf::Clock clock = tanksWorld.time.effectClock;
    int showTime = int(clock.getElapsedTime().asSeconds());

    if (tanksWorld.playerIsDestroyed)
    {
        initTank(tanksWorld, true);
        tanksWorld.playerIsDestroyed = false;
    }

    if (tanksWorld.enemyIsDestroyed)
    {
        tanksWorld.enemyIsDestroyed = false;
        clock.restart().asSeconds();
    }    
    else if (tanksWorld.bonusStruct.activeBonus != TIME_BONUS && tanksWorld.tanks.size() <= maxNumOnField)
    {               
        calcProbabillityInitTank(tanksWorld);
    }          
}
