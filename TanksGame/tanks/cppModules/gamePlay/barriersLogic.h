void initBricksAroundBase(world &tanksWorld)
{
    float startOffsetX = (BRICKS_BEFORE_BASE_X * BARRIER_WIDTH) + FIELD_OFFSET_X + BARRIER_WIDTH;
    float startOffsetY = (BRICKS_BEFORE_BASE_Y * BARRIER_WIDTH) + FIELD_OFFSET_Y + BARRIER_HEIGHT;
    float lineOffsetX = startOffsetX;
    float lineOffsetY = startOffsetY;

    for(int xBrickIndex = 0; xBrickIndex < BASE_BRICK_HEIGHT; xBrickIndex++)
    {
        for(int yBrickIndex = 0; yBrickIndex < BASE_BRICK_WIDTH; yBrickIndex++)
        {   
            if(!((xBrickIndex == 1 && yBrickIndex == 1) || (xBrickIndex == 1 && yBrickIndex == 2) || (xBrickIndex == 2 && yBrickIndex == 1) || (xBrickIndex == 2 && yBrickIndex == 2)))
            {
                barrierStruct newWall;
                newWall.box.setSize(sf::Vector2f{BARRIER_WIDTH, BARRIER_HEIGHT});
                newWall.box.setPosition(lineOffsetX, lineOffsetY);
                newWall.box.setTexture(&brickTexture);
                newWall.type = SIMPLE_BRICK;
                newWall.isPunched = true;
                tanksWorld.barriers.push_back(newWall);
            }      
            lineOffsetX = lineOffsetX + BARRIER_WIDTH;
        }
        lineOffsetX = startOffsetX;
        lineOffsetY = lineOffsetY + BARRIER_HEIGHT;
    }    
}


void initBaseBird(world &tanksWorld, float offsetX, float offsetY)
{
    barrierStruct newWall;
    newWall.box.setSize(sf::Vector2f{BIG_BARRIER_WIDTH, BIG_BARRIER_HEIGHT});
    newWall.box.setPosition(offsetX, offsetY);
    newWall.box.setTexture(&birdTexture);
    newWall.type = BASE_BIRD;
    newWall.isPunched = true;
    tanksWorld.barriers.push_back(newWall);
}


void initWallBlock(world &tanksWorld, float offsetX, float offsetY, int blockType)
{           
    for (int brickIndex = 0; brickIndex < BRICKS_IN_BLOCK; brickIndex++)
    {
        switch(brickIndex)
        {
            case 1:
                offsetX = offsetX + BARRIER_WIDTH; 
                break;
            case 2:
                offsetY = offsetY + BARRIER_HEIGHT;
                break;
            case 3:
                offsetX = offsetX - BARRIER_WIDTH;
                break;               
        }
   
        barrierStruct newWall;
        newWall.box.setSize(sf::Vector2f{BARRIER_WIDTH, BARRIER_HEIGHT});
        newWall.box.setPosition(offsetX, offsetY);

        switch(blockType)
        {
            case SIMPLE:
                newWall.isPunched = true;
                newWall.box.setTexture(&brickTexture);
                newWall.type = SIMPLE_BRICK;
                break;
            case ARMOR:
                newWall.isPunched = false;
                newWall.box.setTexture(&armorTexture);
                newWall.type = ARMOR_BRICK;
                break;
        }
        tanksWorld.barriers.push_back(newWall);
    } 
}


void initWaterBarrier(world &tanksWorld, float offsetX, float offsetY)
{
    for (int brickIndex = 0; brickIndex < BRICKS_IN_BLOCK; brickIndex++)
    {
        switch(brickIndex)
        {
            case 1:
                offsetX = offsetX + BARRIER_WIDTH; 
                break;
            case 2:
                offsetY = offsetY + BARRIER_HEIGHT;
                break;
            case 3:
                offsetX = offsetX - BARRIER_WIDTH;
                break;               
        }
        barrierStruct newWall;
        newWall.box.setSize(sf::Vector2f{BARRIER_WIDTH, BARRIER_HEIGHT});
        newWall.box.setPosition(offsetX, offsetY);
        newWall.box.setTexture(&waterTexture);
        newWall.type = WATER;
        tanksWorld.barriers.push_back(newWall);
    }
}


void initForestBarrier(world &tanksWorld, float offsetX, float offsetY)
{
    barrierStruct newWall;
    newWall.box.setSize(sf::Vector2f{BIG_BARRIER_WIDTH, BIG_BARRIER_HEIGHT});
    newWall.box.setPosition(offsetX, offsetY);
    newWall.box.setTexture(&forestTexture);
    newWall.type = FOREST;
    tanksWorld.barriers.push_back(newWall);
}


void initSandBarrier(world &tanksWorld, float offsetX, float offsetY)
{
    barrierStruct newWall;
    newWall.box.setSize(sf::Vector2f{BIG_BARRIER_WIDTH, BIG_BARRIER_HEIGHT});
    newWall.box.setPosition(offsetX, offsetY);
    newWall.box.setTexture(&sentTexture);
    newWall.type = SAND;
    tanksWorld.speedBarriers.push_back(newWall);
}


void initAsphaltBarrier(world &tanksWorld, float offsetX, float offsetY)
{
    barrierStruct newWall;
    newWall.box.setSize(sf::Vector2f{BIG_BARRIER_WIDTH, BIG_BARRIER_HEIGHT});
    newWall.box.setPosition(offsetX, offsetY);
    newWall.box.setTexture(&asphaltTexture);
    newWall.type = ASPHALT;
    tanksWorld.speedBarriers.push_back(newWall);
}


void initMapBarriers(world &tanksWorld)
{
    std::vector<std::vector<int>> map = tanksWorld.level.map;
    for (float mapString = 0; mapString < MAP_HEIGHT; mapString++)
    {
        for (float mapColumn = 0; mapColumn < MAP_WIDTH; mapColumn++)
        {
            switch (map[mapString][mapColumn])
            {
                case BASE:
                    initBaseBird(tanksWorld, (mapColumn * BARRIER_WIDTH * 2) + FIELD_OFFSET_X, (mapString * BARRIER_HEIGHT * 2) + FIELD_OFFSET_Y);
                    break;
                case BRICK_WALL:
                    initWallBlock(tanksWorld, (mapColumn * BARRIER_WIDTH * 2) + FIELD_OFFSET_X, (mapString * BARRIER_HEIGHT * 2) + FIELD_OFFSET_Y, SIMPLE); 
                    break;
                case ARMOR_WALL:
                    initWallBlock(tanksWorld, (mapColumn * BARRIER_WIDTH * 2) + FIELD_OFFSET_X, (mapString * BARRIER_HEIGHT * 2) + FIELD_OFFSET_Y, ARMOR); 
                    break;
                case FOREST_BLOCK:
                    initForestBarrier(tanksWorld, (mapColumn * BARRIER_WIDTH * 2) + FIELD_OFFSET_X, (mapString * BARRIER_HEIGHT * 2) + FIELD_OFFSET_Y); 
                    break;
                case WATER_BLOCK:
                    initWaterBarrier(tanksWorld, (mapColumn * BARRIER_WIDTH * 2) + FIELD_OFFSET_X, (mapString * BARRIER_HEIGHT * 2) + FIELD_OFFSET_Y);
                    break;
                case SAND_BLOCK:
                    initSandBarrier(tanksWorld, (mapColumn * BARRIER_WIDTH * 2) + FIELD_OFFSET_X, (mapString * BARRIER_HEIGHT * 2) + FIELD_OFFSET_Y);
                    break;
                case ASPHALT_BLOCK:
                    initAsphaltBarrier(tanksWorld, (mapColumn * BARRIER_WIDTH * 2) + FIELD_OFFSET_X, (mapString * BARRIER_HEIGHT * 2) + FIELD_OFFSET_Y);
                    break;
            }
        }
    }
}


void updateBarriers(world &tanksWorld)
{
    sf::Clock &clock = tanksWorld.time.effectClock; 
    std::vector<barrierStruct> &barriers = tanksWorld.barriers;
    int timeToShow = int(clock.getElapsedTime().asSeconds());
    for (int i = 0; i < barriers.size(); i++)
    {
        if (barriers[i].type == BASE_BIRD && barriers[i].contactWithShell)
        {
            if (!tanksWorld.time.restartClock)
            {   
                clock.restart().asSeconds();
                tanksWorld.time.restartClock = true;
                barriers[i].box.setTexture(&stoneTexture);    
            }
            else if (tanksWorld.time.restartClock && timeToShow % 2 == 0 && timeToShow != 0)
            {
                tanksWorld.time.restartClock = false;
                tanksWorld.worldStatus = LOSS;
            }
        }
        else if (barriers[i].isPunched && barriers[i].contactWithShell && barriers[i].type != FOREST)
        {
            tanksWorld.barriers.erase(tanksWorld.barriers.begin() + i);
        }    
    }
}