#ifndef SELECTIONMANAGER_H
#define SELECTIONMANAGER_H
#include "Entities.h"
namespace dw
{
  class SelectionManager
  {
  public:
    SelectionManager(std::vector<dw::BaseEntity*> *entityListGlobal);

    int SelectEntitiesPoint(sf::Vector2f point);

  protected:
      std::vector<BaseEntity *> *m_entities;
  }; //end class SelectionManager
};//end namespace dw

#endif// SELECTIONMANAGER_H