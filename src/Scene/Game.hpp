#pragma once
#include "SceneBase.hpp"
#include "EntityBase.hpp"
#include "Player.hpp"
#include "PlayerShot.hpp"
#include "Enemy.hpp"
#include "EnemyShot.hpp"


//ゲーム中のシーン
class Game : public SceneBase
{
	Player player;
	Array<PlayerShot> pShot;
	Array<Enemy> enemy;
	Array<EnemyShot> eShot;
	
public:
	Game();
	~Game();
	void Draw() const override;
	void Update() override;

};

