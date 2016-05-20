#ifndef AGENT_H
#define AGENT_H
#include "Map.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <stdio.h>

class Agent
{
    public:
        /*Fields*/
        enum id_t {A,B};
        sf::Vector2f windowOffset;
        /*Tile width and height of the animation's rectangle*/
        float tileWidth;
        float tileHeight ;
        Agent(std::vector<sf::Vector2f> path, sf::Vector2f initPos, Agent::id_t id,float tileWidth,float tileHeight,sf::Vector2f windowOffset);


        /*Routines*/
        sf::Texture getFrame(sf::Vector2f movement)

        {
            /*Get the next animation frame for the Agent*/
            if(isMoving)
            {

                if(movement.x == 1)//Right animation
                {
                    frame_move = (frame_move + 1) % 8;
                    return animations_moveR[frame_move++];
                }

                else//Left animation.. Default to this if moving up or down
                {
                    frame_move = (frame_move + 1) % 8;
                    return animations_moveL[frame_move++];
                }
            }

            else
            {
                frame_idle = (frame_idle + 1) % 10;
                return animations_idle[frame_idle++];
            }

        }

        sf::Vector2i getIndex(sf::Vector2f position)
        {
            /*Gets the tile index of the agent's current position in the tileMap*/
            /*Used to selectively draw tiles around the agent while he's animating*/
            /*Thus we avoid drawing all the map during his movement*/
            int i,j;
            j = (int)((position.x - windowOffset.x)/(tileWidth));
            i = (int)((position.y +tileWidth/2 -windowOffset.y)/(tileHeight));
            return sf::Vector2i(i,j);
        }

        sf::Vector2f getNextInPath()//callsecond
        {
            /*Get next coordinate of the path*/
            if(!path.empty())
            {
            if(path.front() == sf::Vector2f(0,0)) {isMoving=false;printf("idle\n");}
            else isMoving=true;
            currentPos.x = currentPos.x + tileWidth * path.front().x;
            currentPos.y = currentPos.y + tileHeight * path.front().y;

            return currentPos;
            }
            else return currentPos;
        }

        sf::Vector2f getCurrentPos()//callfirst
        {
            /*Get the agent current Coordinates*/
            return currentPos;
        }
        sf::Vector2f getNextMove()//callthird
        {
            /*Get next move Left,Right,Up,Down*/
            sf::Vector2f temp;
            if(!path.empty())
            {
                if(path.front()==sf::Vector2f(0,0)) isMoving=false;
                else isMoving = true;
                temp = path.front();
                path.erase(path.begin());
                return temp;
            }
            else
            {
                isMoving = false;
                temp.x=temp.y=0;
                return temp;
            }

        }
    virtual ~Agent();
    protected:
    private:
    /*The id of the agent*/
    id_t id;
    /*Animations*/
    sf::Texture animations_moveR[8],animations_moveL[8], animations_idle[10];//cycle through these to create an animation feel
    int frame_move, frame_idle ; //current frame of the animation
    /*Agent logic . Is Moving or Not*/
    bool isMoving;

    /*Agent movement info*/
    std::vector<sf::Vector2f> path;//Sequence of moves L,R,U,D
    std::vector<sf::Vector2i> visited;//store visited positions
    sf::Vector2f currentPos;//Agent current Position given in pixel values,
                            //relative to the Render Window




};

#endif // AGENT_H
