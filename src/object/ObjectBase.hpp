#pragma once
#include <Siv3D.hpp>

class ObjectBase
{
protected:
    RectF rect;
    String assetName;
    int attack; //プレイヤーに触れた時のダメージ
    bool transparent; //透過（当たり判定無視）属性
    
public:
    ObjectBase(const RectF& _rect, const String& _assetName, int _attack = 100, bool _transparent = false)
    : rect(_rect), assetName(_assetName), transparent(_transparent), attack(_attack) {}
    
    virtual ~ObjectBase() {}
    
    virtual void Draw() const = 0;
    
    virtual bool Collision(const ObjectBase& obj) const {
        if(transparent)
        {
            return false;
        }
        else
        {
            return rect.intersects(obj.GetRect());
        }
    }
    
    const RectF& GetRect() const { return rect; }
    const int GetAttack() const { return attack; }
};
