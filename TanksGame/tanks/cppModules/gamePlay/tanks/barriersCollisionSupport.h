void setCurrTankSpeedBeforeCollision(tank &currTank, world tanksWorld)
{
    if (currTank.speed == tanksWorld.level.bonusSpeed && tanksWorld.bonusStruct.activeBonus == SPEED_BONUS) 
    {
        currTank.speed = tanksWorld.level.bonusSpeed;
    }    
    else
    { 
        currTank.speed = tanksWorld.level.tanksSpeed;
    }
}

void checkSpeedBarriersSetProps(tank &currTank, std::vector<barrierStruct> underBarriers)
{
    for (int i = 0; i < underBarriers.size(); i++)
    {
        if (hasCollision(currTank.box, underBarriers[i].box))
        {
            switch (underBarriers[i].type)
            {
                case ASPHALT:
                    currTank.speed = SECOND_SPEED;
                    break;
                case SAND:
                    currTank.speed = LOW_SPEED;
                    break;
            }    
        }
    }
}

checkSimpleBarriersSetProps(tank &currTank, std::vector<barrierStruct> barriers)
{
    sf::Vector2f tankPosition = currTank.box.getPosition();
    for (int i = 0; i < barriers.size(); i++)
    {
        if (barriers[i].type != FOREST)
        {
            sf::Vector2f barrierPosition = barriers[i].box.getPosition();
            if (hasCollision(currTank.box, barriers[i].box))
            {
                switch (currTank.direction)
                {
                    case LEFT:
                        currTank.moveSolution.canMoveLeft = false;
                        currTank.box.setPosition(tankPosition.x + (barrierPosition.x + BARRIER_WIDTH - tankPosition.x), tankPosition.y);
                        break;

                    case RIGHT:
                        currTank.moveSolution.canMoveRight = false;
                        currTank.box.setPosition(tankPosition.x - (tankPosition.x + TANK_WIDTH - barrierPosition.x), tankPosition.y);
                        break;

                    case UP:
                        currTank.moveSolution.canMoveUp = false;
                        currTank.box.setPosition(tankPosition.x, tankPosition.y + (barrierPosition.y + BARRIER_HEIGHT - tankPosition.y));
                        break;

                    case DOWN:
                        currTank.moveSolution.canMoveDown = false;
                        currTank.box.setPosition(tankPosition.x, tankPosition.y - (tankPosition.y + TANK_HEIGHT - barrierPosition.y));
                        break;
                }
            }
        }
    }
}