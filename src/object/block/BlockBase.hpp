#pragma once
#include <Siv3D.hpp>
#include "ObjectBase.hpp"

class BlockBase : public ObjectBase
{
protected:
    enum class BlockType {
        Stone,
        Air,
        Goal,
    };
    
    BlockType type;
    
public:
    BlockBase(const RectF& _rect = RectF(0, 0, 0, 0), const String& _assetName = U"", BlockType _type = BlockType::Stone, int _attack = 100, bool _transparent = false)
    : ObjectBase(_rect, _assetName, _attack, _transparent), type(_type) {}
    
    virtual ~BlockBase()
    {
    }
    
    virtual void Draw() const override
    {
        if (!assetName.isEmpty()) {
            TextureAsset(assetName).resized(rect.size).draw(rect.pos);
        }
    }
    
    const BlockType GetBlockType() const { return type; }
};
