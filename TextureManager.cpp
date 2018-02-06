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
    if(LoadTexture(TEXTURE::SMILEY,"") )
      loaded++;


    return loaded;
  }

  int TextureManager::LoadTexture(int textureId, std::string texturepath)
  {

    return 0;
  }
  
};//end namespace dw