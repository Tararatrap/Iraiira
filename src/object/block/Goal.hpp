#pragma once
#include "BlockBase.hpp"
#include "Player.hpp"

class Goal : public BlockBase
{
    bool goal;
public:
    Goal(const RectF& _rect, const String& _assetName)
    : BlockBase(_rect, _assetName, BlockType::Goal, 0), goal(false)
    {
    }
    
    
    bool IsGoal(const Player& player) const
    {
        return this->Collision(player);
    }
};
