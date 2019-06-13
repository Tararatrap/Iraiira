#include "Game.hpp"
#include "GameClear.hpp"
#include "GameOver.hpp"
#include "Stone.hpp"
#include "Air.hpp"
#include <iostream>


using namespace std;

Game::Game()
	: player(RectF(125, 400, 30, 30), U"player", 5, 5), rotatingBar(RectF(120, 320, 150,5), U"rotating_bar", 0.0, 1.5), fieldSize(Size(20, 15)), blockSize(40)
{
    const CSVData csv(U"test.csv");
    
    fieldBlocks = Grid<BlockBase>(fieldSize);
    for(int i = 0; i < fieldSize.x; ++i)
    {
        for (int j = 0; j < fieldSize.y; ++j)
        {
            int bs = blockSize;
            const RectF rect = RectF(bs * i, bs * j, bs, bs);
            int32 blockID = csv.get<int32>(j, i);
            if(blockID == 0)
            {
                fieldBlocks[j][i] = Air(rect, U"air");
                cout << "air" << endl;
            }
            else if(blockID == 1)
            {
                fieldBlocks[j][i] = Stone(rect, U"stone");
                cout << "stone" << endl;
            }
            else if(blockID == 3)
            {
                Goal goal = Goal(rect, U"goal");
                fieldBlocks[j][i] = goal;
                goalBlocks.push_back(goal);
                cout << "goal" << endl;
            } else {
                cout << "nothing" << endl;
                
            }
        }
    }
    
}

Game::~Game()
{
}


void Game::Draw() const
{
    for (int x = 0; x < fieldSize.x; ++x)
    {
        for (int y = 0; y < fieldSize.y; ++y)
        {
            fieldBlocks[y][x].Draw();
        }
    }
    
	player.Draw();
    rotatingBar.Draw();
    
}


void Game::Update()
{
    for (auto& block : fieldBlocks)
    {
        player.Damage(block);
    }
    player.Damage(rotatingBar);
    
    player.Update();
    rotatingBar.Update();
    
	if (!player.IsLiving()) {		//プレイヤー死亡
        nextScene = std::make_unique<GameOver>();
	}
    
    for(const auto& goal : goalBlocks)
    {
        if(goal.IsGoal(player))
        {
            nextScene = std::make_unique<GameClear>();
        }
    }
}
