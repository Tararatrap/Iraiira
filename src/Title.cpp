#include "Title.hpp"
#include "Game.hpp"


using namespace std;

Title::Title()
	: font(60)
{
	Window::SetTitle(U"制作練習シューティング");
}


Title::~Title()
{
}


void Title::Draw() const
{
	font(U"制作練習シューティング").drawAt(Window::Center(), Palette::White);
}


void Title::Update()
{
	if (KeyEnter.down()) {
		nextScene = make_unique<Game>();
	}
}

