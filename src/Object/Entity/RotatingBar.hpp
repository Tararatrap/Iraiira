#include "EntityBase.hpp"

class RotatingBar : public EntityBase
{
    double rad;
    double angularVelocity;
public:
    RotatingBar(const RectF& _rect, const String& _assetName, double _rad = 0.0, double _angularVelocity = 0.0)
    : EntityBase(_rect, _assetName, EntityType.RotatingBar), rad(_rad), angularVelocity(_angularVelocity) {}
    
    void Update() override
    {
        rad += angularVelocity / 60;
    }
    
    void Draw() const override
    {
        TextureAsset(assetName).resize(rect.size).rotatedAt(rect.pos, rad).drawAt(rect.pos);
    }
    
    const double GetRad() const { return rad; }
    const double GetAngularVelocity() const { return angularVelocity; }
}
