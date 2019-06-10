#include "GameClear.hpp"


using namespace std;

GameClear::GameClear()
	: font(60)
{
}


GameClear::~GameClear()
{
}


void GameClear::Draw() const
{
	font(U"ゲームクリア").drawAt(Window::Center(), Palette::White);
}


void GameClear::Update()
{
	if (KeyEnter.down()) {
		System::Exit();
	}
}

