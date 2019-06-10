
# include <Siv3D.hpp> // OpenSiv3D v0.3.2
#include "SceneManager.hpp"


void Main() {
	//ゲーム中の画像のアセット登録
	TextureAsset::Register(U"player", U"player.png");
	TextureAsset::Register(U"playerShot", U"playerShot.png");
	TextureAsset::Register(U"enemy", U"enemy.png");
	TextureAsset::Register(U"enemyShot", U"enemyShot.png");

	SceneManager sceneMgr;

	//ESCやエラーが起きるまでループ
	while (System::Update()){
		sceneMgr.Update();
		sceneMgr.Draw();
	}
}
