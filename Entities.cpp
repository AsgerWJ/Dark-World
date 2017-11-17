#include "stdafx.h"
#include "Entities.h"

Entity::Entity(int x, int y)
{
  //Nothing to do here
}

int Entity::Update()
{
  return Entity::UNSPECIFIED_ERROR;
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}