void gameKeyboardEvents(sf::RenderWindow &window, world &tanksWorld)
{
    int &moveCommand = tanksWorld.control.moveCommand;
    bool &shootCommand = tanksWorld.control.shootCommand;

    shootCommand = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);       

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        moveCommand = UP;
    }    
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        moveCommand = DOWN;
    }    
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        moveCommand = LEFT;
    }    
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        moveCommand = RIGHT; 
    }    
    else  
    {
        moveCommand = STOP; 
    }       
}


void checkFieldSetSolution(tank &currTank)
{
    sf::Vector2f tankPosition = currTank.box.getPosition();

    currTank.moveSolution.canMoveLeft = tankPosition.x > LEFT_FIELD_BORDER;
        
    currTank.moveSolution.canMoveRight = tankPosition.x < RIGHT_FIELD_BORDER - TANK_WIDTH;
        
    currTank.moveSolution.canMoveUp = tankPosition.y > TOP_FIELD_BORDER;
        
    currTank.moveSolution.canMoveDown = tankPosition.y < BOTTOM_FIELD_BORDER - TANK_HEIGHT;    
}


void checkBarrierSetSolution(tank &currTank, world &tanksWorld)
{
    float dt = tanksWorld.time.dt;
    std::vector<barrierStruct> barriers = tanksWorld.barriers;
    std::vector<barrierStruct> underBarriers = tanksWorld.speedBarriers;

    setCurrTankSpeedBeforeCollision(currTank, tanksWorld);    

    checkSpeedBarriersSetProps(currTank, underBarriers);

    checkSimpleBarriersSetProps(currTank, barriers);
}


void checkTanksSetSolution(tank &currTank, world tanksWorld)
{
    std::vector<tank> tanks = tanksWorld.tanks;
    sf::Vector2f tankPosition = currTank.box.getPosition();
    int direction = currTank.direction;
    for (int i = 0; i < tanks.size(); i++)
    {
        sf::Vector2f otherTankPosition = tanks[i].box.getPosition();
        if (currTank.id != tanks[i].id && hasCollision(currTank.box, tanks[i].box))
        {
            if (tankPosition.x + TANK_WIDTH <= otherTankPosition.x + INTERSECTS_AREA && tankPosition.x < otherTankPosition.x)
            {
                currTank.moveSolution.canMoveRight = false;
            }    
            else if (tankPosition.x >= otherTankPosition.x + TANK_WIDTH - INTERSECTS_AREA && tankPosition.x + TANK_WIDTH > otherTankPosition.x + TANK_WIDTH)
            { 
                currTank.moveSolution.canMoveLeft = false;
            }    
            else if (tankPosition.y + TANK_HEIGHT <= otherTankPosition.y + INTERSECTS_AREA && tankPosition.y < otherTankPosition.y)
            { 
                currTank.moveSolution.canMoveDown = false;
            }    
            else if (tankPosition.y >= otherTankPosition.y + TANK_HEIGHT - INTERSECTS_AREA && tankPosition.y + TANK_HEIGHT > otherTankPosition.y + TANK_HEIGHT)
            { 
                currTank.moveSolution.canMoveUp = false;
            }    
        }
    }
}


void checkBonusSetSolution(tank &currTank, world &tanksWorld)
{
    std::vector<bonus> &bonuses = tanksWorld.bonusStruct.bonuses;
    std::vector<tank> &tanks = tanksWorld.tanks;
    for (int i = 0; i < bonuses.size(); i++)
    {
        if (hasCollision(currTank.box, bonuses[i].box))
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


void setTanksMoveSolution(world &tanksWorld)
{
    for (int j = 0; j < tanksWorld.tanks.size() && tanksWorld.tanks.size() != 0; j++)
    {
        bool tankIsDestroyed = false;
        tank &currTank = tanksWorld.tanks[j];
        std::vector<tank> tanks = tanksWorld.tanks;
        std::vector<barrierStruct> barriers = tanksWorld.barriers;
        std::vector<barrierStruct> speedBarriers = tanksWorld.speedBarriers;

        checkFieldSetSolution(currTank);

        checkBarrierSetSolution(currTank, tanksWorld);

        checkTanksSetSolution(currTank, tanksWorld);

        checkBonusSetSolution(currTank, tanksWorld);
    }
}