#pragma once
#include "EntityBase.hpp"

//敵本体
class Player : public EntityBase {
	int hp;			//体力

public:
	Player(const RectF& _rect, const String& _assetName, int _hp, int _interval)
		: EntityBase(_rect, _assetName, EntityType::Player), hp(_hp) {}


	void Update() override {
		Vec2 v(0, 0);
		if (KeyRight.pressed()) {
			v += Vec2(1, 0);
		}
		if (KeyUp.pressed()) {
			v += Vec2(0, -1);
		}
		if (KeyLeft.pressed()) {
			v += Vec2(-1, 0);
		}
		if (KeyDown.pressed()) {
			v += Vec2(0, 1);
		}
		
		if (!v.isZero()) {
			v = v / v.length() * 5;	//フレーム移動量5に固定
		}
		Move(v);
        
    }

	int GetHP() const { return hp; }
    
    template < class T >
    void Damage(T& obj)
    {
            if(this->Collision(obj)) {
                hp -= obj.GetAttack();
            }
            if(hp <= 0)
            {
                living = false;
                
            }
    }

};
