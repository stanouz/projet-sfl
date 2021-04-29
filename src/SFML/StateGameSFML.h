#ifndef __STATEGAMESFML_H__
#define __STATEGAMESFML_H__

#include "../Core/Game.h"
#include "../Core/StateManager/State.h"
#include <SFML/Audio.hpp>

class StateGameSFML : public State
{
public:
    StateGameSFML(/* args */);
    StateGameSFML(std::shared_ptr<Context> &cContext);
    ~StateGameSFML();

    void Init();

    void ProcessInput();

    void Update();
    void UpdatePlayer();
    void UpdateEnemies();

    void Display();
    void DisplayMap();
    void DisplayPlayer();
    void DisplayEnemies();
    void DisplayDebug();

    void Pause();

    void Start();

    void MovePlayerWithCollision(float vx, float vy);

private:
    std::shared_ptr<Context> context;

    sf::Texture tileTexture;
    sf::Sprite tileSprite, playerSprite, shadowSprite, enemySprite;

    // Horloge pour le delta time
    sf::Clock deltaClock;
    float deltaTime;

    // Horloge pour l'animation du sprite
    sf::Clock spriteClock;
    int posX = 0;

    // Horloge pour les fps
    sf::Clock fpsClock;
    int fps;

    // Position du joueur
    int playerX, playerY;

    // Direction mouvement du joueur
    bool isGoingUp, isGoingDown, isGoingLeft, isGoingRight, isWalking;

    // Info sur la tilemap
    int w, h, nbMapLayer, x, y, data;

    // Gestion de camera qui suit le joueur
    int substX, substY;

    //Taille de la fenêtre
    int winWidth, winHeight;

    //Taille de la map
    int mapWidth, mapHeight;

    // Texte pour l'UI
    sf::Font textFont;
    sf::Text hpText;

    // Image pour l'UI
    sf::Texture heartText;
    sf::Sprite heartSprite;

    bool isPaused;

    // Gestion scintillement rouge lorsque le joueur prend des dégâts
    sf::Clock hitClock;
    int lastHP;
    bool playerGotHitted;

    // Musique et sons
    bool isMute;
    sf::Music music;
    sf::SoundBuffer runningBuffer;
    sf::Sound runningSound;
};

#endif // __STATEGAMESFML_H__