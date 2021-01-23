struct gameInfoField
{
    sf::RectangleShape box;
    sf::RectangleShape livesLabel;
    std::vector<sf::RectangleShape> tankLabels;
};


struct barrierStruct
{
    sf::RectangleShape box;
    int type;
    bool isPunched = false;
    bool contactWithShell = false;
};


struct explosion
{
    sf::RectangleShape box;
    bool simple = false;
};


struct moveSolutionStruct
{
    bool canMoveUp = false;
    bool canMoveDown = false;
    bool canMoveLeft = false;
    bool canMoveRight = false;
};


struct tank
{
    int id;
    int shellId;
    int direction = UP;
    sf::RectangleShape box;
    moveSolutionStruct moveSolution;
    float speed;
    int shootFreaquency;
    bool firstAppiarence = true;
    bool eraseTank = false;
    bool shoot = false;
    int state = SIMPLE;
};


struct shell
{
    int id;
    float speed;
    sf::RectangleShape box;
    int direction;
    int destroyedAimType;
    bool isEnemyShell = false;
    bool eraseShell = false;
    bool enemyUnion = false;
};


struct startEnemyPosition
{
    int firstAppearenceCount = 0;
    bool firstPos = false;
    bool secondPos = false;
    bool thirdPos = false;
};


struct score
{
    int enemyDestroyed;
    int playerDestroyed;
};



struct levelData
{
    std::vector<std::vector<int>> map;
    int levelNumber;
    int minEnemyNumOnField;
    int maxEnemyNumOnField;
    int enemyNumDestroyToWin;
    int playerNumDestroyToLoss;
    float tanksSpeed;
    float shellSpeed;
    float bonusSpeed;
    int shootFreaquency;
};


struct bonus
{
    int type;
    sf::RectangleShape box;
    int resetTime;
    bool eraseBonus = false;
};


struct bonuses
{
    int activeBonus = NO_BONUS;
    int tankId = UNSET_ID;
    bool enemyBonus = false;
    std::vector<bonus> bonuses;
};


struct worldTime
{
    sf::Clock mainClock;
    sf::Clock bonusClock;
    sf::Clock effectClock;
    sf::Clock explorClock;
    float dt;
    bool restartClock = false;
};


struct control
{
    int moveCommand = STOP;
    bool shootCommand = false;
};


struct world
{
    control control;
    worldTime time;
    startEnemyPosition startPosition;
    sf::RectangleShape battleField;
    gameInfoField infoField;
    bonuses bonusStruct;
    std::vector<explosion> explosions;
    std::vector<barrierStruct> barriers;
    std::vector<barrierStruct> speedBarriers;
    std::vector<tank> tanks;
    std::vector<shell> shells;
    bool enemyIsDestroyed = false;
    bool playerIsDestroyed = false;
    score score;
    int worldStatus = GAMEPLAY;
    levelData level;
};

