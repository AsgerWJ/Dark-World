#include "stdafx.h"
#include "Human.h"

namespace dw
{
  Human::Human(int x, int y) : dw::BaseEntity(x,y)
  {
    m_hejsa.setFillColor(sf::Color::Red);
    m_hejsa.setSize(sf::Vector2f(10,10));
    m_hejsa.setPosition(0,0);

    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(4);

    sf::Vertex* quad = &m_vertices[0];

    quad[0].position = sf::Vector2f(100,100);
    quad[0].color = sf::Color::Green;
    quad[1].position = sf::Vector2f(100+x,100);
    quad[1].color = sf::Color::Green;
    quad[2].position = sf::Vector2f(100+x,100+y);
    quad[2].color = sf::Color::Green;
    quad[3].position = sf::Vector2f(100,100+y);
    quad[3].color = sf::Color::Green;

  }

  void Human::draw(sf::RenderTarget& target, sf::RenderStates states) const 
  {
    target.draw(m_hejsa, states);
    target.draw(m_vertices,states);
  }
}; //end namespace dw