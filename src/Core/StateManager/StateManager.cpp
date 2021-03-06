#include "StateManager.h"
#include <iostream>
#include <assert.h>

StateManager::StateManager() : add(false), replace(false), remove(false)
{
}

StateManager::~StateManager()
{
}

void StateManager::Add(std::unique_ptr<State> nState, bool nreplace)
{
    add = true;
    sNewState = std::move(nState);

    replace = nreplace;
}

void StateManager::PopCurrent()
{
    remove = true;
}

void StateManager::ProcessStateChange()
{
    if (remove && (!sStates.empty()))
    {
        sStates.pop();

        if (!sStates.empty())
        {
            sStates.top()->Start();
        }

        remove = false;
    }

    if (add)
    {
        if (replace && (!sStates.empty()))
        {
            sStates.pop();
            replace = false;
        }

        if (!sStates.empty())
        {
            sStates.top()->Pause();
        }

        sStates.push(std::move(sNewState));
        sStates.top()->Init();
        sStates.top()->Start();
        add = false;
    }
}

std::unique_ptr<State> &StateManager::GetCurrent()
{
    return sStates.top();
}

void StateManager::Test() const
{
    std::cout << "===== Class StateManager =====" << std::endl;

    StateManager sm1;

    std::cout << "Constructeur StateManager() : ";
    assert(sm1.add == false);
    assert(sm1.replace == false);
    assert(sm1.remove == false);
    std::cout << "ok" << std::endl;

    std::cout << "Fonction PopCurrent() : ";
    sm1.PopCurrent();
    assert(sm1.add == false);
    assert(sm1.replace == false);
    assert(sm1.remove == true);
    std::cout << "ok" << std::endl;
}
