#include "GameOver.hpp"
#include "Title.hpp"


using namespace std;

GameOver::GameOver()
	: font(60){
}


GameOver::~GameOver()
{
}


void GameOver::Draw() const
{
	font(U"ゲームオーバー").drawAt(Window::Center(), Palette::White);
}


void GameOver::Update()
{
	if (KeyEnter.down()) {
		nextScene = make_unique<Title>();
	}
}

