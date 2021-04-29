#include "Game.h"
#include <stdio.h>
#include <assert.h>
#include "../SFML/StateSplashScreenSFML.h"
#include "../txt/StateSplashScreenTxt.h"

#include <iostream>

Game::Game(/* args */)
{
    context = std::make_shared<Context>();

    // Initialisation des ennemies
    int count = context->map->GetSpawnsLayer()->getEnemySpawns().size();
    
    for(int i = 0; i<count; i++){
        int x = context->map->GetSpawnsLayer()->getEnemySpawns()[i].GetX();
        int y = context->map->GetSpawnsLayer()->getEnemySpawns()[i].GetY();

        std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>(x, y, "Enemy", 100, 3, 1, 100);
        context->enemies.push_back(enemy);
        
        context->map->GetCollisionLayer()->AddCollisionBoxEntity(
            enemy->GetID(), new CollisionBox(x, y, 26, 26));
    }

    context->isDebug = false;
}


Game::~Game()
{
}

void Game::Run(int mode) 
{
    assert(mode==0 || mode == 1);
    switch (mode)
    {
    case 0: //mode SFML
    {
        int winWidth = 700;
        int winHeight = 700;
        context->renderWin->create(sf::VideoMode(winWidth, winHeight, 32), "Legend Of Nautibus");
        context->stateMan->Add(std::make_unique<StateSplashScreenSFML>(context));
        while (!context->quit)
        {
            context->stateMan->ProcessStateChange();
            context->stateMan->GetCurrent()->ProcessInput();
            context->stateMan->GetCurrent()->Update();
            context->stateMan->GetCurrent()->Display();
        }
    break;
    }
    
    case 1: //mode txt
        context->stateMan->Add(std::make_unique<StateSplashScreenTxt>(context));
        while (!context->quit)
        {
            context->stateMan->ProcessStateChange();
            context->stateMan->GetCurrent()->ProcessInput();
            context->stateMan->GetCurrent()->Update();
            context->stateMan->GetCurrent()->Display();
        }
    break;

    default:
    break;

    }
}


void Game::Test() 
{   
    
}