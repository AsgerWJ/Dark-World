#ifndef ENTITIES_H
#define ENTITIES_H
namespace dw
{
  class BaseEntity : public sf::Drawable
  {
  public:
    BaseEntity(int x, int y);

    virtual int Update(); //Updates entity. Call this before drawing

    // Control functions
    virtual int SetSelected(bool selected); //Select or de-select this entity
    virtual int SetMoveTarget(int x, int y); //



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

  protected:
    int m_xpos;
    int m_ypos;

    bool m_selectable;

  private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  };// end BaseEntity class
}; //end namespace

#endif //ENTITIES_H