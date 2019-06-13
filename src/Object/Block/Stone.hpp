#pragma once
#include "BlockBase.hpp"

class Stone : public BlockBase
{
    
public:
    Stone(const RectF& _rect, const String& _assetName)
    : BlockBase(_rect, _assetName, BlockType.Stone) {};
    
}
