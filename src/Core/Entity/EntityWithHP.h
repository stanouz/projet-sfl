#ifndef ENTITYWITHHP_H
#define ENTITYWITHHP_H

#include "EntityWithoutHP.h"
#include <string>

using namespace std;

/*! \class EntityWithHP
*   \brief Classe représentant une entité qui peut infliger/subir des dégats et se déplacer.
*
*   La classe représente une entité avec un nom, des points de vie, une position, des dégats d'attaque,
*   une vitesse et un cap maximum de points de vie.
*/
class EntityWithHP : public EntityWithoutHP
{
public:
    /*// ==== Fonctions membres publiques === //*/

    /*! \brief Constructeur par défaut.
    *
    *
    *   Créer une entité EntityWithHP avec une position x 0.0, une position y 0.0, un nom "Unknown", 200 hp, 20 de damage,
    *   200 de maxHealth et une vitesse de 1,0 (entité vide).
    *
    */
    EntityWithHP();


    /*! \brief Constructeur avec spécifités de l'entité en paramètre.
    *   \param [in] x : réel positif, position de l'entité sur l'axe X (horizontal).
    *   \param [in] y : réel positif, position de l'entité sur l'axe Y (vertical).
    *   \param [in] name : chaine de caractères, nom de l'entité.
    *   \param [in] hp : entier positif, nombre de points de vie de l'entité.
    *   \param [in] dammage : entier positif, nombre de points de vie infligé lors d'une attaque.
    *   \param [in] maxHealth : entier positif, maximum de points de vie qu'une entité peut avoir.
    *   \param [in] livingStatus : Booléen, définissant si l'entité est morte ou pas.
    *   \param [in] speed : réel positif, vitesse de déplacement de l'entité.
    *
    *
    *   Créer une EntityWithHP (x, y, name, hp, dammage, maxHealth, livingStatus, speed)
    *
    */
    EntityWithHP(float x, float y, string name, unsigned int hp, unsigned int damage, float speed, unsigned int maxHealth);


    /*! \brief Destructeur.
    *
    *  Destructeur de la classe EntityWithHP.
    *
    */
    virtual ~EntityWithHP();


    /*! \brief Permet de deplacer l'entité.
    *
    *   Permet de deplacer l'entité avec une vitesse vx sur l'axe x et une vitesse vy
    *   sur l'axe y.
    *
    */
    void Move(float vx, float vy);


    /*! \brief Permets de modifier le nombre de points de vie d'une entité EntityWithHP.
    *
    *
    *   Permet de remplacer la valeur actuelle de Hp de l'entité en une valeur newHp.
    *
    *   \param [in] newHp : entier positif, nouveau nombre de points de vie de l'entité.
    *
    *
    */
    void SetHP(unsigned int newHp);

    /*! \brief Retourne le nombre de points de vie de l'entité.
    *
    *   Retourne le nombre de points de vie Hp actuelle de l'entité EntityWithHP.
    *
    *
    */
    int GetHP() const;


    /*! \brief Permets de modifier la vitesse de déplacement de l'entité EntitywithHP.
    *
    *
    *   \param [in] newSpeed: réel positif, nouvelle vitesse de déplacement de l'entité.
    *
    */
    void SetSpeed(float newSpeed);


    /*! \brief Retourne la vitesse de déplacement de l'entité EntityWithHP.
    *
    *   Retourne la vitesse de déplacement Speed de l'entité  EntityWithHP.
    *
    *
    */
    float GetSpeed() const;


    /*! \brief Permet de modofier les dégats infligés par l'entité EntityWithHP.
    *
    *   Modifie la quantité de dégats qu'inflige l'entité EntityWithP.
    *
    *   \param [in] newDmg : entier positif, nouveau nombre de points de vie de l'entité.
    *
    *
    */
    void SetDamage(unsigned int newDmg);


    /*! \brief Permet de retourner le nombre de dégats q'inflige l'entité EntityWithHP.
    *
    *   Retourne damage le nombre de points de vie qu'inflige une entité lors d'une attaque.
    */
    int GetDamage() const;


    /*! \brief Permet d'imprimer sur la console des informations générales concernant l'entité.
    *
    *   Imprime sur la console des informations concernant l'entité.
    *
    *
    */
    void PrintEntityInfo() override;


    /*! \brief Permet de faire en sorte qu'une entité subisse le nombre "damage" dégats.
    *
    *   \param [in] damage : entier positif, dégats à infliger.
    *
    */
    void TakeDamage(unsigned int damage);


    /*! \brief Permet d'infliger damage dégats à l'entité target.
    *
    *
    *   \param [in] target : EntityWithHP qui va subir le nombre "damage" dégats.
    *   \param [in] damage : entier positif, nombre de dégats à infligerà l'entité target.
    *
    */
    void Attack(EntityWithHP &target, unsigned int damage) const;


    /*! \brief Modifie l'état de vie/mort de l'entité.
    *
    *   Modifie l'état de vie/mort de l'entité.
    *
    *   \param [in] newStatus : booléen : indique si l'entitté EntityWithHP est en vie ou pas.
    *
    */
    void SetLivingStatus (bool newStatus);


    /*! \brief Retourne l'état de vie/mort de l'entité.
    *
    *   Retourne l'état de vie/mort de l'entité.
    *
    */
    bool GetLivingStatus() const;


    /*! \brief Retourne le cap maximum de points de vie de l'entité.
    *
    *   Retourne le cap maximum de points de vie de l'entité.
    *
    */
    int GetMaxHealth() const;

protected :
    /*// ==== Données membres protégées === //*/

    /*! \brief Nombre entier de points de vie de l'entité */
    unsigned int hp;

    /*! \brief Nombre entier de points de vie infligé lors d'un attaque */
    unsigned int damage;

    /*! \brief Booléen définissant si l'entité est morte ou pas */
    bool livingStatus;

    /*! \brief Nombre entier maximal de points de vie de l'entité */
    unsigned int maxHealth;

    /*! \brief Vitesse de l'entité */
    float speed;
};

#endif
