#ifndef PLAYER_H
#define PLAYER_H

#include "BaseEntity.h"

namespace dw
{
  class Player : public BaseEntity
  {
  public:
    Player(sf::Vector2f spawnPos);
    void SetMovingDirection(sf::Vector2f movementDir);
    int Update(const sf::Time &timeFrame);

    void loadTexture(sf::Texture *texture);

  protected:

    sf::VertexArray m_vertices;
    sf::Vector2f m_movement;

  private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  }; //end class player
};//end namespace dw


#endif //PLAYER_H
