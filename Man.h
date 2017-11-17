#include "Entities.h"

class Man : public Entity
{
public:
  Man(int x, int y);
  int Update();

protected:
  sf::VertexArray m_vertices;

private:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};