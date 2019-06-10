#pragma once
#include "SceneBase.hpp"

//ゲームオーバーのシーン
class GameOver : public SceneBase
{
	Font font;

public:
	GameOver();
	~GameOver();
	void Draw() const override;
	void Update() override;

};

