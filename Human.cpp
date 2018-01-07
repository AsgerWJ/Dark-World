#include "stdafx.h"
#include "Human.h"
#include "dwUtil.h"

namespace dw
{
  Human::Human(sf::Vector2f spawnPos) : dw::BaseEntity(spawnPos)
  {
    m_pos = spawnPos;

    m_speed = 10;

    m_size.x = 10.0;
    m_size.y = 10.0;

    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(4);

    sf::Vertex* quad = &m_vertices[0];

    quad[0].position = sf::Vector2f(spawnPos.x-m_size.x/2,spawnPos.y+m_size.y/2);
    quad[0].color = sf::Color::Green;
    quad[1].position = sf::Vector2f(spawnPos.x+m_size.x/2,spawnPos.y+m_size.y/2);
    quad[1].color = sf::Color::Green;
    quad[2].position = sf::Vector2f(spawnPos.x+m_size.x/2,spawnPos.y-m_size.y/2);
    quad[2].color = sf::Color::Green;
    quad[3].position = sf::Vector2f(spawnPos.x-m_size.x/2,spawnPos.y-m_size.y/2);
    quad[3].color = sf::Color::Green;

  }

  void Human::draw(sf::RenderTarget& target, sf::RenderStates states) const 
  {

    states.transform *= getTransform();

    target.draw(m_vertices,states);
  }

  int Human::Update(const sf::Time &timeFrame)
  {
    if(m_state == BaseEntity::STATE::MOVING)
    {
      bool moving = false;
      float movement = m_speed * timeFrame.asSeconds();

      m_pos += m_targetDirection*movement;

      if(!moving)
        m_state = BaseEntity::STATE::IDLE;

     this->setPosition(m_pos);
    }
   return 1;
  }

  int Human::SetMoveTarget(sf::Vector2f target)
  {
    m_state = BaseEntity::STATE::MOVING;
    m_target = target;
    m_targetDirection = dw::util::vector::NomarlizeVector2f(target-m_pos);
    return BaseEntity::MOVETARGET_OK;

  }
}; //end namespace dw