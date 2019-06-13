# include <Siv3D.hpp> // OpenSiv3D v0.3.2
#include "SceneManager.hpp"


void Main() {
    //ゲーム中の画像のアセット登録
    TextureAsset::Register(U"player", U"player.png");
    TextureAsset::Register(U"stone", U"stone.png");
    TextureAsset::Register(U"air", U"air.png");
    TextureAsset::Register(U"goal", U"goal.png");
    TextureAsset::Register(U"rotaiting_bar", U"rotating_bar.png");
    
    SceneManager sceneMgr;
    
    //ESCやエラーが起きるまでループ
    while (System::Update()){
        sceneMgr.Update();
        sceneMgr.Draw();
    }
}
