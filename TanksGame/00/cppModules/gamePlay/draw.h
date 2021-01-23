void drawExplosions(sf::RenderWindow &window, world &tanksWorld)
{
    int timeIndex = 10;
    int effectInex = timeIndex;

    sf::Clock &clock = tanksWorld.time.explorClock;

    int msTime = clock.getElapsedTime().asMilliseconds() / timeIndex;
    
    for (int i = 0; i < tanksWorld.explosions.size(); i++)
    {
        if (tanksWorld.explosions[i].simple)
        {   
            window.draw(tanksWorld.explosions[i].box);
            tanksWorld.explosions[i].box.setTexture(&exploBiggerTexture);
               
            window.draw(tanksWorld.explosions[i].box);
            tanksWorld.explosions[i].box.setTexture(&exploBiggestTexture);
              
            window.draw(tanksWorld.explosions[i].box); 
        }
        else 
        {
              window.draw(tanksWorld.explosions[i].box);
              tanksWorld.explosions[i].box.setTexture(&exploHugerTexture);
          
              window.draw(tanksWorld.explosions[i].box);
              tanksWorld.explosions[i].box.setTexture(&exploHugestTexture);
              
              window.draw(tanksWorld.explosions[i].box);
        }     
    }
    
    
    if (msTime >= effectInex)
    {
        tanksWorld.explosions.clear();
        clock.restart().asMilliseconds();  
    }
}


void drawBarriers(sf::RenderWindow &window, world tanksWorld, float barrierKind)
{
    int intBarrierKind = barrierKind;
    if (tanksWorld.barriers.size() > 0)
    {

        switch (intBarrierKind)
        {
            case SIMPLE_BARRIER:
                for (int i = 0; i < tanksWorld.barriers.size(); i++)
                    if (tanksWorld.barriers[i].type != FOREST)
                        window.draw(tanksWorld.barriers[i].box);
                break;

            case FOREST_BARRIER:
                for (int i = 0; i < tanksWorld.barriers.size(); i++)
                    if (tanksWorld.barriers[i].type == FOREST)
                        window.draw(tanksWorld.barriers[i].box);
                break;

            case SPEED_BARRIER:
                for (int i = 0; i < tanksWorld.speedBarriers.size(); i++)
                    window.draw(tanksWorld.speedBarriers[i].box);
                break;
        }    
    }        
}


void drawTanks(sf::RenderWindow &window, world tanksWorld)
{
    for (int i = 0; i < tanksWorld.tanks.size(); i++)
        window.draw(tanksWorld.tanks[i].box);
}

void drawShells(sf::RenderWindow &window, world tanksWorld)
{
    for (int i = 0; i < tanksWorld.shells.size(); i++)
        window.draw(tanksWorld.shells[i].box);
}


void drawInfoField(sf::RenderWindow &window, world tanksWorld)
{
    window.draw(tanksWorld.infoField.box);
    window.draw(tanksWorld.infoField.livesLabel);
    for(int i = 0; i < tanksWorld.infoField.tankLabels.size(); i++)
        window.draw(tanksWorld.infoField.tankLabels[i]);
}

void drawInfoBattleFields(sf::RenderWindow &window, world tanksWorld)
{
    drawInfoField(window, tanksWorld);
    window.draw(tanksWorld.battleField);
}

void drawBonuses(sf::RenderWindow &window, std::vector<bonus> bonuses)
{
    for(int i = 0; i < bonuses.size(); i++)
        window.draw(bonuses[i].box);
}

void drawTanksWorld(sf::RenderWindow &window, world &tanksWorld)
{
    drawInfoBattleFields(window, tanksWorld);
    drawBarriers(window, tanksWorld, SPEED_BARRIER);
    drawBarriers(window, tanksWorld, SIMPLE_BARRIER);
    drawTanks(window, tanksWorld);
    drawShells(window, tanksWorld);
    drawExplosions(window, tanksWorld);
    drawBarriers(window, tanksWorld, FOREST_BARRIER);
    drawBonuses(window, tanksWorld.bonusStruct.bonuses);
}
