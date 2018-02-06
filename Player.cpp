#include "stdafx.h"
#include "Player.h"

namespace dw
{
  Player::Player(sf::Vector2f spawnPos) : dw::BaseEntity(spawnPos)
  {
    m_pos = spawnPos;

    m_speed = 10;

    m_size.x = 10.0;
    m_size.y = 10.0;

    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(4);

    sf::Vertex* quad = &m_vertices[0];

    quad[0].position = sf::Vector2f(spawnPos.x-m_size.x/2,spawnPos.y+m_size.y/2);
    //quad[0].color = sf::Color::Green;
    quad[1].position = sf::Vector2f(spawnPos.x+m_size.x/2,spawnPos.y+m_size.y/2);
    //quad[1].color = sf::Color::Green;
    quad[2].position = sf::Vector2f(spawnPos.x+m_size.x/2,spawnPos.y-m_size.y/2);
    //quad[2].color = sf::Color::Green;
    quad[3].position = sf::Vector2f(spawnPos.x-m_size.x/2,spawnPos.y-m_size.y/2);
    //quad[3].color = sf::Color::Green;
  }

  void Player::SetMovingDirection(sf::Vector2f movementDir)
  {
    m_state = STATE::MOVING;
    m_movement = movementDir;
  }

  int Player::Update(const sf::Time &timeFrame)
  {

    return NO_ERROR;
  }

  void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
  {

  }

};//end namespace dw