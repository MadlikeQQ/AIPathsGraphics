#include "Agent.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;
Agent::Agent(std::vector<sf::Vector2f> path, sf::Vector2f initPos, Agent::id_t id,float tileWidth,float tileHeight, sf::Vector2f windowOffset)
{


if(id == A )
{
    /*Path Info*/
    this->path=path;
    //this->visited.push_back()
    this->currentPos = initPos;
    /*Draw Info*/
    this->windowOffset = windowOffset;
    this->frame_idle=0;
    this->frame_move=0;
    this->id = id;
    this->tileHeight = tileHeight ;
    this->tileWidth = tileWidth ;
    /*State info*/
    this->isMoving = false;

    sf::Texture texture ;
    texture.loadFromFile("./Assets/Agents/run_animation_right_A.png");
    /*Width of each frame , and their height*/
    unsigned int base_width = texture.getSize().x / 8 ;
    unsigned int base_height = texture.getSize().y;
    /*Load animation textures into arrays*/
    sf::Image im = texture.copyToImage();
    int i;
    for(i = 0 ; i < 8; i++)
    {
        animations_moveR[i].loadFromImage(im,sf::IntRect(i*base_width,0,base_width,base_height));
    }

    texture.loadFromFile("./Assets/Agents/run_animation_left_A.png");
    im =texture.copyToImage();
    for(i = 0 ; i < 8; i++)
    {
        animations_moveL[i].loadFromImage(im,sf::IntRect(i*base_width,0,base_width,base_height));
    }



    texture.loadFromFile("./Assets/Agents/idle_animation_A.png");
    im = texture.copyToImage();
    for(i = 0 ; i < 10; i++)
    {
        animations_idle[i].loadFromImage(im,sf::IntRect(i*base_width,0,base_width,base_height));

    }
    }
    else if(id == B)
    {
    this->path=path;
    this->currentPos = initPos;
    this->windowOffset = windowOffset;
    this->frame_idle=0;
    this->frame_move=0;
    this->id = id;
    this->tileHeight = tileHeight;
    this->tileWidth = tileWidth;
    this->isMoving = false;

    sf::Texture texture ;
    texture.loadFromFile("./Assets/Agents/run_animation_right_B.png");
    unsigned int base_width = texture.getSize().x / 8 ;
    unsigned int base_height = texture.getSize().y;

    sf::Image im = texture.copyToImage();
    int i;
    for(i = 0 ; i < 8; i++)
    {
        animations_moveR[i].loadFromImage(im,sf::IntRect(i*base_width,0,base_width,base_height));
    }

    texture.loadFromFile("./Assets/Agents/run_animation_left_B.png");
    im =texture.copyToImage();
    for(i = 0 ; i < 8; i++)
    {
        animations_moveL[i].loadFromImage(im,sf::IntRect(i*base_width,0,base_width,base_height));
    }



    texture.loadFromFile("./Assets/Agents/idle_animation_B.png");
    im = texture.copyToImage();
    for(i = 0 ; i < 10; i++)
    {
        animations_idle[i].loadFromImage(im,sf::IntRect(i*base_width,0,base_width,base_height));

    }
    }
    else {printf("Agent: Invalid id \n");exit(1);}



}
//fields

Agent::~Agent()
{
    //dtor
}
