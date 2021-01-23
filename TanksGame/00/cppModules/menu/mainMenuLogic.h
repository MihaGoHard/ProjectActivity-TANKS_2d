void initMainBackground(mainMenu &mainMenu)
{
    sf::RectangleShape &mainBackground = mainMenu.mainBackground;
    mainBackground.setSize(sf::Vector2f{MENU_WIDTH, MENU_HEIGHT});
    mainBackground.setPosition(MENU_OFFSET_X, WINDOW_HEIGHT);
    mainBackground.setTexture(&mainMenuTexture);
}


void initChoicePointer(mainMenu &mainMenu)
{
    choicePointer &pointer = mainMenu.choicePointer;
    pointer.box.setTexture(&emptyTexture);
    pointer.box.setSize(sf::Vector2f{TANK_WIDTH, TANK_HEIGHT});
    pointer.box.setPosition(POINTER_START_POS_X, POINTER_START_POS_Y);
}


void initMainMenu(mainMenu &mainMenu)
{
    initMainBackground(mainMenu);
    initChoicePointer(mainMenu);
}


void raiseMainBackground(mainMenu &mainMenu)
{
    sf::RectangleShape &background = mainMenu.mainBackground;
    
    sf::Vector2f backgroundPosition = background.getPosition();

    if (backgroundPosition.y >= MENU_OFFSET_Y)
        background.setPosition(MENU_OFFSET_X, backgroundPosition.y - RAISE_SPEED * mainMenu.dt);
    else
        mainMenu.showChoicePointer = true;
}


void updateMenuElemsSetSolutions(mainMenu &mainMenu)
{
    if (mainMenu.raiseMainBackground)
        raiseMainBackground(mainMenu);

    if (mainMenu.showChoicePointer)
        mainMenu.choicePointer.box.setTexture(&pointerTexture);  
        
    if (mainMenu.control.up && mainMenu.choicePointer.box.getPosition().y >= POINTER_START_POS_Y + TANK_HEIGHT)
    {
        mainMenu.choicePointer.box.setPosition(POINTER_START_POS_X, POINTER_START_POS_Y);
        mainMenu.choicePointer.startPos = true;
    }    

    if (mainMenu.control.down && mainMenu.choicePointer.box.getPosition().y <= POINTER_START_POS_Y)
    {
        mainMenu.choicePointer.box.setPosition(POINTER_START_POS_X, POINTER_START_POS_Y + VERTICAL_CHOICE_OFFSET);    
        mainMenu.choicePointer.startPos = false;
    }    

    if (mainMenu.choicePointer.startPos && mainMenu.control.enter && mainMenu.showChoicePointer)
    {
        mainMenu.startGame = true;     
        mainMenu.choicePointer.box.setTexture(&emptyTexture);
        mainMenu.raiseMainBackground = true;
        mainMenu.mainMenuInited = false;
        mainMenu.showChoicePointer = false;
    }   
}

