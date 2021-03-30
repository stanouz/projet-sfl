#ifndef __ASSET_MANAGER_H__
#define __ASSET_MANAGER_H__

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>

class AssetManager{
    std::vector<sf::Texture> textureEnemy;
    std::vector<sf::Texture> textureNPC;
    sf::Texture texturePlayer;

    // Ajouter son et font
public:
    AssetManager();
    ~AssetManager();

    void AddTextureEnemy(std::string fileTexture);
    void AddTextureNPC(std::string fileTexture);
    void RemoveTextureEnemy(int indice);
    void RemoveTextureNPC(int indice);

    void SetPlayerTexture(std::string fileTexture);

};


#endif