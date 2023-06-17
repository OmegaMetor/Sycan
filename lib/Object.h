#pragma once
#include <vector>
#include <TextureProvider.h>

namespace Sycan{

class Object{
    public:
        AssetProvider::TextureProvider textureProvider;
        struct
        {
            struct
            {
                int x;
                int y;
            } size;
            bool flipX;
            bool flipY;
        } textureInfo;
        
        
};

}