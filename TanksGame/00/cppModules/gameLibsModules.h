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


#include "./textures.h"
#include "./supportFunctions.h"
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

#include "./gamePlay/levels.h"

#include "./gamePlay/gameBox.h"
#include "./gamePlay/effectsLogic.h"
#include "./gamePlay/bonus.h"
#include "./gamePlay/tankCollisionsMoveSolutions.h"
#include "./gamePlay/shellLogic.h"
#include "./gamePlay/tanksLogic.h"

#include "./gamePlay/barriersLogic.h"
#include "./gamePlay/score.h"
#include "./gamePlay/tanksWorldInit.h"
#include "./gamePlay/draw.h"

#include "./menu/mainMenuLogic.h"
#include "./menu/mainMenuEventsSolutions.h"
#include "./menu/gameOverLogic.h"
#include "./menu/levelScoreInfo.h"

#include "./menu/draw.h"
#include "./gameProcess.h"
#include "./gameControl.h"
#include "./gameInit.h"