sf::Texture mainTankUpTexture;
sf::Texture mainTankDownTexture;
sf::Texture mainTankLeftTexture;
sf::Texture mainTankRightTexture;

sf::Texture mainTankUpArmorTexture;
sf::Texture mainTankDownArmorTexture;
sf::Texture mainTankLeftArmorTexture;
sf::Texture mainTankRightArmorTexture;


sf::Texture enemyTankUpTexture;
sf::Texture enemyTankDownTexture;
sf::Texture enemyTankLeftTexture;
sf::Texture enemyTankRightTexture;

sf::Texture enemyTankUpArmorTexture;
sf::Texture enemyTankDownArmorTexture;
sf::Texture enemyTankLeftArmorTexture;
sf::Texture enemyTankRightArmorTexture;


sf::Texture shellUpTexture;
sf::Texture shellDownTexture;
sf::Texture shellLeftTexture;
sf::Texture shellRightTexture;

sf::Texture brickTexture;
sf::Texture armorTexture;
sf::Texture forestTexture;
sf::Texture waterTexture;
sf::Texture sentTexture;
sf::Texture asphaltTexture;
sf::Texture birdTexture;

sf::Texture exploTexture;
sf::Texture exploBiggerTexture;
sf::Texture exploBiggestTexture;
sf::Texture exploHugerTexture;
sf::Texture exploHugestTexture;

sf::Texture emptyTexture;
sf::Texture pointerTexture;

sf::Texture stoneTexture;

sf::Texture mainMenuTexture;
sf::Texture gameOverTexture;

sf::Texture tankLabelTexture;
sf::Texture live1LabelTexture;
sf::Texture live2LabelTexture;
sf::Texture live3LabelTexture;
sf::Texture live4LabelTexture;


sf::Texture stage1Texture;
sf::Texture stage2Texture;
sf::Texture stage3Texture;
sf::Texture stage4Texture;
sf::Texture stage5Texture;
sf::Texture stage6Texture;
sf::Texture stage7Texture;
sf::Texture stage8Texture;
sf::Texture stage9Texture;
sf::Texture stage10Texture;

sf::Texture scoreTexture;

sf::Texture num0Texture;
sf::Texture num1Texture;
sf::Texture num2Texture;
sf::Texture num3Texture;
sf::Texture num4Texture;
sf::Texture num5Texture;
sf::Texture num6Texture;
sf::Texture num7Texture;
sf::Texture num8Texture;
sf::Texture num9Texture;


sf::Texture boomBonusTexture;
sf::Texture timeBonusTexture;
sf::Texture baseBonusTexture;
sf::Texture speedBonusTexture;



void initTextures()
{
    mainTankUpTexture.loadFromFile("./textures/mainTankUp.png");
    mainTankDownTexture.loadFromFile("./textures/mainTankDown.png");
    mainTankLeftTexture.loadFromFile("./textures/mainTankLeft.png");
    mainTankRightTexture.loadFromFile("./textures/mainTankRight.png");

    initSmoothTexture(mainTankUpTexture);
    initSmoothTexture(mainTankDownTexture);
    initSmoothTexture(mainTankLeftTexture);
    initSmoothTexture(mainTankRightTexture);


    mainTankUpArmorTexture.loadFromFile("./textures/mainTankUpArmor.png");
    mainTankDownArmorTexture.loadFromFile("./textures/mainTankDownArmor.png");
    mainTankLeftArmorTexture.loadFromFile("./textures/mainTankLeftArmor.png");
    mainTankRightArmorTexture.loadFromFile("./textures/mainTankRightArmor.png");

    initSmoothTexture(mainTankUpArmorTexture);
    initSmoothTexture(mainTankDownArmorTexture);
    initSmoothTexture(mainTankLeftArmorTexture);
    initSmoothTexture(mainTankRightArmorTexture);


    enemyTankUpArmorTexture.loadFromFile("./textures/enemyTankUpArmor.png");
    enemyTankDownArmorTexture.loadFromFile("./textures/enemyTankDownArmor.png");
    enemyTankLeftArmorTexture.loadFromFile("./textures/enemyTankLeftArmor.png");
    enemyTankRightArmorTexture.loadFromFile("./textures/enemyTankRightArmor.png");

    initSmoothTexture(enemyTankUpArmorTexture);
    initSmoothTexture(enemyTankDownArmorTexture);
    initSmoothTexture(enemyTankLeftArmorTexture);
    initSmoothTexture(enemyTankRightArmorTexture);


    enemyTankUpTexture.loadFromFile("./textures/enemyTankUp.png");
    enemyTankDownTexture.loadFromFile("./textures/enemyTankDown.png");
    enemyTankLeftTexture.loadFromFile("./textures/enemyTankLeft.png");
    enemyTankRightTexture.loadFromFile("./textures/enemyTankRight.png");

    initSmoothTexture(enemyTankUpTexture);
    initSmoothTexture(enemyTankDownTexture);
    initSmoothTexture(enemyTankLeftTexture);
    initSmoothTexture(enemyTankRightTexture);

    
    shellUpTexture.loadFromFile("./textures/shellUp.png");
    shellDownTexture.loadFromFile("./textures/shellDown.png");
    shellLeftTexture.loadFromFile("./textures/shellLeft.png");
    shellRightTexture.loadFromFile("./textures/shellRight.png");

    initSmoothTexture(shellUpTexture);
    initSmoothTexture(shellDownTexture);
    initSmoothTexture(shellLeftTexture);
    initSmoothTexture(shellRightTexture);

    brickTexture.loadFromFile("./textures/brick.png");
    initSmoothTexture(brickTexture);

    armorTexture.loadFromFile("./textures/armor.jpg");
    initSmoothTexture(armorTexture);

    forestTexture.loadFromFile("./textures/forest.png");
    initSmoothTexture(forestTexture);

    waterTexture.loadFromFile("./textures/water.png");
    initSmoothTexture(waterTexture);

    sentTexture.loadFromFile("./textures/sent.jpg");
    initSmoothTexture(sentTexture);

    asphaltTexture.loadFromFile("./textures/asphalt.jpg");
    initSmoothTexture(asphaltTexture);

    birdTexture.loadFromFile("./textures/bird.png");
    initSmoothTexture(birdTexture);

    exploTexture.loadFromFile("./textures/explo1.png");
    initSmoothTexture(exploTexture);

    exploBiggerTexture.loadFromFile("./textures/explo2.png");
    initSmoothTexture(exploBiggerTexture);

    exploBiggestTexture.loadFromFile("./textures/explo3.png");
    initSmoothTexture(exploBiggestTexture);

    exploHugerTexture.loadFromFile("./textures/explo4.png");
    initSmoothTexture(exploHugerTexture);

    exploHugestTexture.loadFromFile("./textures/explo5.png");
    initSmoothTexture(exploHugestTexture);

    emptyTexture.loadFromFile("./textures/empty.png");
    initSmoothTexture(emptyTexture);

    pointerTexture.loadFromFile("./textures/choicePointer.png");
    initSmoothTexture(pointerTexture);

    mainMenuTexture.loadFromFile("./textures/mainMenu.png");
    initSmoothTexture(mainMenuTexture);

    gameOverTexture.loadFromFile("./textures/gameOver.png");
    initSmoothTexture(gameOverTexture);

    stoneTexture.loadFromFile("./textures/stone.jpg");
    initSmoothTexture(stoneTexture);

    tankLabelTexture.loadFromFile("./textures/tankLabel.png");
    initSmoothTexture(tankLabelTexture);

    live1LabelTexture.loadFromFile("./textures/live1.png");
    initSmoothTexture(live1LabelTexture);

    live2LabelTexture.loadFromFile("./textures/live2.png");
    initSmoothTexture(live2LabelTexture);

    live3LabelTexture.loadFromFile("./textures/live3.png");
    initSmoothTexture(live3LabelTexture);

    live4LabelTexture.loadFromFile("./textures/live4.png");
    initSmoothTexture(live4LabelTexture);



    stage1Texture.loadFromFile("./textures/stage1.png");
    initSmoothTexture(stage1Texture);

    stage2Texture.loadFromFile("./textures/stage2.png");
    initSmoothTexture(stage2Texture);

    stage3Texture.loadFromFile("./textures/stage3.png");
    initSmoothTexture(stage3Texture);

    stage4Texture.loadFromFile("./textures/stage4.png");
    initSmoothTexture(stage4Texture);

    stage5Texture.loadFromFile("./textures/stage5.png");
    initSmoothTexture(stage5Texture);

    stage6Texture.loadFromFile("./textures/stage6.png");
    initSmoothTexture(stage6Texture);

    stage7Texture.loadFromFile("./textures/stage7.png");
    initSmoothTexture(stage7Texture);

    stage8Texture.loadFromFile("./textures/stage8.png");
    initSmoothTexture(stage8Texture);

    stage9Texture.loadFromFile("./textures/stage9.png");
    initSmoothTexture(stage9Texture);

    stage10Texture.loadFromFile("./textures/stage10.png");
    initSmoothTexture(stage10Texture);



    scoreTexture.loadFromFile("./textures/score.png");
    initSmoothTexture(scoreTexture);


    num0Texture.loadFromFile("./textures/num0.png");
    initSmoothTexture(num0Texture);

    num1Texture.loadFromFile("./textures/num1.png");
    initSmoothTexture(num1Texture);

    num2Texture.loadFromFile("./textures/num2.png");
    initSmoothTexture(num2Texture);

    num3Texture.loadFromFile("./textures/num3.png");
    initSmoothTexture(num3Texture);

    num4Texture.loadFromFile("./textures/num4.png");
    initSmoothTexture(num4Texture);

    num5Texture.loadFromFile("./textures/num5.png");
    initSmoothTexture(num5Texture);

    num6Texture.loadFromFile("./textures/num6.png");
    initSmoothTexture(num6Texture);

    num7Texture.loadFromFile("./textures/num7.png");
    initSmoothTexture(num7Texture);

    num8Texture.loadFromFile("./textures/num8.png");
    initSmoothTexture(num8Texture);

    num9Texture.loadFromFile("./textures/num9.png");
    initSmoothTexture(num9Texture);



    boomBonusTexture.loadFromFile("./textures/boom.jpg");
    initSmoothTexture(boomBonusTexture);

    timeBonusTexture.loadFromFile("./textures/time.jpg");
    initSmoothTexture(timeBonusTexture);

    baseBonusTexture.loadFromFile("./textures/base.jpg");
    initSmoothTexture(baseBonusTexture);

    speedBonusTexture.loadFromFile("./textures/speed.jpg");
    initSmoothTexture(speedBonusTexture);
}