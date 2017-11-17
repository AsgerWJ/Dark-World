#include "stdafx.h"
#include "Man.h"

Man::Man(int x, int y) : Entity(x,y)
{
  m_vertices.setPrimitiveType(sf::Quads);
  m_vertices.resize(1);
  sf::Vertex* quad = &m_vertices[0];
  
  quad[0].position = sf::Vector2f(0,0);
  quad[1].position = sf::Vector2f(x,0);
  quad[2].position = sf::Vector2f(0,0);
  quad[3].position = sf::Vector2f(0,y);
}

int Man::Update()
{
  return Entity::UNSPECIFIED_ERROR;
}

void Man::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(m_vertices,states);
}