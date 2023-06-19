#pragma once
#include <vector>
#include <SDL2/SDL.h>

namespace Sycan {
namespace AssetProvider{

class TextureProvider{
    SDL_Texture* texture;
    public:
    SDL_Texture* getTexture();
    TextureProvider(const char* texturePath);
    TextureProvider();
};

}
}