#pragma once
#include "SceneBase.hpp"
#include "BlockBase.hpp"
#include "EntityBase.hpp"
#include "Player.hpp"
#include "Goal.hpp"
#include "RotatingBar.hpp"

//ゲーム中のシーン
class Game : public SceneBase
{
	Player player;
    const Size fieldSize;
    const int blockSize;
    RotatingBar rotatingBar;
    Grid<BlockBase> fieldBlocks;
    Array<Goal> goalBlocks;
    
public:
	Game();
	~Game();
	void Draw() const override;
	void Update() override;

};

