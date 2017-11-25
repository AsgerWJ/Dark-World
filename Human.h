#ifndef HUMAN_H
#define HUMAN_H


#include "Entities.h"

namespace dw
{
  class Human : public dw::BaseEntity
  {
  public:
    Human(int x, int y);

    int Update(const sf::Time &timeFrame);

  protected:
    sf::RectangleShape m_hejsa;

    sf::VertexArray m_vertices;


  private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  };//end class Human
};//end namespace dw

#endif //HUMAN_H