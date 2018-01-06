#include "stdafx.h"
#include "Entities.h"
namespace dw
{
  BaseEntity::BaseEntity(sf::Vector2f spawnPos)
  {
  m_selectable = false; //default non-selectable
  //Nothing to do here
  }

  int BaseEntity::Update(const sf::Time &timeFrame)
  {
  return BaseEntity::UNSPECIFIED_ERROR;
  }

  void BaseEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const
  {

  }

  /// Control functions

  int BaseEntity::SetSelected(bool selected)
  {
  return BaseEntity::ENTITY_NONSELECTABLE;
  }

  int BaseEntity::SetMoveTarget(sf::Vector2f target)
  {
    m_state = BaseEntity::STATE::IDLE;
    return BaseEntity::MOVETARGET_INVALID;
  }

  sf::Vector2f BaseEntity::GetPos()
  {
    return m_pos;
  }

  //Return true if provided point is within entity
  bool BaseEntity::ContainsPoint(sf::Vector2f point)
  {
    bool inside = true;
    //outide x
    if(point.x < (m_pos.x - m_size.x/2) || point.x > (m_pos.x + m_size.x/2) )
      inside = false;

    //outside y
    if(point.y < (m_pos.y - m_size.y/2) || point.y > (m_pos.y + m_size.y/2) )
      inside = false;
    return inside;
  }
}; //end namespace