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

    mainTankUpTexture.setSmooth(true);
    mainTankDownTexture.setSmooth(true);
    mainTankLeftTexture.setSmooth(true);
    mainTankRightTexture.setSmooth(true);


    mainTankUpArmorTexture.loadFromFile("./textures/mainTankUpArmor.png");
    mainTankDownArmorTexture.loadFromFile("./textures/mainTankDownArmor.png");
    mainTankLeftArmorTexture.loadFromFile("./textures/mainTankLeftArmor.png");
    mainTankRightArmorTexture.loadFromFile("./textures/mainTankRightArmor.png");

    mainTankUpArmorTexture.setSmooth(true);
    mainTankDownArmorTexture.setSmooth(true);
    mainTankLeftArmorTexture.setSmooth(true);
    mainTankRightArmorTexture.setSmooth(true);


    enemyTankUpArmorTexture.loadFromFile("./textures/enemyTankUpArmor.png");
    enemyTankDownArmorTexture.loadFromFile("./textures/enemyTankDownArmor.png");
    enemyTankLeftArmorTexture.loadFromFile("./textures/enemyTankLeftArmor.png");
    enemyTankRightArmorTexture.loadFromFile("./textures/enemyTankRightArmor.png");

    enemyTankUpArmorTexture.setSmooth(true);
    enemyTankDownArmorTexture.setSmooth(true);
    enemyTankLeftArmorTexture.setSmooth(true);
    enemyTankRightArmorTexture.setSmooth(true);


    enemyTankUpTexture.loadFromFile("./textures/enemyTankUp.png");
    enemyTankDownTexture.loadFromFile("./textures/enemyTankDown.png");
    enemyTankLeftTexture.loadFromFile("./textures/enemyTankLeft.png");
    enemyTankRightTexture.loadFromFile("./textures/enemyTankRight.png");

    enemyTankUpTexture.setSmooth(true);
    enemyTankDownTexture.setSmooth(true);
    enemyTankLeftTexture.setSmooth(true);
    enemyTankRightTexture.setSmooth(true);

    
    shellUpTexture.loadFromFile("./textures/shellUp.png");
    shellDownTexture.loadFromFile("./textures/shellDown.png");
    shellLeftTexture.loadFromFile("./textures/shellLeft.png");
    shellRightTexture.loadFromFile("./textures/shellRight.png");

    shellUpTexture.setSmooth(true);
    shellDownTexture.setSmooth(true);
    shellLeftTexture.setSmooth(true);
    shellRightTexture.setSmooth(true);

    brickTexture.loadFromFile("./textures/brick.png");
    brickTexture.setSmooth(true);

    armorTexture.loadFromFile("./textures/armor.jpg");
    armorTexture.setSmooth(true);

    forestTexture.loadFromFile("./textures/forest.png");
    forestTexture.setSmooth(true);

    waterTexture.loadFromFile("./textures/water.png");
    waterTexture.setSmooth(true);

    sentTexture.loadFromFile("./textures/sent.jpg");
    sentTexture.setSmooth(true);

    asphaltTexture.loadFromFile("./textures/asphalt.jpg");
    asphaltTexture.setSmooth(true);

    birdTexture.loadFromFile("./textures/bird.png");
    birdTexture.setSmooth(true);

    exploTexture.loadFromFile("./textures/explo1.png");
    exploTexture.setSmooth(true);

    exploBiggerTexture.loadFromFile("./textures/explo2.png");
    exploBiggerTexture.setSmooth(true);

    exploBiggestTexture.loadFromFile("./textures/explo3.png");
    exploBiggestTexture.setSmooth(true);

    exploHugerTexture.loadFromFile("./textures/explo4.png");
    exploHugerTexture.setSmooth(true);

    exploHugestTexture.loadFromFile("./textures/explo5.png");
    exploHugestTexture.setSmooth(true);

    emptyTexture.loadFromFile("./textures/empty.png");
    emptyTexture.setSmooth(true);

    pointerTexture.loadFromFile("./textures/choicePointer.png");
    pointerTexture.setSmooth(true);

    mainMenuTexture.loadFromFile("./textures/mainMenu.png");
    mainMenuTexture.setSmooth(true);

    gameOverTexture.loadFromFile("./textures/gameOver.png");
    gameOverTexture.setSmooth(true);

    stoneTexture.loadFromFile("./textures/stone.jpg");
    stoneTexture.setSmooth(true);

    tankLabelTexture.loadFromFile("./textures/tankLabel.png");
    tankLabelTexture.setSmooth(true);

    live1LabelTexture.loadFromFile("./textures/live1.png");
    live1LabelTexture.setSmooth(true);

    live2LabelTexture.loadFromFile("./textures/live2.png");
    live2LabelTexture.setSmooth(true);

    live3LabelTexture.loadFromFile("./textures/live3.png");
    live3LabelTexture.setSmooth(true);

    live4LabelTexture.loadFromFile("./textures/live4.png");
    live4LabelTexture.setSmooth(true);



    stage1Texture.loadFromFile("./textures/stage1.png");
    stage1Texture.setSmooth(true);

    stage2Texture.loadFromFile("./textures/stage2.png");
    stage2Texture.setSmooth(true);

    stage3Texture.loadFromFile("./textures/stage3.png");
    stage3Texture.setSmooth(true);

    stage4Texture.loadFromFile("./textures/stage4.png");
    stage4Texture.setSmooth(true);

    stage5Texture.loadFromFile("./textures/stage5.png");
    stage5Texture.setSmooth(true);

    stage6Texture.loadFromFile("./textures/stage6.png");
    stage6Texture.setSmooth(true);

    stage7Texture.loadFromFile("./textures/stage7.png");
    stage7Texture.setSmooth(true);

    stage8Texture.loadFromFile("./textures/stage8.png");
    stage8Texture.setSmooth(true);

    stage9Texture.loadFromFile("./textures/stage9.png");
    stage9Texture.setSmooth(true);

    stage10Texture.loadFromFile("./textures/stage10.png");
    stage10Texture.setSmooth(true);



    scoreTexture.loadFromFile("./textures/score.png");
    scoreTexture.setSmooth(true);


    num0Texture.loadFromFile("./textures/num0.png");
    num0Texture.setSmooth(true);

    num1Texture.loadFromFile("./textures/num1.png");
    num1Texture.setSmooth(true);

    num2Texture.loadFromFile("./textures/num2.png");
    num2Texture.setSmooth(true);

    num3Texture.loadFromFile("./textures/num3.png");
    num3Texture.setSmooth(true);

    num4Texture.loadFromFile("./textures/num4.png");
    num4Texture.setSmooth(true);

    num5Texture.loadFromFile("./textures/num5.png");
    num5Texture.setSmooth(true);

    num6Texture.loadFromFile("./textures/num6.png");
    num6Texture.setSmooth(true);

    num7Texture.loadFromFile("./textures/num7.png");
    num7Texture.setSmooth(true);

    num8Texture.loadFromFile("./textures/num8.png");
    num8Texture.setSmooth(true);

    num9Texture.loadFromFile("./textures/num9.png");
    num9Texture.setSmooth(true);



    boomBonusTexture.loadFromFile("./textures/boom.jpg");
    boomBonusTexture.setSmooth(true);

    timeBonusTexture.loadFromFile("./textures/time.jpg");
    timeBonusTexture.setSmooth(true);

    baseBonusTexture.loadFromFile("./textures/base.jpg");
    baseBonusTexture.setSmooth(true);

    speedBonusTexture.loadFromFile("./textures/speed.jpg");
    speedBonusTexture.setSmooth(true);
}