#include "GameState.h"
#include "Map.h"
#include "Agent.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
GameState::GameState(sf::RenderWindow *window, Agent *A, Agent *B, Map *tileMap)
{
    this->window = window;
    this->A = A;
    this->B = B;
    this->tileMap = tileMap;
    this->tileHeight = A->tileHeight;
    this->tileWidth = A->tileWidth;
    this->updateRate = 50;
    this->state = playing;
}

GameState::~GameState()
{
    //dtor
}
