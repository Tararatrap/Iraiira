#pragma once
#include "SceneBase.hpp"

//起動直後のシーン
class Title : public SceneBase
{
	Font font;

public:
	Title();
	~Title();
	void Draw() const override;
	void Update() override;

};

