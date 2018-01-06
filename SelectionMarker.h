#ifndef SELECTIONMARKER_H
#define SELECTIONMARKER_H

namespace dw
{
  //SelectionMarker class should be assigned to all selectable entities.
  //Handles drawing of 
  class SelectionMarker : public sf::Drawable , public sf::Transformable
  {
  public:
    SelectionMarker();
    void SetState(bool active);

  }; //End SelectionMarker class




}; //End namespace dw

#endif //SELECTIONMARKER_H