void getDirectBeforLimitX(sf::Vector2f tankPosition, int &direction)
{
    int randInt = getRandInRange(probRanges::begin, probRanges::secondEnd);
    
    if (randIntEqualProbCondition(randInt, LEFT_X_SIMPLE_LEFT))
    {
        direction = LEFT;
    }    
    else if (randIntEqualProbCondition(randInt, LEFT_X_SIMPLE_UP))
    {
        direction = UP;
    }    
    else if (randIntEqualProbCondition(randInt, LEFT_X_SIMPLE_RIGHT))
    {
        direction = RIGHT;
    }    
    else 
    { 
        direction = DOWN;
    }
}


void getDirectAfterLimitX(sf::Vector2f tankPosition, int &direction)
{
    int randInt = getRandInRange(probRanges::begin, probRanges::firstEnd);

    if (randIntEqualProbCondition(randInt, RIGHT_X_SIMPLE_RIGHT))
    {
        direction = RIGHT;
    }    
    else if (randIntEqualProbCondition(randInt, RIGHT_X_SIMPLE_UP))
    {
        direction = UP;
    }    
    else if (randIntEqualProbCondition(randInt, RIGHT_X_SIMPLE_LEFT))
    {
        direction = LEFT;
    }    
    else
    { 
        direction = DOWN;
    }
}


int getDirectBeforAttackLimitY(sf::Vector2f tankPosition)
{
    int direction = STOP;

    int randInt = getRandInRange(probRanges::begin, probRanges::firstEnd);

    if (tankPosition.x < TANK_ATTAC_LEFT_LIMIT_X)
    {
        getDirectBeforLimitX(tankPosition, direction);        
    }     
    else if (tankPosition.x >= TANK_ATTAC_LEFT_LIMIT_X)
    {
        getDirectAfterLimitX(tankPosition, direction);    
    }         
    return direction;
}


void getDirectMiddleAttackX(tank enemyTank, int &direction)
{
    int randInt = getRandInRange(probRanges::begin, probRanges::secondEnd);

    if (randIntEqualProbCondition(randInt, MIDDLE_X_ATTACK))
    {
        direction = UP;
    }    
    else 
    {
        if (enemyTank.direction == RIGHT)
        {
            direction = LEFT;
        }    
        else if (enemyTank.direction == LEFT)
        {
            direction = RIGHT;
        }    
        else
        {
            direction = UP;
        }            
    }
}


void getDirectSidesAttackX(sf::Vector2f tankPosition, int &direction)
{
    int randInt = getRandInRange(probRanges::begin, probRanges::firstEnd);
    
    if (tankPosition.x < TANK_ATTAC_LEFT_LIMIT_X)
    {
        if (randIntEqualProbCondition(randInt, LEFT_X_ATTACK))
        {
            direction = UP;
        }    
        else
        {                
            direction = RIGHT;
        }        
    }

    if (tankPosition.x > TANK_ATTAC_RIGHT_LIMIT_X)
    {
        if (randIntEqualProbCondition(randInt, RIGHT_X_ATTACK))
        {
            direction = UP;
        }
        else
        {    
            direction = LEFT; 
        }                      
    }
}


int getDirectAfterAttackLimitY(tank &enemyTank, sf::Vector2f tankPosition)
{
    int direction = STOP;

    if(tankPosition.x >= TANK_ATTAC_LEFT_LIMIT_X && tankPosition.x <= TANK_ATTAC_RIGHT_LIMIT_X)
    {
        getDirectMiddleAttackX(enemyTank, direction);           
    }
    else
    { 
        getDirectSidesAttackX(tankPosition, direction);
    }                 
    return direction;
}


void setShootFreaquency(tank &enemyTank, int levelShootFreaquency)
{
    sf::Vector2f tankPosition = enemyTank.box.getPosition();

    if (tankPosition.y > TANK_ATTAC_LIMIT_Y || enemyTank.direction == DOWN)
    {
        enemyTank.shootFreaquency = levelShootFreaquency / FAST_FREAQUENCY_INDEX;
    }
    else
    {
        enemyTank.shootFreaquency = levelShootFreaquency;
    }
}


void checkAttackLimitSetTankProps(tank &enemyTank, int levelShootFreaquency)
{
    sf::Vector2f tankPosition = enemyTank.box.getPosition();
    
    if (tankPosition.y <= TANK_ATTAC_LIMIT_Y)
    {
        enemyTank.direction = getDirectBeforAttackLimitY(tankPosition);
    } 
    else
    {
        enemyTank.direction = getDirectAfterAttackLimitY(enemyTank, tankPosition);
    }

    setShootFreaquency(enemyTank, levelShootFreaquency);
}