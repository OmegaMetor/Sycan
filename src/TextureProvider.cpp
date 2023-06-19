#include "TextureProvider.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Sycan.h"

namespace Sycan
{
    namespace AssetProvider
    {
        TextureProvider::TextureProvider(const char* texturePath){
            texture = IMG_LoadTexture(Sycan::Engine::getEngine()->renderer, texturePath);
        }
        SDL_Texture* TextureProvider::getTexture(){
            return texture;
        }
        TextureProvider::TextureProvider(){
            
        }
    }
}