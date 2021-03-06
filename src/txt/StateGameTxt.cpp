#include "StateGameTxt.h"

StateGameTxt::StateGameTxt(/* args */)
{
}

StateGameTxt::StateGameTxt(std::shared_ptr<Context> &cContext)
    : context(cContext)
{
}

StateGameTxt::~StateGameTxt()
{
}

void StateGameTxt::Init()
{
    context->player->SetSpeed(1);

    system("setterm -cursor off");
}

void StateGameTxt::ProcessInput()
{
}

void StateGameTxt::Update()
{
    int c;
    CollisionLayer * colLayer = context->map->GetCollisionLayer();
    c = win->getCh();
    switch (c)
    {
    case 'z':
        context->player->MoveWithCollision(0, -1, colLayer, 1);
        context->player->SetDirection(Up);
        break;

    case 'q':
        context->player->MoveWithCollision(-1, 0, colLayer, 1);
        context->player->SetDirection(Left);
        break;

    case 's':
        context->player->MoveWithCollision(0, 1, colLayer, 1);
        context->player->SetDirection(Down);
        break;

    case 'd':
        context->player->MoveWithCollision(1, 0, colLayer, 1);
        context->player->SetDirection(Right);
        break;

    case 'x':
        system("clear");
        system("setterm -cursor on");
        context->quit = true;
        break;

    default:
        break;
    }

    float playerX = context->player->GetPos_x();
    float playerY = context->player->GetPos_y();
    int playerID = context->player->GetID();
    

    Box * cbPlayer = 
        context->map->GetCollisionLayer()->GetCollisionBoxesEntity()[playerID];
    cbPlayer->SetPosition(playerX, playerY);
}

void StateGameTxt::Display()
{
    win = std::make_unique<WinTXT>(50, 25);
    win->clear();

    //Affichage du joueur
    int pX = win->getDimx() / 2; //center of the screen on x
    int pY = win->getDimy() / 2; //center of the screen on y
    win->print(pX, pY, 'O');

    //Affichage des données du joueurs
    std::cout << std::endl
              << " Informations : "
              << std::endl
              << "Position : (" << context->player->GetPos_x() << ", "
              << context->player->GetPos_y() << ")" << std::endl
              << "HP : " << context->player->GetHP() << "/"
              << context->player->GetMaxHP() << std::endl;

    //Affichage des ennemies
    const std::vector<std::shared_ptr<Enemy>> enemies = context->enemies;
    for (unsigned int i = 0; i < enemies.size(); i++)
    {
        win->print((pX - context->player->GetPos_x() + enemies[i]->GetPos_x()),
                   (pY - context->player->GetPos_y() + enemies[i]->GetPos_y()),
                   'E');
    }

    //Affichage des collisions boxes
    const std::vector<Box> cb =
        context->map->GetCollisionLayer()->GetCollisionBoxes();
    for (int i = 0; i < (int)cb.size(); i++)
    {
        int w = cb[i].GetWidth();
        int h = cb[i].GetHeight();
        for (int j = cb[i].GetX(); j <= cb[i].GetX() + w; j++)
        {
            for (int k = cb[i].GetY(); k <= cb[i].GetY() + h; k++)
            {
                win->print((pX - context->player->GetPos_x() + j),
                           (pY - context->player->GetPos_y() + k), 'X');
            }
        }
    }

    win->draw();
}

void StateGameTxt::Pause()
{
}

void StateGameTxt::Start()
{
}
