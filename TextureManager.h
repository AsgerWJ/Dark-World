#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "string"

namespace dw
{
  class TextureManager
  {
  public:
    TextureManager();
    int LoadTextures();


  protected:
    int LoadTexture(int textureId, std::string texturepath);


  };//end class TextureManager
};// end namespace dw


#endif// TEXTUREMANAGER_H