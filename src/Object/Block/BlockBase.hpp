#pragma once
#include <Siv3D.hpp>
#include "ObjectBase.hpp"

class BlockBase : public ObjectBase
{
protected:
    enum class BlockType {
        Stone,
    };
    
    BlockType type;
    
public:
    BlockBase(const RectF& _rect, const String& _assetName = U"", BlockType _type = BlockType.Stone)
    : ObjectBaes(_rect, _assetName), type(_type) {}
    
    virtual ~BlockBase()
    {
    }
    
    virtual void Draw() const override
    {
        if (!assetName.isEmpty()) {
            TextureAsset(assetName).resize(rect.size).drawAt(rect.pos);
        }
    }
    
    const BlockType GetBlockType() const { return type; }
}
