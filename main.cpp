#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "./include/Map.h"
#include "./include/Agent.h"
#include "./include/GameState.h"
//#include <stdio.h>
//#include <stdlib.h>

//#include <fstream>
//#include <sstream>
//#include <string>
#define MAXSIZE 90

float tileWidth = 70;
float tileHeight = 70;
float myMap[MAXSIZE][MAXSIZE];
sf::Vector2f windowOffset;

void update(sf::RenderWindow *window, Agent *A, Agent *B, Map *tileMap);

    int main(int argc, char *argv[])
    {

    if(argc < 2) {printf("Usage : %s [datafile]\n",argv[0]); exit(1);}


    int lines = 0,cols = 0;

    sf::VideoMode v ;



    sf::RenderWindow window(v.getDesktopMode(), "AI Paths");

    sf::Texture texture;
    sf::Sprite sprite;
    sf::CircleShape shape(100.f);

    //read data of input to pathfinder

    //printf("Reading Data file...\n");
    FILE *f;

    if((f = fopen(argv[1],"r"))==NULL) exit(1);
    fscanf(f,"%d %d",&lines,&cols);

    float maxsize = (window.getSize().x / cols < window.getSize().y /lines) ? window.getSize().x / cols : window.getSize().y /lines;
    tileWidth = tileHeight = maxsize;

    //printf("tileW = %f , tileH = %f\n",tileWidth,tileHeight);






    int i,j;
    sf::Vector2f posA,posB;

     windowOffset.x = window.getSize().x / 2 - ((float)cols * tileWidth)/2;
     windowOffset.y = window.getSize().y / 2 - ((float)lines * tileHeight)/2;



    for(i = 0 ; i < lines; i++)
    {

        for(j = 0 ; j < cols; j++)
        {

            fscanf(f,"%1f",&myMap[i][j]);
            //printf("%f ",myMap[i][j]);
            /*Agent A's code found*/if(myMap[i][j] == 4) {posA.x = j*tileWidth + windowOffset.x
             ; posA.y = i*tileHeight + windowOffset.y /*- tileHeight /2*/;myMap[i][j]=0;}
            /*Agent B's code found*/if(myMap[i][j] == 5) {posB.x = j*tileWidth + windowOffset.x  ;
             posB.y = i*tileHeight + windowOffset.y /*- tileHeight /2*/  ;myMap[i][j] =0;}
        }
    }


    //read paths

    int countA, countB;
    float x,y;



    fscanf(f,"%d",&countA);
    std::vector<sf::Vector2f> pathA (countA);
    //read path A
    for(i = 0 ; i < countA; i++)
        {
            fscanf(f,"%f %f",&x,&y);

            //pathA.push_back(*(new sf::Vector2f(x,y)));
            pathA[i] = sf::Vector2f(x,y);
            //printf("%f %f \n",x,y);
        }
    fscanf(f,"%d",&countB);
     std::vector<sf::Vector2f> pathB (countB);

     for(i = 0 ; i < countB; i++)
       {
            fscanf(f,"%f %f",&x,&y);

            //pathB.push_back(*(new sf::Vector2f(x,y)));
            pathB[i] = sf::Vector2f(x,y);
            //printf("%f %f \n",x,y);
       }
    //read path B



    //printf("Loading Game Assets...\n");
    Map *tileMap = new Map(lines, cols, myMap, &window,tileWidth,tileHeight,windowOffset);
    Agent *A = new Agent(pathA,posA,Agent::A,tileWidth,tileHeight,windowOffset);
    Agent *B = new Agent(pathB,posB,Agent::B,tileWidth,tileHeight,windowOffset);
    GameState *gameState = new GameState(&window, A,B,tileMap);

    //printf("Inital position of Agent A: (%d,%d)\n",A->getIndex(posA).x,A->getIndex(posA).y);
    //printf("Inital position of Agent B: (%d,%d)\n",B->getIndex(posB).x,B->getIndex(posB).y);





    sf::Clock clock;

   //printf("Initializing Game...\n");
   window.clear(sf::Color::Transparent);
   tileMap->drawMap(&window);//draw the whole map once . May take time depending on size
   window.display();
    //printf("Game Started...\n");
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
                gameState->eventHandler(event);

        }


        gameState->update();
        //update(&window, A, B, tileMap);



    }

    return 0;
}
