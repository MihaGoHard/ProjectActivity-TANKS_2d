#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <conio.h>
#include <ctime>
#include <random>
#include <vector>
#include <string>
#include <list>

#include "./constStructures/commonConstStruct.h"
#include "./constStructures/gamePlayConst/barrierConst.h"
#include "./constStructures/gamePlayConst/bonusConst.h"
#include "./constStructures/gamePlayConst/fieldConst.h"
#include "./constStructures/gamePlayConst/infoFieldConst.h"
#include "./constStructures/gamePlayConst/diffConst.h"
#include "./constStructures/gamePlayConst/tankShellConst.h"
#include "./constStructures/gamePlayStruct.h"
#include "./constStructures/menuConst.h"
#include "./constStructures/menuStruct.h"

#include "./supportFunctions.h"
#include "./textures/texturesGlobal.h"
#include "./textures/texturesInit.h"

#include "./gamePlay/levels.h"

#include "./gamePlay/gameBox.h"
#include "./gamePlay/effectsLogic.h"
#include "./gamePlay/bonus.h"
#include "./gamePlay/shellLogic.h"

#include "./gamePlay/tanks/enemyTankUpdateSupport.h"
#include "./gamePlay/tanks/playerTankUpdateSupport.h"
#include "./gamePlay/tanks/directionUpdateSupport.h"
#include "./gamePlay/tanks/barriersCollisionSupport.h"
#include "./gamePlay/tanks/tanksLogic.h"
#include "./gamePlay/tanks/tankCollisionsMoveSolutions.h"
#include "./gamePlay/tanks/tanksInit.h"



#include "./gamePlay/barriersLogic.h"
#include "./gamePlay/score.h"
#include "./gamePlay/tanksWorldInit.h"
#include "./gamePlay/draw.h"

#include "./menu/mainMenuLogic.h"
#include "./menu/gameOverLogic.h"
#include "./menu/levelInfoLogic.h"
#include "./menu/scoreInfoLogic.h"

#include "./menu/draw.h"
#include "./gameProcess.h"
#include "./gameUpdate.h"
#include "./gameControl.h"
#include "./gameInit.h"