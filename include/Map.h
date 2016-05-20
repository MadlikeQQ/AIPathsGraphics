#ifndef MAP_H
#define MAP_H
#define MAXSIZE 90
#include<stdio.h>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace std;
class Map
{
public:
    Map(int lines, int cols, float tileMap[][MAXSIZE],sf::RenderWindow *window,float tileWidth, float tileHeight,sf::Vector2f windowOffset);
    virtual ~Map();


    void drawTile(sf::RenderWindow *window, sf::Vector2i pos)
    {
        /*Draw tile with the stored info in position i,j of tileMap*/
        sf::Sprite sprite;
        sprite.setTexture(textures[pos.x][pos.y]);
        sprite.setPosition(positions[pos.x][pos.y]);
        sprite.setScale(scales[pos.x][pos.y]);
        //sprite.setTexture(floor);
        //sprite.setPosition(pos);
        //sprite.setScale(tileWidth / floor.getSize().x, tileHeight / floor.getSize().y);
        window->draw(sprite);
    }
    void drawMap(sf::RenderWindow *window)
    {
    /*Draws the entire tileMap. Avoid calling this function where possible*/
    /*Call drawtile() instead for individual tile drawing*/
    /*after drawing the whole tileMap the first time*/
    int i,j;
        for(i = 0 ; i < lines ; i ++)
            for(j = 0 ; j < cols; j++)
                drawTile(window, sf::Vector2i(i,j));
    }
    void tileMapInit()
    {
        /*This function stores the textures and positions of the tileMap tiles*/
        int i,j;
        for(i = 0 ; i < lines ; i++)
        {
            textures[i] = new sf::Texture[MAXSIZE]; //make an new line of textures
            positions[i] = new sf::Vector2f[MAXSIZE];//make a new linew of positions for the tiles to be drawn
            scales[i] = new sf::Vector2f[MAXSIZE];//make a new line of scaling for the sprites to be drawn

            for(j = 0 ; j < cols; j++)
            {

                if((int)myMap[i][j] == 0)
                {
                    sf::Texture texture;

                    texture.loadFromFile("./Assets/Tiles/ground.png");
                    textures[i][j] = texture;
                    positions[i][j] = sf::Vector2f(j*tileWidth + windowOffset.x ,i*tileHeight + windowOffset.y);
                    scales[i][j] =  sf::Vector2f(tileWidth / texture.getSize().x, tileHeight / texture.getSize().y);

                }
                 else if ((int)myMap[i][j] == 1)
                {

                    sf::Texture texture;
                    texture.loadFromFile("./Assets/Tiles/BAD.png");
                     textures[i][j] = texture;
                    positions[i][j] = sf::Vector2f(j*tileWidth + windowOffset.x ,i*tileHeight + windowOffset.y);
                    scales[i][j] =  sf::Vector2f(tileWidth / texture.getSize().x, tileHeight / texture.getSize().y);

                }
               else  if((int)myMap[i][j] == 2)
                {
                    sf::Texture texture;

                    texture.loadFromFile("./Assets/Tiles/secondary.png");
                    textures[i][j] = texture;
                    positions[i][j] = sf::Vector2f(j*tileWidth + windowOffset.x ,i*tileHeight + windowOffset.y);
                    scales[i][j] =  sf::Vector2f(tileWidth / texture.getSize().x, tileHeight / texture.getSize().y);

                }
                else if((int)myMap[i][j] == 3)
                {
                    sf::Texture texture;

                    texture.loadFromFile("./Assets/Tiles/final.png");
                    textures[i][j] = texture;
                    positions[i][j] = sf::Vector2f(j*tileWidth + windowOffset.x ,i*tileHeight + windowOffset.y);
                    scales[i][j] =  sf::Vector2f(tileWidth / texture.getSize().x, tileHeight / texture.getSize().y);

                }

                }
            }
    }



protected:
private:
    //static const int MAX_SIZE = 10000;
    //const float myMap[MAXSIZE][MAXSIZE];


    float *(myMap[MAXSIZE]) ;/*The map as given in the input with the correct encoding*/
    int lines,cols; /*Lines and Columns of the map*/


    float tileWidth ; /*width and height for the height fo the tiles*/
    float tileHeight ; /*to be drawn*/


    sf::Vector2f windowOffset; /*A offset to put the tileMap in the center of the Render Window*/


    /*A table to store the textures for each tile*/
    sf::Texture floor;
    sf::Texture *(textures[MAXSIZE]);
    sf::Vector2f *(positions[MAXSIZE]);
    sf::Vector2f *(scales[MAXSIZE]);




    //vector<sf::Sprite> sprites;
    //sf::Texture texture,valid,invalid;



};

#endif // MAP_H
