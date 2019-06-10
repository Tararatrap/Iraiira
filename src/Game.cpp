#include "Game.hpp"
#include "GameClear.hpp"
#include "GameOver.hpp"

using namespace std;

Game::Game()
	: player(RectF(500, 500, 50, 50), U"player", 5, 5)
{
	for (int i = 0; i < 5; i++) {
		Enemy tmp(RectF(100 + 100 * i, 100, 50, 50), U"enemy", 5, 50, Vec2(3, 3));
		enemy.push_back(tmp);
	}
}

Game::~Game()
{
}


void Game::Draw() const
{
	player.Draw();
	for (const auto& s : pShot) {
		s.Draw();
	}
	for (const auto& e : enemy) {
		e.Draw();
	}
	for (const auto& s : eShot) {
		s.Draw();
	}

}


void Game::Update()
{
	for (auto& s : pShot) {
		s.Update();
	}

	player.Update();
	if (KeySpace.pressed() && player.CanShot()) {
		pShot.push_back(PlayerShot(RectF(player.GetPos(), 5, 30), U"playerShot", 1, 1, Vec2(0, -20)));
		player.Shot();		//プレイヤーが弾出したことを通知
	}

	for (auto& s : eShot) {
		s.Update();
	}

	for (auto& e : enemy) {
		e.Update();
		if (e.CanShot()) {
			eShot.push_back(EnemyShot(RectF(e.GetPos(), 5, 30), U"enemyShot", 1, 1, Vec2(0, 20)));
		}
	}

	player.Damage(eShot);				//ダメージ計算
	for (size_t i = 0; i < enemy.size(); i++) {
		enemy[i].Damage(pShot);			//ダメージ計算
		if (!enemy[i].IsLiving()) {		//死亡
			enemy.erase(enemy.begin() + i);
			i--;
		}
	}

	if (!player.IsLiving()) {		//プレイヤー死亡
		nextScene = make_unique<GameOver>();
	}
	if (enemy.empty()) {			//敵全滅
		nextScene = make_unique<GameClear>();
	}
}
