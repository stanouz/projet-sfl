#ifndef __STATEMENUSFML_H__
#define __STATEMENUSFML_H__

#include "../Core/Game.h"
#include "../Core/StateManager/State.h"


class StateMenuSFML : public State
{
public:
    StateMenuSFML(/* args */);
    StateMenuSFML(std::shared_ptr<Context> &cContext);
    ~StateMenuSFML();

    void Init();

    void ProcessInput();

    void Update();

    void Display();

    void Pause();

    void Start();

private:
    std::shared_ptr<Context> context;

    sf::Font textFont;

    sf::Text gameTitle;
    sf::Text playButton;
    sf::Text exitButton;

    bool isPlayButSelected;
    bool isPlayButPressed;

    bool isExitButSelected;
    bool isExitButPressed;

    
};
#endif // __STATEMENUSFML_H__