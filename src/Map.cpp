#include "Map.h"
#define MAXSIZE 90

Map::Map(int lines, int cols, float tileMap[][MAXSIZE],sf::RenderWindow *window ,float tileWidth, float tileHeight, sf::Vector2f windowOffset)
{
    //ctor
    this->lines = lines;
    this->cols = cols;
    //windowOffset.x = window->getSize().x / 2 - (cols * tileWidth)/2;
    //windowOffset.y = window->getSize().y / 2 - (lines * tileHeight)/2;
    this->windowOffset = windowOffset;
    this->tileWidth = tileWidth;
    this->tileHeight = tileHeight;

    floor.loadFromFile("./Assets/Tiles/ground.png");

    int i;
    for(i = 0 ; i < lines ; i++)
    {
        myMap[i] = new float[MAXSIZE];
        myMap[i] = tileMap[i];
    }

    tileMapInit();

}

Map::~Map()
{
    //dtor
}
