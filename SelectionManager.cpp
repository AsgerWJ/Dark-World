#include "stdafx.h"

#include "SelectionManager.h"

namespace dw
{
  SelectionManager::SelectionManager(std::vector<BaseEntity*> *entityListGlobal )
  {
    m_entities = entityListGlobal;
  }

  int SelectionManager::SelectEntitiesPoint(sf::Vector2f point)
  {
    int selectionCount = 0;
    auto enIt = m_entities->begin();
    for(enIt; enIt != m_entities->end(); enIt++)
    {
      if( *enIt == NULL)
        continue;
      sf::Vector2f entPos = (*enIt)->GetPos();
      if( 
    }

    return selectionCount;
  }


}; //End namespace dw