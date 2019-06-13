#pragma once
#include "SceneBase.hpp"

//ゲームクリアのシーン
class GameClear : public SceneBase
{
	Font font;

public:
	GameClear();
	~GameClear();
	void Draw() const override;
	void Update() override;

};

