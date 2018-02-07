#include "stdafx.h"
#include "TextureManager.h"
#include "TextureIds.h"

namespace dw
{
  TextureManager::TextureManager()
  {

  }

  int TextureManager::LoadTextures()
  {
    int loaded = 0;
    if(LoadTexture(TEXTURE::SMILEY,"C:\\Development\\Dark-World\\Resources\\Graphics\\smiley.png") )
      loaded++;


    return loaded;
  }

  int TextureManager::LoadTexture(int textureId, std::string texturePath)
  {
    sf::Texture newTexture;
    if (newTexture.loadFromFile(texturePath))
      m_textures[textureId] = newTexture;
    return 0;
  }
  
  sf::Texture * TextureManager::GetTexturePtr(int textureId)
  {
    return &m_textures[textureId];
  }
  
};//end namespace dw