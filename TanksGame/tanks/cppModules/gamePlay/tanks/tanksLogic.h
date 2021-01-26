void updatePlayerTank(tank &playerTank, world &tanksWorld)
{
    int &moveCommand = tanksWorld.control.moveCommand;
    float dt = tanksWorld.time.dt;
    bool &shootCommand = tanksWorld.control.shootCommand;

    if (playerTank.state != FREEZE)
    {
        switch (moveCommand)
        {
            case UP:
                setPlayerTankUpProps(playerTank, dt);
                break;
            case DOWN: 
                setPlayerTankDownProps(playerTank, dt);
                break;
            case LEFT:
                setPlayerTankLeftProps(playerTank, dt);
                break;
            case RIGHT:
                setPlayerTankRightProps(playerTank, dt);
                break;
        }    
    }

    if (shootCommand && !shellInShellsArr(playerTank.shellId, tanksWorld.shells))
    {
        initShell(playerTank, tanksWorld);
    }    
}


void updateEnemyTank(tank &enemyTank, world &tanksWorld)
{
    int changeDirectProbability = 250;
    float dt = tanksWorld.time.dt;
    int shootFreaquency = tanksWorld.level.shootFreaquency;
    
    if (enemyTank.state != FREEZE)
    {
        if (isCollisedWithBarrier(enemyTank.moveSolution) || probabillityEqualRand(changeDirectProbability))
        { 
            checkAttackLimitSetTankProps(enemyTank, shootFreaquency);
        }       

        switch (enemyTank.direction)
        {
            case DOWN:
                setEnemyTankDownProps(enemyTank, dt);    
                break;
            case UP:
                setEnemyTankUpProps(enemyTank, dt);    
                break;
            case LEFT:
                setEnemyTankLeftProps(enemyTank, dt);     
                break;
            case RIGHT:
                setEnemyTankRightProps(enemyTank, dt);    
                break;
        }    
    }    

    if (probabillityEqualRand(enemyTank.shootFreaquency) && !shellInShellsArr(enemyTank.shellId, tanksWorld.shells))
    {
        initShell(enemyTank, tanksWorld);    
    }
}


void updateTanks(world &tanksWorld)
{
    std::vector<tank> &tanks = tanksWorld.tanks;

    for (int i = 0; i < tanks.size(); i++)
    {
        if (tanks[i].eraseTank)
        {
            tanksWorld.tanks.erase(tanksWorld.tanks.begin() + i);
        }
        else
        {
            if (tanks[i].id == PLAYER_ID)
            {
                updatePlayerTank(tanks[i], tanksWorld);
            }    
            else
            {
                updateEnemyTank(tanks[i], tanksWorld);
            }    
        }
    }
}