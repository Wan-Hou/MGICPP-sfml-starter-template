
#include "GameObject.h"

GameObject::GameObject()
{
    sprite = new sf::Sprite;
}

GameObject::~GameObject()
{
    if (sprite != nullptr)
    {
        delete sprite;
        sprite = nullptr;
    }
}

bool GameObject::initialiseSprite(const std::string& filename)
{
    if (!texture.loadFromFile(filename))
    {
        return false;
    }
    sprite->setTexture(texture);

    return true;
}

sf::Sprite* GameObject::getSprite()
{
    return sprite;
}

void GameObject::setSpeed(float change)
{
    speed = change;
}

float GameObject::getSpeed() const
{
    return speed;
}