#include "stdafx.h"
#include "Entities.h"
namespace dw
{
  BaseEntity::BaseEntity(int x, int y)
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

  int BaseEntity::SetMoveTarget(int x, int y)
  {
  return BaseEntity::MOVETARGET_INVALID;
  }
}; //end namespace