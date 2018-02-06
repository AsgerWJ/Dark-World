#ifndef PLAYER_H
#define PLAYER_H

#include "BaseEntity.h"

namespace dw
{
  class Player : BaseEntity
  {
  public:
    Player(sf::Vector2f spawnPos);
    void SetMovingDirection(sf::Vector2f movementDir);
    int Update(const sf::Time &timeFrame);

  protected:

    sf::VertexArray m_vertices;
    sf::Vector2f m_movement;

  private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  }; //end class player
};//end namespace dw


#endif //PLAYER_H
