struct gameOver
{
    float dt;
    sf::RectangleShape gameOverImg;
    bool showScore = false;
    bool gameOverInited = false;
};


struct levelInfo
{
    sf::RectangleShape background;
    sf::RectangleShape stageLabel;
    bool startGame = false;
};


struct scoreInfo
{
    sf::RectangleShape background;
    sf::RectangleShape stage;

    sf::RectangleShape tanksNum1;
    sf::RectangleShape tanksNum2;

    sf::RectangleShape simpleTankPoints1;
    sf::RectangleShape simpleTankPoints2;

    sf::RectangleShape total1;
    sf::RectangleShape total2;
    sf::RectangleShape total3;
    sf::RectangleShape total4;
    sf::RectangleShape total5;
    int nextState = WAIT;
};


struct choicePointer
{
    sf::RectangleShape box;
    bool startPos = true;
};


struct mainMenuControl
{
    bool up = false;
    bool down = false;
    bool enter = false;
};


struct mainMenu
{
    float dt;
    choicePointer choicePointer;
    sf::RectangleShape mainBackground;
    mainMenuControl control;
    bool mainMenuInited = false;
    bool raiseMainBackground = true;
    bool showChoicePointer = false;
    bool startGame = false;
};


struct statesTime
{
    float dt;
    sf::Clock dtClock;
    sf::Clock effectClock;
};


struct gameStates
{
    std::vector<levelData> levels;
    levelInfo levelInfo;
    scoreInfo scoreInfo;
    gameOver gameOver;
    mainMenu mainMenu;
    world tanksWorld;
    statesTime time;
};