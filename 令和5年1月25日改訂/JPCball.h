#pragma once
class Game;
class JPCball :public IGameObject
{
public:
	JPCball();
	~JPCball();
	//更新処理。
	void Update();
	//描画処理。
	void Render(RenderContext& rc);
	/*const Vector3& GetPosition() const
	{
		return position;
	}*/

	//移動処理。

	void Rotation();
	//ステート管理。
	//void ManageState();
	//アニメーションの再生。
	//void PlayAnimation();
	//音楽の再生
	void PlayMusic();

	Game* game;

	Vector3 position;			//座標。
	Vector3 firstPosition;		//最初の座標。
	PhysicsSphereObject physicsSphereObject;
private:
	//メンバ変数
	void Move();
	ModelRender modelRender;	//モデルレンダ―。
	//CharacterController characterController;  //キャラクターコントローラー。
	Quaternion rotation;  //クォータニオン。
	int playerState = 0;	//プレイヤーのステート(状態)を表す変数。
	FontRender fontRender;
	int M = 0;

};

