void setPlayerTankUpProps(tank &playerTank, float dt)
{
    if (playerTank.moveSolution.canMoveUp)
    {
        sf::Vector2f tankPosition = playerTank.box.getPosition();
        playerTank.box.setPosition(tankPosition.x, tankPosition.y - playerTank.speed * dt);
        if (playerTank.state == ARMOR)
        {
            playerTank.box.setTexture(&mainTankUpArmorTexture);
        }    
        else if (playerTank.state == SIMPLE)    
        {
        playerTank.box.setTexture(&mainTankUpTexture);
        }   
        playerTank.direction = UP;
    }    
}


void setPlayerTankDownProps(tank &playerTank, float dt)
{
    if (playerTank.moveSolution.canMoveDown)
    {
        sf::Vector2f tankPosition = playerTank.box.getPosition();
        playerTank.box.setPosition(tankPosition.x, tankPosition.y + playerTank.speed * dt);
        if (playerTank.state == ARMOR)
        {
            playerTank.box.setTexture(&mainTankDownArmorTexture);
        }    
        else if (playerTank.state == SIMPLE)
        {
            playerTank.box.setTexture(&mainTankDownTexture); 
        }       
        playerTank.direction = DOWN;
    }    
}


void setPlayerTankLeftProps(tank &playerTank, float dt)
{
    if (playerTank.moveSolution.canMoveLeft)
    {
        sf::Vector2f tankPosition = playerTank.box.getPosition();
        playerTank.box.setPosition(tankPosition.x - playerTank.speed * dt, tankPosition.y);
        if (playerTank.state == ARMOR)
        {
            playerTank.box.setTexture(&mainTankLeftArmorTexture);
        }    
        else if (playerTank.state == SIMPLE)
        {
            playerTank.box.setTexture(&mainTankLeftTexture); 
        }       
        playerTank.direction = LEFT;
    }    
}

void setPlayerTankRightProps(tank &playerTank, float dt)
{
    if (playerTank.moveSolution.canMoveRight)
    {
        sf::Vector2f tankPosition = playerTank.box.getPosition();
        playerTank.box.setPosition(tankPosition.x + playerTank.speed * dt, tankPosition.y);
        if (playerTank.state == ARMOR)
        {
            playerTank.box.setTexture(&mainTankRightArmorTexture);
        }    
        else if (playerTank.state == SIMPLE)
        {
            playerTank.box.setTexture(&mainTankRightTexture);
        }    
        playerTank.direction = RIGHT;
    }    
}