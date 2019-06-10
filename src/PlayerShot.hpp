#pragma once
#include "ObjectBase.hpp"


//自機弾
class PlayerShot : public ObjectBase {
	int hp;			//体力
	int attack;		//攻撃力
	Vec2 v;			//進んでいる方向
	int count;

public:
	PlayerShot(const RectF& _rect, const String& _assetName, int _hp, int _attack, const Vec2& _v)
		: ObjectBase(_rect, _assetName, ObjectType::PlayerShot), hp(_hp), attack(_attack), v(_v), count(0) {}


	void Update() override {
		Move(v);
		if (count > 1000) {
			living = false;
		}
		count++;
	}

	int GetHP() const { return hp; }
	int GetAttack() const { return attack; }
};
