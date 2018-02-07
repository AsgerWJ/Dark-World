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
    sf::Texture * GetTexturePtr(int textureId);

  protected:
    int LoadTexture(int textureId, std::string texturepath);
    std::map<int,sf::Texture> m_textures;

  };//end class TextureManager
};// end namespace dw


#endif// TEXTUREMANAGER_H