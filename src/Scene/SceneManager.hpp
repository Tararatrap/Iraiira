#pragma once
#include "SceneBase.hpp"
#include "Title.hpp"

class SceneManager
{
	std::unique_ptr<SceneBase> currentScene;
	std::unique_ptr<SceneBase> prevScene;

public:
	SceneManager()
		: currentScene(std::move(std::make_unique<Title>())), prevScene(nullptr)
	{
	}

	void Update() {
		// Move, Update Scene
		if (currentScene->IsFinished()) {
			MoveScene();
		}
		else {
			currentScene->Update();
		}
	}

	void Draw() const {
		// Draw
		if (currentScene->GetPrevDraw() && prevScene) {
			prevScene->Draw();
		}
		currentScene->Draw();
	}

	void MoveScene() {

		// ChangeScene
		if (currentScene->NextSceneNullCheck()) {
			// 次のシーンへ
			auto nextScene = currentScene->GetNextScene();
			if (currentScene->GetSaveScene()) {
				prevScene = std::move(currentScene);
			}
			currentScene = std::move(nextScene);
		}
		else if (currentScene->GetReturnScene() && prevScene) {
			// 前のシーンに戻る
			currentScene = std::move(prevScene);
			prevScene = nullptr;
		}
	}
};
