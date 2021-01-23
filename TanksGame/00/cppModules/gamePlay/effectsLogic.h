void initExplosion(world &tanksWorld, float offsetX, float offsetY, int type)
{
    explosion explosion;
    explosion.box.setSize(sf::Vector2f{BIG_BARRIER_WIDTH, BIG_BARRIER_HEIGHT});
    explosion.box.setPosition(offsetX, offsetY);
    explosion.box.setTexture(&exploTexture);
    explosion.simple = true;
    switch (type)
    {
      case BIG_EXPLOSION:
        explosion.box.setTexture(&exploBiggerTexture);
        explosion.simple = false;
        break;
      case SIMPLE_EXPLOSION:
        explosion.box.setTexture(&exploTexture);
        explosion.simple = true;
        break;  
    }
        
    tanksWorld.explosions.push_back(explosion);
}