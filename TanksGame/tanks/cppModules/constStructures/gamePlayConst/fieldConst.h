const float FIELD_OFFSET_X = 60;
const float FIELD_OFFSET_Y = 40;

const float FIELD_WIDTH = 1200;
const float FIELD_HEIGHT = 800;


const int TANK_ATTAC_LIMIT_Y = 740;
const int TANK_ATTAC_LEFT_LIMIT_X = 500;
const int TANK_ATTAC_RIGHT_LIMIT_X = 800;


const float MAP_WIDTH = FIELD_WIDTH / 50;
const float MAP_HEIGHT = FIELD_HEIGHT / 50;


const sf::Vector2f START_PLAYER_POS = {400 + FIELD_OFFSET_X, 740 + FIELD_OFFSET_Y};
const sf::Vector2f FIRST_ENEMY_POS = {0 + FIELD_OFFSET_X, 0 + FIELD_OFFSET_Y};
const sf::Vector2f SECOND_ENEMY_POS = {550 + FIELD_OFFSET_X, 0 + FIELD_OFFSET_Y};
const sf::Vector2f THIRD_ENEMY_POS = {1150 + FIELD_OFFSET_X, 0 + FIELD_OFFSET_Y};


const float LEFT_FIELD_BORDER = FIELD_OFFSET_X;
const float RIGHT_FIELD_BORDER = FIELD_WIDTH + FIELD_OFFSET_X;
const float TOP_FIELD_BORDER = FIELD_OFFSET_Y;
const float BOTTOM_FIELD_BORDER = FIELD_HEIGHT + FIELD_OFFSET_Y;


const int EMPTY_PLACE = 0;
const int BASE = 99;
const int BRICK_WALL = 1; 
const int ARMOR_WALL = 2;
const int FOREST_BLOCK = 3;
const int WATER_BLOCK = 4;
const int SAND_BLOCK = 5;
const int ASPHALT_BLOCK = 6;