void gameKeyboardEvents(sf::RenderWindow &window, world &tanksWorld)
{
    int &moveCommand = tanksWorld.control.moveCommand;
    bool &shootCommand = tanksWorld.control.shootCommand;
    
    if (sf ::Keyboard ::isKeyPressed(sf ::Keyboard ::Space))
        shootCommand = true; 
    else
        shootCommand = false;       


    if (sf ::Keyboard ::isKeyPressed(sf ::Keyboard ::Up))
        moveCommand = UP;
    else if (sf ::Keyboard ::isKeyPressed(sf ::Keyboard ::Down))
        moveCommand = DOWN;
    else if (sf ::Keyboard ::isKeyPressed(sf ::Keyboard ::Left))
        moveCommand = LEFT;
    else if (sf ::Keyboard ::isKeyPressed(sf ::Keyboard ::Right))
        moveCommand = RIGHT; 
    else  
        moveCommand = STOP;    
}

void checkFieldSetSollution(tank &currTank)
{
    sf::Vector2f tankPosition = currTank.box.getPosition();

    if (tankPosition.x > LEFT_FIELD_BORDER)
        currTank.moveSolution.canMoveLeft = true;
    else 
        currTank.moveSolution.canMoveLeft = false;

    if (tankPosition.x < RIGHT_FIELD_BORDER - TANK_WIDTH)
        currTank.moveSolution.canMoveRight = true;
    else
        currTank.moveSolution.canMoveRight = false;

    if (tankPosition.y > TOP_FIELD_BORDER)
        currTank.moveSolution.canMoveUp = true;
    else    
        currTank.moveSolution.canMoveUp = false;

    if (tankPosition.y < BOTTOM_FIELD_BORDER - TANK_HEIGHT)
        currTank.moveSolution.canMoveDown = true;
    else    
        currTank.moveSolution.canMoveDown = false;
}

void checkBarrierSetSollution(tank &currTank, world &tanksWorld)
{
    float dt = tanksWorld.time.dt;
    std::vector<barrierStruct> barriers = tanksWorld.barriers;
    std::vector<barrierStruct> underBarriers = tanksWorld.speedBarriers;
    sf::Vector2f tankPosition = currTank.box.getPosition();

    
    if (currTank.speed == tanksWorld.level.bonusSpeed && tanksWorld.bonusStruct.activeBonus == SPEED_BONUS) 
        currTank.speed = tanksWorld.level.bonusSpeed;
    else 
        currTank.speed = tanksWorld.level.tanksSpeed;

    for (int i = 0; i < underBarriers.size(); i++)
    {
        if (checkCollision(currTank.box, underBarriers[i].box))
        {
            switch (underBarriers[i].type)
            {
                case ASPHALT:
                    currTank.speed = SECOND_SPEED;
                    break;
                case SENT:
                    currTank.speed = LOW_SPEED;
                    break;
            }    
        }
    }

    for (int i = 0; i < barriers.size(); i++)
    {
        if (barriers[i].type != FOREST)
        {
            sf::Vector2f barrierPosition = barriers[i].box.getPosition();
            if (checkCollision(currTank.box, barriers[i].box))
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


void checkTanksSetSollution(tank &currTank, world tanksWorld)
{
    std::vector<tank> tanks = tanksWorld.tanks;
    sf::Vector2f tankPosition = currTank.box.getPosition();
    int direction = currTank.direction;
    for (int i = 0; i < tanks.size(); i++)
    {
        sf::Vector2f otherTankPosition = tanks[i].box.getPosition();
        if (currTank.id != tanks[i].id && checkCollision(currTank.box, tanks[i].box))
        {
            if (tankPosition.x + TANK_WIDTH <= otherTankPosition.x + INTERSECTS_AREA && tankPosition.x < otherTankPosition.x)
                currTank.moveSolution.canMoveRight = false;

            else if (tankPosition.x >= otherTankPosition.x + TANK_WIDTH - INTERSECTS_AREA && tankPosition.x + TANK_WIDTH > otherTankPosition.x + TANK_WIDTH)
                currTank.moveSolution.canMoveLeft = false;

            else if (tankPosition.y + TANK_HEIGHT <= otherTankPosition.y + INTERSECTS_AREA && tankPosition.y < otherTankPosition.y)
                currTank.moveSolution.canMoveDown = false;

            else if (tankPosition.y >= otherTankPosition.y + TANK_HEIGHT - INTERSECTS_AREA && tankPosition.y + TANK_HEIGHT > otherTankPosition.y + TANK_HEIGHT)
                currTank.moveSolution.canMoveUp = false;
        }
    }
}


void checkBonusSetSollution(tank &currTank, world &tanksWorld)
{
    std::vector<bonus> &bonuses = tanksWorld.bonusStruct.bonuses;
    std::vector<tank> &tanks = tanksWorld.tanks;
    for (int i = 0; i < bonuses.size(); i++)
    {
        if (checkCollision(currTank.box, bonuses[i].box))
        {
            switch (bonuses[i].type)
            {
                case BOOM_BONUS: 
                    setBoomBonus(currTank, tanksWorld);
                    break;
            
                case TIME_BONUS:
                    setTimeBonus(currTank, tanksWorld);
                    break;
            
                case SPEED_BONUS: 
                    setSpeedBonus(currTank, tanksWorld);        
                    break;

                case ARMOR_BONUS:
                    setArmorBonus(currTank, tanksWorld);
                    break;
            }

            tanksWorld.bonusStruct.bonuses[i].eraseBonus = true;
            tanksWorld.time.bonusClock.restart().asSeconds();
        }
    }
}


void checkTankCollisionSetMoveSollution(world &tanksWorld)
{
    for (int j = 0; j < tanksWorld.tanks.size() && tanksWorld.tanks.size() != 0; j++)
    {
        bool tankIsDestroyed = false;
        tank &currTank = tanksWorld.tanks[j];
        std::vector<tank> tanks = tanksWorld.tanks;
        std::vector<barrierStruct> barriers = tanksWorld.barriers;
        std::vector<barrierStruct> speedBarriers = tanksWorld.speedBarriers;

        checkFieldSetSollution(currTank);

        checkBarrierSetSollution(currTank, tanksWorld);

        checkTanksSetSollution(currTank, tanksWorld);

        checkBonusSetSollution(currTank, tanksWorld);
    }
}
