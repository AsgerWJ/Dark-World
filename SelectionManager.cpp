#include "stdafx.h"

#include "SelectionManager.h"

namespace dw
{
  SelectionManager::SelectionManager(std::vector<BaseEntity*> *entityListGlobal )
  {
    m_entities = entityListGlobal;
  }

  int SelectionManager::SelectEntitiesInArea(sf::Vector2f firstPoint, sf::Vector2f lastPoint)
  {
    int selectionCount = 0;
    auto enIt = m_entities->begin();
    for(enIt; enIt != m_entities->end(); enIt++)
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

      }
    }

    return selectionCount;
  }
  int SelectionManager::SelectEntitiesInArea(sf::Vector2i firstPoint, sf::Vector2i lastPoint)
  {
    return SelectEntitiesInArea(sf::Vector2f((float)firstPoint.x,(float)firstPoint.y), sf::Vector2f((float)lastPoint.x,(float)lastPoint.y) );
  }


}; //End namespace dw