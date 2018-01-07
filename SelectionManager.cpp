#include "stdafx.h"

#include "SelectionManager.h"

namespace dw
{
  SelectionManager::SelectionManager(std::vector<dw::BaseEntity*> *entityListGlobal, std::vector<dw::BaseEntity*> *selectedListGlobal)
  {
    m_pEntities = entityListGlobal;
    m_pSelectedEntities = selectedListGlobal;
  }

  int SelectionManager::SelectEntitiesInArea(sf::Vector2f firstPoint, sf::Vector2f lastPoint,bool add)
  {
    if(!add)
      m_pSelectedEntities->clear();
    int selectionCount = 0;
    auto enIt = m_pEntities->begin();
    for(enIt; enIt != m_pEntities->end(); enIt++)
    {
      if( *enIt == NULL)
        continue;

      float lowerX = std::min(firstPoint.x, lastPoint.x);
      float upperX = std::max(firstPoint.x, lastPoint.x);

      float lowerY = std::min(firstPoint.y, lastPoint.y);
      float upperY = std::max(firstPoint.y, lastPoint.y);

      bool inside = true;
      
      sf::Vector2f pos = (*enIt)->GetPos();

      //outide x
      if(pos.x < lowerX || pos.x > upperX )
        inside = false;

      //outside y
      if(pos.y < lowerY || pos.y > upperY )
        inside = false;

      if ( inside )
      {
        if( std::find(m_pSelectedEntities->begin(), m_pSelectedEntities->end(), (*enIt)) == m_pSelectedEntities->end() )
          m_pSelectedEntities->push_back(*enIt);
      }
    }

    return selectionCount;
  }
  int SelectionManager::SelectEntitiesInArea(sf::Vector2i firstPoint, sf::Vector2i lastPoint,bool add)
  {
    return SelectEntitiesInArea(sf::Vector2f((float)firstPoint.x,(float)firstPoint.y), sf::Vector2f((float)lastPoint.x,(float)lastPoint.y) ,add);
  }


}; //End namespace dw