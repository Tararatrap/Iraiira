# pragma once
# include <Siv3D.hpp> // OpenSiv3D v0.2.7

class SceneBase {

protected:
	std::unique_ptr<SceneBase> nextScene;
	bool returnScene;
	bool saveScene;
	bool prevDraw;

public:
	SceneBase()
		: nextScene(nullptr), returnScene(false), saveScene(false), prevDraw(false)
	{}

	virtual void Draw() const = 0;

	virtual void Update() = 0;

	[[nodiscard]] bool NextSceneNullCheck() const {
		return nextScene != nullptr;
	}

	[[nodiscard]] std::unique_ptr<SceneBase> GetNextScene() {
		return std::move(nextScene);
	}

	[[nodiscard]] bool GetReturnScene() const {
		return returnScene;
	}

	[[nodiscard]] bool GetSaveScene() const {
		return saveScene;
	}

	[[nodiscard]] bool GetPrevDraw() const {
		return prevDraw;
	}

	virtual bool IsFinished() const { return nextScene != nullptr || returnScene; }

	//デストラクタ(継承されるデストラクタは仮想関数に！)
	virtual ~SceneBase() {}
};
