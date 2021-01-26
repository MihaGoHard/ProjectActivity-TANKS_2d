void setEnemyTankDownProps(tank &enemyTank, float dt)
{
    if (enemyTank.moveSolution.canMoveDown)
    {
        sf::Vector2f tankPosition = enemyTank.box.getPosition();
        enemyTank.box.setPosition(tankPosition.x, tankPosition.y + enemyTank.speed * dt);
        
        if (enemyTank.state == ARMOR)
        {
            enemyTank.box.setTexture(&enemyTankDownArmorTexture);
        }  
        else if (enemyTank.state == SIMPLE)
        {
            enemyTank.box.setTexture(&enemyTankDownTexture);
        }
    }
}    


void setEnemyTankUpProps(tank &enemyTank, float dt)
{
    if (enemyTank.moveSolution.canMoveUp)
    {
        sf::Vector2f tankPosition = enemyTank.box.getPosition();
        enemyTank.box.setPosition(tankPosition.x, tankPosition.y - enemyTank.speed * dt);
        
        if (enemyTank.state == ARMOR)
        {
            enemyTank.box.setTexture(&enemyTankUpArmorTexture);
        }    
        else if (enemyTank.state == SIMPLE)
        {
            enemyTank.box.setTexture(&enemyTankUpTexture);
        }
    }
}    


void setEnemyTankLeftProps(tank &enemyTank, float dt)
{
    if (enemyTank.moveSolution.canMoveLeft)
    {
        sf::Vector2f tankPosition = enemyTank.box.getPosition();
        enemyTank.box.setPosition(tankPosition.x - enemyTank.speed * dt, tankPosition.y);
        
        if (enemyTank.state == ARMOR)
        {
            enemyTank.box.setTexture(&enemyTankLeftArmorTexture);
        }    
        else if (enemyTank.state == SIMPLE)
        {
            enemyTank.box.setTexture(&enemyTankLeftTexture);
        }
    }
}    


void setEnemyTankRightProps(tank &enemyTank, float dt)
{
    if (enemyTank.moveSolution.canMoveRight)
    {
        sf::Vector2f tankPosition = enemyTank.box.getPosition();
        enemyTank.box.setPosition(tankPosition.x + enemyTank.speed * dt, tankPosition.y);
        
        if (enemyTank.state == ARMOR)
        {
            enemyTank.box.setTexture(&enemyTankRightArmorTexture);
        }    
        else if (enemyTank.state == SIMPLE)
        {
            enemyTank.box.setTexture(&enemyTankRightTexture);
        }
    }
}    