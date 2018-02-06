#ifndef BASEENTITY_H
#define BASEENTITY_H

namespace dw
{
  class BaseEntity : public sf::Drawable , public sf::Transformable
  {
  public:
    BaseEntity(sf::Vector2f spawnPos);

    virtual int Update(const sf::Time &timeFrame); //Updates entity. Call this before drawing

    // Control functions
    virtual sf::Vector2f GetPos();

    virtual bool ContainsPoint(sf::Vector2f point);

    virtual void loadTexture(sf::Texture *texture);


    enum
    {
      UNSPECIFIED_ERROR = -1,
      NO_ERROR = 0
    };

    enum STATE
    {
      IDLE = 0,
      MOVING
    };

  protected:
    sf::Vector2f m_pos;
    sf::Vector2f m_size;
    float m_speed; //pixel/sec

    bool m_selectable;

    int m_state;

    sf::Texture * m_pTexture;

  private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  };// end BaseEntity class
}; //end namespace

#endif //BASEENTITY_H