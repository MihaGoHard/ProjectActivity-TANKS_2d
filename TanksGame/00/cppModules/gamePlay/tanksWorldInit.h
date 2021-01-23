void initTanksWorld(world &tanksWorld)
{
    srand(time(0));
    tanksWorld.explosions = {};
    tanksWorld.barriers = {};
    tanksWorld.speedBarriers = {};
    tanksWorld.tanks = {};
    tanksWorld.shells = {};
    tanksWorld.bonusStruct.bonuses = {};

    tanksWorld.startPosition.firstAppearenceCount = 0;
    tanksWorld.startPosition.firstPos = false;
    tanksWorld.startPosition.secondPos = false;
    tanksWorld.startPosition.thirdPos = false;

    tanksWorld.time.mainClock.restart().asSeconds();
    tanksWorld.time.effectClock.restart().asSeconds();
    tanksWorld.bonusStruct.activeBonus = NO_BONUS;
    initScore(tanksWorld);
    initGameInfoField(tanksWorld);
    initBase(tanksWorld);
    initBattleField(tanksWorld);
    initMapBarriers(tanksWorld);
    initAllTanks(tanksWorld);
}