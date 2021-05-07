#include "StatePauseSFML.h"
#include <assert.h>

StatePauseSFML::StatePauseSFML(/* args */)
{
}

StatePauseSFML::StatePauseSFML(std::shared_ptr<Context> &cContext)
    : context(cContext)
{
}

StatePauseSFML::~StatePauseSFML()
{
}

void StatePauseSFML::Init()
{
    assert(textFont.loadFromFile("./data/fonts/BebasNeue-Regular.ttf"));
    textColor = sf::Color(245, 222, 92);

    int winx = context->renderWin->getSize().x;
    int winy = context->renderWin->getSize().y;

    pauseText.setFont(textFont);
    pauseText.setFillColor(textColor);
    pauseText.setOutlineColor(sf::Color::Black);
    pauseText.setOutlineThickness(2);
    pauseText.setString("PAUSE");
    pauseText.setCharacterSize(50);
    pauseText.setOrigin(pauseText.getLocalBounds().left + 
                        pauseText.getLocalBounds().width / 2.0f,
                        pauseText.getLocalBounds().top +
                        pauseText.getLocalBounds().height / 2.0f);
    pauseText.setPosition(winx / 2.0f, winy / 2.0f);

    resumeText.setFont(textFont);
    resumeText.setFillColor(textColor);
    resumeText.setOutlineColor(sf::Color::Black);
    resumeText.setOutlineThickness(2);
    resumeText.setString("Press Escape to resume");
    resumeText.setCharacterSize(50);
    resumeText.setOrigin(resumeText.getLocalBounds().left +
                            resumeText.getLocalBounds().width / 2.0f,
                            resumeText.getLocalBounds().top +
                            resumeText.getLocalBounds().height / 2.0f);
    resumeText.setPosition(winx / 2.0f, winy / 2.0f + 150);
}

void StatePauseSFML::ProcessInput()
{
    sf::Event event;

    while (context->renderWin->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            context->renderWin->close();
            context->quit = true;
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::Escape:
                context->stateMan->PopCurrent();
                break;

            case sf::Keyboard::Key::X:
                context->renderWin->close();
                context->quit = true;
                break;
            
            case sf::Keyboard::M:
                context->isMute = !(context->isMute);
                break;

            default:
                break;
            }
        }
    }
}

void StatePauseSFML::Update()
{
}

void StatePauseSFML::Display()
{
    context->renderWin->draw(pauseText);
    context->renderWin->draw(resumeText);
    context->renderWin->display();
}

void StatePauseSFML::Pause()
{
}

void StatePauseSFML::Start()
{
}
