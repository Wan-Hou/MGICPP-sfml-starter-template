
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Functions.h"

class GameObject
{
public:
    GameObject();
    ~GameObject();
    bool initialiseSprite(const std::string& filename);
    sf::Sprite* getSprite();
    void setSpeed(float change);
    float getSpeed() const;

private:
    sf::Sprite* sprite = nullptr;
    sf::Texture texture;
    float speed = 200;
};

class Bird :
    public GameObject
{

};



#endif // GAMEOBJECT_H
