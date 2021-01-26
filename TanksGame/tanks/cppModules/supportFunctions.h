bool hasCollision(sf::RectangleShape firstRect, sf::RectangleShape secondRect)
{
    return firstRect.getGlobalBounds().intersects(secondRect.getGlobalBounds());
}


void initSmoothTexture(sf::Texture &texture)
{
    texture.setSmooth(true);
}


bool delayIsEquallTime(int delay, int timeToShow)
{
    return timeToShow % delay == 0 && timeToShow != 0;
}


bool probabillityEqualRand(int probabillity)
{
    return rand() % probabillity == 0;
}


int getRandInRange(int rangeBegin, int rangeEnd)
{
   return rand() % rangeEnd + rangeBegin;
}


bool isCollisedWithBarrier(moveSolutionStruct moveSolution)
{
    return !moveSolution.canMoveDown || !moveSolution.canMoveUp || !moveSolution.canMoveRight || !moveSolution.canMoveLeft;
}


bool randIntEqualProbCondition(int randInt, int conditionType)
{
    bool isEqual = false;
    switch (conditionType)
    {
        case MIDDLE_X_ATTACK:
            if(randInt == 2 || randInt == 6 || randInt == 10)
            {
                isEqual = true;
            }
            break;

        case LEFT_X_ATTACK:
            if (randInt == 2)
            {
                isEqual = true;
            }
            break;
            
        case RIGHT_X_ATTACK:
            if (randInt == 5)
            {
                isEqual = true;
            }    
            break;
        

        case LEFT_X_SIMPLE_LEFT:
            if (randInt == 6 || randInt == 10)
            {
                isEqual = true;
            }
            break;

        case LEFT_X_SIMPLE_RIGHT:
            if (randInt == 1 || randInt == 4 || randInt == 8)
            {
                isEqual = true;
            }
            break;
            
        case LEFT_X_SIMPLE_UP:
            if (randInt == 3)
            {
                isEqual = true;
            }    
            break;
            

        case RIGHT_X_SIMPLE_LEFT:
            if (randInt == 6 || randInt == 10 || randInt == 15)
            {
                isEqual = true;
            }
            break;

        case RIGHT_X_SIMPLE_RIGHT:
            if (randInt == 1 || randInt == 4)
            {
                isEqual = true;
            }
            break;
            
        case RIGHT_X_SIMPLE_UP:
            if (randInt == 3)
            {
                isEqual = true;
            }    
            break;

        default:
            isEqual = false;
            break;        
    }
    return isEqual;
}