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
    //m_state = STATE::MOVING;
    m_movement = movementDir;
  }

  int Player::Update(const sf::Time &timeFrame)
  {
    if(util::vector::MagnitudeVector2f(m_movement) > 0.0)
    {
      m_state = STATE::MOVING;
      //Do movement
      sf::Vector2f movement = util::vector::NomarlizeVector2f(m_movement)*m_speed*timeFrame.asSeconds();
      m_pos += movement;
      m_movement.x = 0;
      m_movement.y = 0;
      this->setPosition(m_pos);
    }
    else
      m_state = STATE::IDLE;

    return NO_ERROR;
  }

  void Player::loadTexture(sf::Texture *texture)
  {
    BaseEntity::loadTexture(texture);

    sf::Vertex* quad = &m_vertices[0];
    // define its 4 texture coordinates
    quad[0].texCoords = sf::Vector2f(0,10);
    quad[1].texCoords = sf::Vector2f(0,0);
    quad[2].texCoords = sf::Vector2f(10,0);
    quad[3].texCoords = sf::Vector2f(10,10);
  }

  void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
  {
    // apply the transform
    states.transform *= getTransform();

    // our particles don't use a texture
    states.texture = m_pTexture;

    // draw the vertex array
    target.draw(m_vertices, states);
  }

};//end namespace dw