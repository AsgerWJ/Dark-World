#ifndef SELECTIONMANAGER_H
#define SELECTIONMANAGER_H
#include "Entities.h"
namespace dw
{
  class SelectionManager
  {
  public:
    SelectionManager(std::vector<dw::BaseEntity*> *entityListGlobal, std::vector<dw::BaseEntity*> *selectedListGlobal);

    int SelectEntitiesInArea(sf::Vector2f firstPoint, sf::Vector2f lastPoint,bool add);
    int SelectEntitiesInArea(sf::Vector2i firstPoint, sf::Vector2i lastPoint,bool add);

  protected:
      std::vector<BaseEntity *> *m_pEntities;
      std::vector<BaseEntity *> *m_pSelectedEntities;
  }; //end class SelectionManager
};//end namespace dw

#endif// SELECTIONMANAGER_H