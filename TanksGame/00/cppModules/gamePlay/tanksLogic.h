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
        setMainTankProps(tank, tanksWorld);
    else
        setEnemyTankProps(tank, tanksWorld);
    tanksWorld.tanks.push_back(tank);
}


void initAllTanks(world &tanksWorld)
{
    initTank(tanksWorld, true);

    for (int i = 0; i < 3; i++)
        initTank(tanksWorld, false);
}


void checkTanksDestroyInitNewTanks(world &tanksWorld)
{
    int minNumOnField = tanksWorld.level.minEnemyNumOnField;
    int maxNumOnField = tanksWorld.level.maxEnemyNumOnField;
    int middleNumOnField = maxNumOnField - minNumOnField;
    
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

        if (tanksWorld.tanks.size() <= minNumOnField)
        {
            if (rand() % OFTEN_APPEAR_FREAQUENCY == 0)
                initTank(tanksWorld, false);
        }    
        else if (tanksWorld.tanks.size() > minNumOnField && tanksWorld.tanks.size() <= middleNumOnField)
        {
            if (rand() % MIDDLE_APPEAR_FREAQUENCY == 0)
                initTank(tanksWorld, false);
        }       
        else if (tanksWorld.tanks.size() > middleNumOnField && tanksWorld.tanks.size() <= maxNumOnField)
        {
            if (rand() % RARELY_APPEAR_FREAQUENCY == 0)
                initTank(tanksWorld, false);
        }
    }          
}


void updatePlayerTank(tank &playerTank, world &tanksWorld)
{
    sf::Vector2f tankPosition = playerTank.box.getPosition();
    float tankSpeed = playerTank.speed;
    int &moveCommand = tanksWorld.control.moveCommand;
    float dt = tanksWorld.time.dt;
    bool &shootCommand = tanksWorld.control.shootCommand;

    if (playerTank.state != FREEZE)
    {
        if (moveCommand == UP && playerTank.moveSolution.canMoveUp)
        {
            playerTank.box.setPosition(tankPosition.x, tankPosition.y - playerTank.speed * tanksWorld.time.dt);
            if (playerTank.state == ARMOR)
                playerTank.box.setTexture(&mainTankUpArmorTexture);
            else if (playerTank.state == SIMPLE)    
               playerTank.box.setTexture(&mainTankUpTexture);
            playerTank.direction = UP;
        }
        else if (moveCommand == DOWN && playerTank.moveSolution.canMoveDown)
        {
            playerTank.box.setPosition(tankPosition.x, tankPosition.y + playerTank.speed * tanksWorld.time.dt);
            if (playerTank.state == ARMOR)
                playerTank.box.setTexture(&mainTankDownArmorTexture);
            else if (playerTank.state == SIMPLE)
                playerTank.box.setTexture(&mainTankDownTexture);    
            playerTank.direction = DOWN;
        }
        else if (moveCommand == LEFT && playerTank.moveSolution.canMoveLeft)
        {
            playerTank.box.setPosition(tankPosition.x - playerTank.speed * tanksWorld.time.dt, tankPosition.y);
            if (playerTank.state == ARMOR)
                playerTank.box.setTexture(&mainTankLeftArmorTexture);
            else if (playerTank.state == SIMPLE)
                playerTank.box.setTexture(&mainTankLeftTexture);    
            playerTank.direction = LEFT;
        }
        else if (moveCommand == RIGHT && playerTank.moveSolution.canMoveRight)
        {
            playerTank.box.setPosition(tankPosition.x + playerTank.speed * tanksWorld.time.dt, tankPosition.y);
            if (playerTank.state == ARMOR)
                playerTank.box.setTexture(&mainTankRightArmorTexture);
            else if (playerTank.state == SIMPLE)
                playerTank.box.setTexture(&mainTankRightTexture);
            playerTank.direction = RIGHT;
        }
    }

    if (shootCommand && !checkShellInShellsArr(playerTank.shellId, tanksWorld.shells))
        initShell(playerTank, tanksWorld);

}


void checkAttackLimitSetTankProps(tank &enemyTank)
{
    sf::Vector2f tankPosition = enemyTank.box.getPosition();
    if (tankPosition.y > TANK_ATTAC_LIMIT_Y)
    {  
        enemyTank.shootFreaquency = ENEMY_TANK_FAST_SHOOT_FREAQUENCY;
        int randInt = rand() % 20 + 1;
        if(tankPosition.x >= TANK_ATTAC_LEFT_LIMIT_X && tankPosition.x <= TANK_ATTAC_RIGHT_LIMIT_X)
        {
            if (randInt == 2 || randInt == 6 || randInt == 10)
                enemyTank.direction = UP;
            else 
            {
                if (enemyTank.direction == RIGHT)
                    enemyTank.direction = LEFT;
                else if (enemyTank.direction == LEFT)
                    enemyTank.direction = RIGHT;
                else
                    enemyTank.direction = UP;        
            }       
        }
        else
        { 
            int randInt = rand() % 15 + 1;
            if (tankPosition.x < TANK_ATTAC_LEFT_LIMIT_X)
                if (randInt == 2 || randInt == 6 || randInt == 10)
                    enemyTank.direction == UP;
                else                
                    enemyTank.direction = RIGHT;    

            if (tankPosition.x > TANK_ATTAC_RIGHT_LIMIT_X)
                if (randInt == 4 || randInt == 15 || randInt == 1)
                    enemyTank.direction == UP;
                else    
                    enemyTank.direction = LEFT;                   
            
        }                 
    }
    if (tankPosition.y <= TANK_ATTAC_LIMIT_Y)
    {
        int randInt = rand() % 15 + 1;
        enemyTank.shootFreaquency = ENEMY_TANK_SIMPLE_SHOOT_FREAQUENCY;
        if (tankPosition.x < TANK_ATTAC_LEFT_LIMIT_X)
        {
            if (randInt == 6 || randInt == 10)
                enemyTank.direction = LEFT;
            else if (randInt == 3)
                enemyTank.direction = UP;
            else if (randInt == 1 || randInt == 4 || randInt == 8)
                enemyTank.direction = RIGHT;
            else 
                enemyTank.direction = DOWN;
        }     
        else if (tankPosition.x >= TANK_ATTAC_LEFT_LIMIT_X)
        {
            if (randInt == 1 || randInt == 4)
                enemyTank.direction = RIGHT;
            else if (randInt == 3)
                enemyTank.direction = UP;
            else if (randInt == 6 || randInt == 10 || randInt == 15)
                enemyTank.direction = LEFT;
            else 
                enemyTank.direction = DOWN;
        }         
    }
}


void updateEnemyTank(tank &enemyTank, world &tanksWorld)
{
    sf::Vector2f tankPosition = enemyTank.box.getPosition();
    if (enemyTank.state != FREEZE)
    {
        if (!enemyTank.moveSolution.canMoveDown || !enemyTank.moveSolution.canMoveUp || !enemyTank.moveSolution.canMoveRight || !enemyTank.moveSolution.canMoveLeft)
            enemyTank.direction = STOP;

        if (rand() % 300 == 0)
        {
            enemyTank.moveSolution.canMoveDown = enemyTank.moveSolution.canMoveUp = false;
            enemyTank.moveSolution.canMoveRight = enemyTank.moveSolution.canMoveLeft = false;
            enemyTank.direction = STOP;
        }

        if (enemyTank.direction == STOP) 
            checkAttackLimitSetTankProps(enemyTank);

        if (enemyTank.moveSolution.canMoveDown && enemyTank.direction == DOWN)
        {
            enemyTank.box.setPosition(tankPosition.x, tankPosition.y + enemyTank.speed * tanksWorld.time.dt);
            if (enemyTank.state == ARMOR)
              enemyTank.box.setTexture(&enemyTankDownArmorTexture);
            else if (enemyTank.state == SIMPLE)
              enemyTank.box.setTexture(&enemyTankDownTexture);
        }

        if (enemyTank.moveSolution.canMoveUp && enemyTank.direction == UP)
        {
            enemyTank.box.setPosition(tankPosition.x, tankPosition.y - enemyTank.speed * tanksWorld.time.dt);
            if (enemyTank.state == ARMOR)
                enemyTank.box.setTexture(&enemyTankUpArmorTexture);
            else if (enemyTank.state == SIMPLE)
                enemyTank.box.setTexture(&enemyTankUpTexture);
        }
        
        if (enemyTank.moveSolution.canMoveLeft && enemyTank.direction == LEFT)
        {
            enemyTank.box.setPosition(tankPosition.x - enemyTank.speed * tanksWorld.time.dt, tankPosition.y);
            if (enemyTank.state == ARMOR)
                enemyTank.box.setTexture(&enemyTankLeftArmorTexture);
            else if (enemyTank.state == SIMPLE)
                enemyTank.box.setTexture(&enemyTankLeftTexture);
        }
        
        if (enemyTank.moveSolution.canMoveRight && enemyTank.direction == RIGHT)
        {
            enemyTank.box.setPosition(tankPosition.x + enemyTank.speed * tanksWorld.time.dt, tankPosition.y);
            if (enemyTank.state == ARMOR)
                enemyTank.box.setTexture(&enemyTankRightArmorTexture);
            else if (enemyTank.state == SIMPLE)
                enemyTank.box.setTexture(&enemyTankRightTexture);
        }
    }    

    if (rand() % enemyTank.shootFreaquency == 0)
    {
        if (!checkShellInShellsArr(enemyTank.shellId, tanksWorld.shells))
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
                updatePlayerTank(tanks[i], tanksWorld);
            else
                updateEnemyTank(tanks[i], tanksWorld);
        }
    }
}