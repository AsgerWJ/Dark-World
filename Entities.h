

class Entity : public sf::Drawable
{
public:
  Entity(int x, int y);

  virtual int Update(); //Updates entity. Call this before drawing



  enum
  {
    UNSPECIFIED_ERROR = -1,
    NO_ERROR = 0
  };

protected:
  int m_xpos;
  int m_ypos;
private:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};