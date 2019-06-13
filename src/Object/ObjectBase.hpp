#pragma once
#include <Siv3D.hpp>

class ObjectBase
{
protected:
    RectF rect;
    String assetName;
    
public:
    ObjectBase(const RectF& _rect, const String& _assetName)
    : rect(_rect), assetName(_assetName) {}
    
    virtual ~ObjectBase() {}
    
    virtual void Draw() const = 0;
    
    bool Collision(const ObjectBase& obj) {
        return rect.intersects(obj.GetRect());
    }
    
    const RectF& GetRect() const { return rect; }
    const Vec2& GetPos() const { return rect.pos; }
};
