#pragma once
#include <vector>
#include <SDL2/SDL.h>

namespace Sycan {
namespace AssetProvider{

class TextureProvider{
    public:
    virtual SDL_Texture* getTexture();
};

}
}