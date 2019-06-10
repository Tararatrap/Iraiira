#pragma once
# include <Siv3D.hpp> // OpenSiv3D v0.3.2


// 敵、弾、自機の共通オブジェクト
class ObjectBase {
protected:
	enum class ObjectType {
		Player,
		PlayerShot,
		Enemy,
		EnemyShot,
	};

	RectF rect;				//オブジェクトの領域
	String assetName;	//画像アセット名
	bool living;			//生存しているかどうか
	ObjectType type;		//オブジェクトの種類

public:
	ObjectBase(const RectF& _rect, const String& _assetName = U"", ObjectType _type = ObjectType::Player)
		: rect(_rect), assetName(_assetName), type(_type), living(true) {}

	virtual ~ObjectBase() {}
	virtual void Draw() const {
		if (!assetName.isEmpty() && IsLiving()) {
			TextureAsset(assetName).resized(rect.size).draw(rect.pos);
		}
	}
	virtual void Update(){}

	void Move(const Vec2& v) {
		rect.pos += v;
	}

	const Vec2& GetPos() const {
		return rect.pos;
	}

	const RectF& GetRect() const {
		return rect;
	}

	ObjectType GetObjectType() const {
		return type;
	}

	bool Collision(const ObjectBase& a) {
		return GetRect().intersects(a.GetRect());
	}

	virtual bool IsLiving() const { return living; }
};
