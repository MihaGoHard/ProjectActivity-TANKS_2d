void initScore(world &tanksWorld)
{
    tanksWorld.score.enemyDestroyed = 0;
    tanksWorld.score.playerDestroyed = 0;
}


void updateScore(world &tanksWorld)
{
    sf::Clock &clock = tanksWorld.time.effectClock;
    int timeToShow = int(clock.getElapsedTime().asSeconds());

    if (tanksWorld.enemyIsDestroyed)
        tanksWorld.score.enemyDestroyed = tanksWorld.score.enemyDestroyed + 1;

    if (tanksWorld.playerIsDestroyed)
        tanksWorld.score.playerDestroyed = tanksWorld.score.playerDestroyed + 1;   
        
    if (tanksWorld.score.enemyDestroyed >= tanksWorld.level.enemyNumDestroyToWin)
    {
        if (tanksWorld.time.restartClock && timeToShow % 2 == 0 && timeToShow != 0)
        {
            tanksWorld.time.restartClock = false;
            tanksWorld.worldStatus = WIN;
        }
        else if (!tanksWorld.time.restartClock)
        {
            clock.restart().asSeconds();
            tanksWorld.time.restartClock = true;
        }
    }   

    if (tanksWorld.score.playerDestroyed >= PLAYER_LIVES_NUM)
    {
        if (tanksWorld.time.restartClock && timeToShow % DELAY_AFTER_GAME == 0 && timeToShow != 0)
        {
            tanksWorld.time.restartClock = false;
            tanksWorld.worldStatus = LOSS;
        }
        else if (!tanksWorld.time.restartClock)
        {
            clock.restart().asSeconds();
            tanksWorld.time.restartClock = true;
        }
    }          
}