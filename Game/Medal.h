#pragma once

class Counter;
class Choice;
//プレイヤークラス。
class Medal : public IGameObject
{
public:
	Medal();
	~Medal();
	//更新処理。
	void Update();
	//描画処理。
	void Render(RenderContext& rc);
	const Vector3& GetPosition() const
	{
		return position;
	}

	void AddMoveSpeed(const Vector3& addMoveSpeed)
	{
		position += addMoveSpeed;
	}

	//移動処理。
	
	void Rotation();
	//ステート管理。
	void LevelState();
	//アニメーションの再生。
	//void PlayAnimation();
	//音楽の再生
	void PlayMusic();

	CollisionObject* collisionObject;		//コリジョンオブジェクト。
	Vector3 position;			//座標。
	Vector3 firstPosition;		//最初の座標。
	Vector3 moveSpeed;		//移動速度。
	private:
	//メンバ変数
	//void Move();

	Choice* choice;
	ModelRender modelRender;	//モデルレンダ―。
	Counter* counter;
	Quaternion rotation;  //クォータニオン。
	int playerState = 0;	//プレイヤーのステート(状態)を表す変数。
	FontRender fontRender;
	int M = 0;
	int GetSentaku = 0;

	PhysicsCylinderObject physicsCylinderObject;
};
