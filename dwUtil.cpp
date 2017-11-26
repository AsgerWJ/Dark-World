#include "stdafx.h"
#include "dwUtil.h"


namespace dw
{
  namespace util
  {
    namespace vector
    {

      float MagnitudeVector2f(const sf::Vector2f & in)
      {
        return std::sqrt(std::pow(in.x , 2) + std::pow(in.y , 2) );
      }

      sf::Vector2f NomarlizeVector2f(const sf::Vector2f & in)
      {
        return in / MagnitudeVector2f(in);
      }


    };//end vector namespace

  };//end namespace util
};//end namespace dw