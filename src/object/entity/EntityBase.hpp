#pragma once
# include <Siv3D.hpp>
#include "ObjectBase.hpp"

// 敵、弾、自機の共通オブジェクト
class EntityBase : public ObjectBase
{
protected:
	enum class EntityType {
		Player,
		PlayerShot,
        RotatingBar,
	};
    
	bool living;			//生存しているかどうか
	EntityType type;		//オブジェクトの種類

public:
    EntityBase(const RectF& _rect, const String& _assetName = U"", EntityType _type = EntityType::Player, int _attack = 100, bool _transparent = false)
		: ObjectBase(_rect, _assetName, _attack, _transparent), type(_type), living(true) {}

	virtual ~EntityBase() {}
    
	virtual void Draw() const override {
		if (!assetName.isEmpty() && IsLiving()) {
			TextureAsset(assetName).resized(rect.size).draw(rect.pos);
		}
	}
	virtual void Update(){}

	void Move(const Vec2& v) {
		rect.pos += v;
	}
    
	EntityType GetEntityType() const {
		return type;
	}

	virtual bool IsLiving() const { return living; }
};
