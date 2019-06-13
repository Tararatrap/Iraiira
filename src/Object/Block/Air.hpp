#pragma once
#include "BlockBase.hpp"

class Air : public BlockBase
{
public:
    Air(const RectF& _rect, const String& _assetName)
    : BlockBase(_rect, _assetName, BlockType::Air, 0, true) {}
};
