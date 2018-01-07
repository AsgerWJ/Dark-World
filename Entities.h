#ifndef ENTITIES_H
#define ENTITIES_H

namespace dw
{
  class BaseEntity : public sf::Drawable , public sf::Transformable
  {
  public:
    BaseEntity(sf::Vector2f spawnPos);

    virtual int Update(const sf::Time &timeFrame); //Updates entity. Call this before drawing

    // Control functions
    virtual int SetSelected(bool selected); //Select or de-select this entity
    virtual int SetMoveTarget(sf::Vector2f target); //
    virtual int SetMoveTarget(sf::Vector2i target); //
    virtual sf::Vector2f GetPos();

    virtual bool ContainsPoint(sf::Vector2f point);


    enum
    {
      UNSPECIFIED_ERROR = -1,
      NO_ERROR = 0
    };

    enum
    {
      ENTITY_SELECTED = 0,
      ENTITY_DESELECTED = 1,
      ENTITY_NONSELECTABLE
    };

    enum
    {
      MOVETARGET_OK,
      MOVETARGET_INVALID
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
    sf::Vector2f m_target; //Target coordinates
    sf::Vector2f m_targetDirection; //Target direction normalized

    bool m_selectable;

    int m_state;

  private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  };// end BaseEntity class
}; //end namespace

#endif //ENTITIES_H