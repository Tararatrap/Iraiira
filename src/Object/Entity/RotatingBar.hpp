#pragma once
#include "EntityBase.hpp"

class RotatingBar : public EntityBase
{
    double rad;
    double angularVelocity;
public:
    RotatingBar(const Rect& _rect, const String& _assetName, double _rad = 0.0, double _angularVelocity = 0.0)
    : EntityBase(_rect, _assetName, EntityType::RotatingBar), rad(_rad), angularVelocity(_angularVelocity) {}
    
    void Update() override
    {
        rad += angularVelocity / 60;
    }
    
    void Draw() const override
    {
        TextureAsset(assetName).resized(rect.size).rotatedAt(rect.size / 2, rad).drawAt(rect.pos);
    }
    
    const double GetRad() const { return rad; }
    const double GetAngularVelocity() const { return angularVelocity; }
};
