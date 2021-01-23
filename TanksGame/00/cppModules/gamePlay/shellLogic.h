void initShell(tank &currTank, world &tanksWorld)
{
    int direction = currTank.direction;
    sf::Vector2f tankPosition = currTank.box.getPosition();
    shell newShell;
    newShell.box.setSize(SHELL_SIZE);

    switch (direction)
    {
        case UP:
            newShell.box.setPosition(tankPosition.x + SHELL_POS_OFFSET, tankPosition.y - SHELL_TRUNK_OFFSET);
            newShell.box.setTexture(&shellUpTexture);
            break;
        case DOWN:
            newShell.box.setPosition(tankPosition.x + SHELL_POS_OFFSET, tankPosition.y + TANK_HEIGHT);
            newShell.box.setTexture(&shellDownTexture);
            break;
        case LEFT:
            newShell.box.setPosition(tankPosition.x - SHELL_TRUNK_OFFSET, tankPosition.y + SHELL_POS_OFFSET);
            newShell.box.setTexture(&shellLeftTexture);
            break;    
        case RIGHT:
            newShell.box.setPosition(tankPosition.x + TANK_WIDTH, tankPosition.y + SHELL_POS_OFFSET);
            newShell.box.setTexture(&shellRightTexture);
            break;
    }        

    if (currTank.id != PLAYER_ID)
        newShell.isEnemyShell = true;
        
    newShell.id = rand() % 4000;
    newShell.speed = tanksWorld.level.shellSpeed;
    currTank.shellId = newShell.id;
    newShell.box.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    newShell.direction = direction;
    tanksWorld.shells.push_back(newShell);
    currTank.shoot = false;
}


void updateShell(shell &shell, float dt)
{
    sf::Vector2f shellPosition = shell.box.getPosition();
    switch (shell.direction)
    {
        case UP:
            shell.box.setPosition(shellPosition.x, shellPosition.y - shell.speed * dt);
            break;
        case DOWN:
            shell.box.setPosition(shellPosition.x, shellPosition.y + shell.speed * dt);
            break;
        case LEFT:
            shell.box.setPosition(shellPosition.x - shell.speed * dt, shellPosition.y);
            break;
        case RIGHT:
            shell.box.setPosition(shellPosition.x + shell.speed * dt, shellPosition.y);
            break;
    }    
}


void updateShells(world &tanksWorld)
{
    for (int i = 0; i < tanksWorld.shells.size(); i++)
    {
        if (tanksWorld.shells[i].eraseShell)
        {
            sf::Vector2f shellPosition = tanksWorld.shells[i].box.getPosition();

            if (tanksWorld.shells[i].destroyedAimType == TANK && !tanksWorld.shells[i].enemyUnion)
              initExplosion(tanksWorld, shellPosition.x - 20.f, shellPosition.y - 20.f, BIG_EXPLOSION);
            else if (tanksWorld.shells[i].destroyedAimType == BARRIER)
              initExplosion(tanksWorld, shellPosition.x - 20.f, shellPosition.y - 20.f, SIMPLE_EXPLOSION); 

            tanksWorld.shells.erase(tanksWorld.shells.begin() + i);
        }
        else
            updateShell(tanksWorld.shells[i], tanksWorld.time.dt);
    }
}


void collisionWithFieldBorder(shell &currShell, bool &currShellDestroyed)
{
    sf::Vector2f shellPosition = currShell.box.getPosition();
    
    if (shellPosition.x <= LEFT_FIELD_BORDER || shellPosition.x >= RIGHT_FIELD_BORDER - SHELL_WIDTH || shellPosition.y <= TOP_FIELD_BORDER || shellPosition.y >= BOTTOM_FIELD_BORDER - SHELL_HEIGHT)
    {
        currShell.eraseShell = true;
        currShell.destroyedAimType = BARRIER;
        currShellDestroyed = true;    
    }
}


void checkShellTankCollision(shell &currShell, bool &currShellDestroyed, world &tanksWorld)
{
    for (int j = 0; j < tanksWorld.tanks.size(); j++)
    {
        tank &currTank = tanksWorld.tanks[j];
        if (checkCollision(currTank.box, currShell.box) && !currShellDestroyed)
        {
            if (currTank.state == ARMOR)
                currShell.destroyedAimType = BARRIER;
            else if (currTank.id != PLAYER_ID && currShell.isEnemyShell)
                currShell.enemyUnion = true;
            else if (currTank.id == PLAYER_ID && currShell.isEnemyShell)
            {
                currTank.eraseTank = true;
                tanksWorld.playerIsDestroyed = true;
                currShell.destroyedAimType = TANK;
            }
            else if (currTank.id != PLAYER_ID && !currShell.isEnemyShell)
            {
                currTank.eraseTank = true;
                tanksWorld.enemyIsDestroyed = true;
                currShell.destroyedAimType = TANK;
            }

            currShell.eraseShell = true;
            currShellDestroyed = true;
        }
    }
}


void checkShellsCollision(shell &currShell, bool &currShellDestroyed, world &tanksWorld)
{
    for (int n = 0; n < tanksWorld.shells.size() && !currShellDestroyed; n++)
    {
        if (currShell.id != tanksWorld.shells[n].id && checkCollision(currShell.box, tanksWorld.shells[n].box))
        {
            currShell.eraseShell = true;
            tanksWorld.shells[n].eraseShell = true;
            currShellDestroyed = true;
            currShell.destroyedAimType = BARRIER;
        }
    }
}


void checkShellBarrierCollision(shell &currShell, bool &currShellDestroyed, world &tanksWorld)
{
    for (int i = 0; i < tanksWorld.barriers.size() && !currShellDestroyed; i++)
    {
        if (tanksWorld.barriers[i].type != FOREST && tanksWorld.barriers[i].type != WATER)
        {
            sf::RectangleShape &currBarrier = tanksWorld.barriers[i].box;
            sf::RectangleShape &rightLeftBarrier = tanksWorld.barriers[i + 1].box;
            sf::RectangleShape &downBarrier = tanksWorld.barriers[i + 3].box;

            if (checkCollision(currShell.box, currBarrier))
            {
                if (tanksWorld.barriers[i].type == BIRD)
                    currShell.destroyedAimType = TANK;
                else
                    currShell.destroyedAimType = BARRIER;

                tanksWorld.barriers[i].contactWithShell = true;
                currShell.eraseShell = true;
                currShellDestroyed = true;            

                if (currShell.direction == RIGHT && checkCollision(currShell.box, downBarrier))
                    tanksWorld.barriers[i + 3].contactWithShell = true;

                if (checkCollision(currShell.box, rightLeftBarrier))
                    tanksWorld.barriers[i + 1].contactWithShell = true;
            }   
        }
    }
}


bool checkShellInShellsArr(int shellId, std::vector<shell> shells)
{
    bool shellInArr = false;
    for (int i = 0; i < shells.size(); i++)
    {
        if (shellId == shells[i].id)
            shellInArr = true;
    }
    return shellInArr;
}


void checkShellCollision(world &tanksWorld)
{
    bool currShellDestroyed = false;
    for (int i = 0; i < tanksWorld.shells.size(); i++)
    {
        shell &currShell = tanksWorld.shells[i];
        
        if (!currShellDestroyed)
            collisionWithFieldBorder(currShell, currShellDestroyed);

        if (!currShellDestroyed)
            checkShellTankCollision(currShell, currShellDestroyed, tanksWorld);

        if (!currShellDestroyed)
            checkShellsCollision(currShell, currShellDestroyed, tanksWorld);

        if (!currShellDestroyed)
            checkShellBarrierCollision(currShell, currShellDestroyed, tanksWorld);
        
        bool currShellDestroyed = false;    
    }
}