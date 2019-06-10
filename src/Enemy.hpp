#pragma once
#include "ObjectBase.hpp"
#include "PlayerShot.hpp"


//敵本体
class Enemy : public ObjectBase {
	int hp;			//体力
	int interval;	//弾発射間隔
	Vec2 v;			//進んでいる方向
	int count;		//経過フレーム数

public:
	Enemy(const RectF& _rect, const String& _assetName, int _hp, int _interval, const Vec2& _v)
		: ObjectBase(_rect, _assetName, ObjectType::Enemy), hp(_hp), interval(_interval), v(_v), count(0) {}


	void Update() override {
		Move(v);
		count++;
		if (count % 100 == 0) {
			v = -v;
		}
	}

	int CanShot() { return count % interval == 0; }
	int GetHP() const { return hp; }

	void Damage(const Array<PlayerShot>& pShot) {
		for (const auto& s : pShot) {
			if (Collision(s)) {
				hp -= s.GetAttack();
				if (hp <= 0) {
					living = false;
					break;
				}
			}
		}
	}
};
