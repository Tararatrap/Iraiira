#pragma once
#include "ObjectBase.hpp"
#include "EnemyShot.hpp"


//敵本体
class Player : public ObjectBase {
	int hp;			//体力
	int interval;	//弾発射間隔
	int cooldown;	//弾が次に発射できるまでの時間

public:
	Player(const RectF& _rect, const String& _assetName, int _hp, int _interval)
		: ObjectBase(_rect, _assetName, ObjectType::Player), hp(_hp), interval(_interval), cooldown(0) {}


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
		cooldown--;
	}

	int CanShot() const { return cooldown <= 0; }
	int GetHP() const { return hp; }
	int getcooldown() const { return  cooldown; }

	void Shot() {
		cooldown = interval;
	}

	void Damage(const Array<EnemyShot>& eShot) {
		for (const auto& s : eShot) {
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
