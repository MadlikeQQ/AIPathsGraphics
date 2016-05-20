#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "Map.h"
#include "Agent.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class GameState
{
    public:
        enum state_t {playing,paused};//the state of the game.
        state_t state;
        int32_t updateRate;//the update rate of the game
        GameState(sf::RenderWindow *window, Agent *A, Agent *B, Map *tileMap);


void update()
{
    if(state == playing)
    {
    sf::Sprite sprite;
    sf::Vector2f s1,s2,f1,f2,m1,m2,t1,t2;
    sf::Vector2i i1start,i1end, i2start,i2end;
    sf::Clock clock;
    sf::Texture texture;

    float step=4,step_c = 0;//position step and counter for each movement.
                            //Set to tileWidth or tileHeight for rectangular, non smooth, movement
    //tileWidth / step;
    s1 = A->getCurrentPos();//get current coordinates of agents
    s2 = B->getCurrentPos();

    f1 = A->getNextInPath();//get target coordinates
    f2 = B->getNextInPath();

    m1 = A->getNextMove();//get current move to be drawn(L,R,U,D)
    m2 = B->getNextMove();

    /*Define the start tiles and end tiles of the agents*/
    /*Only these will be updated in each iteration of the agent movements*/
    /*Avoiding re-drawing of the whole map*/
    i1start = A->getIndex(s1);
    i2start = B->getIndex(s2);
    i1end = A->getIndex(f1);
    i2end = B->getIndex(f2);




    //printf("Move of A (%f,%f), MOve of B (%f,%f)\n",m1.x,m1.y,m2.x,m2.y);
    t1=s1;t2=s2;
    while(step_c < tileWidth)
    {


        tileMap->drawTile(window,i1start);
        tileMap->drawTile(window,i2start);
        tileMap->drawTile(window,i1end);
        tileMap->drawTile(window,i2end);






        t1+=m1*step;
        //texture = A->texture;
        texture = A->getFrame(m1);
        sprite.setTexture(texture);
        sprite.setPosition(t1);
        sprite.setScale(tileWidth / texture.getSize().x, tileHeight / texture.getSize().y);
        window->draw(sprite);




        t2+=m2*step;


        texture = B->getFrame(m2);
        sprite.setTexture(texture);
        sprite.setScale(tileWidth / texture.getSize().x, tileHeight / texture.getSize().y);
        sprite.setPosition(t2);
        window->draw(sprite);


        window->display();
        /*wait some time before the next frame*/
        clock.restart();
        while(clock.getElapsedTime().asMilliseconds() < updateRate);

        step_c += step;
    }
}

}
void eventHandler(sf::Event event)
{

    {
        if(event.key.code == sf::Keyboard::Space)
        /*Pressing Space toggles the game state*/
            {
                if(state == paused)
                {
                    state = playing;
                }
                else
                {
                    state = paused;
                }
            }
            /*Pressing Up or Down arrows changes the update rate*/
            if(event.key.code == sf::Keyboard::Up)
            {
                updateRate -= 25;
                if(updateRate < 0 ) updateRate = 0;
            }
            if(event.key.code == sf::Keyboard::Down)
            {
                updateRate += 25;

            }

    }
}
        virtual ~GameState();
    protected:
    private:
    Map *tileMap;
    Agent *A,*B;
    sf::RenderWindow *window;
    float tileWidth, tileHeight;
};

#endif // GAMESTATE_H
