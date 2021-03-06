#ifndef HUMAN_H
#define HUMAN_H


#include "BaseEntity.h"

namespace dw
{
  class Human : public dw::BaseEntity
  {
  public:
    Human(sf::Vector2f spawnPos);

    int Update(const sf::Time &timeFrame);

  protected:

    sf::VertexArray m_vertices;


  private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  };//end class Human
};//end namespace dw

#endif //HUMAN_H