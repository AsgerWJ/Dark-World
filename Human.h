#include "Entities.h"
namespace dw
{
  class Human : public dw::BaseEntity
  {
  public:
    Human(int x, int y);

  protected:
    sf::RectangleShape m_hejsa;

    sf::VertexArray m_vertices;

    int m_speed; // pixels/sec

  private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  };//end class Human
};//end namespace dw