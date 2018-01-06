#ifndef SELECTIONMANAGER_H
#define SELECTIONMANAGER_H
#include "Entities.h"
namespace dw
{
  class SelectionManager
  {
  public:
    SelectionManager(std::vector<dw::BaseEntity*> *entityListGlobal);

    int SelectEntitiesInArea(sf::Vector2f firstPoint, sf::Vector2f lastPoint);
    int SelectEntitiesInArea(sf::Vector2i firstPoint, sf::Vector2i lastPoint);

  protected:
      std::vector<BaseEntity *> *m_entities;
      std::vector<BaseEntity *> m_selectedEntities;
  }; //end class SelectionManager
};//end namespace dw

#endif// SELECTIONMANAGER_H