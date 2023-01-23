#pragma once

//class Bouto;
//ボールクラス。
class Ball1 : public IGameObject
{
public:
	Ball1();
	~Ball1();
	const Vector3& GetPosition() const
	{
		return position;
	}
	//Bouto* bouto;
	//更新処理。
	void Update();
	//描画処理。
	void Render(RenderContext& rc);
	//移動処理。
	
	//void Rotation();
	//ステート管理。
	void ManageState();
	//アニメーションの再生。
	void PlayAnimation();
	//音楽の再生
	void PlayMusic();
	void AddMoveSpeed(const Vector3& addMoveSpeed)
	{
		moveSpeed += addMoveSpeed;
	}

	/*CharacterController& GetCharacterController()
	{
		return characterController;
	}*/
int ballState = 0;	//プレイヤーのステート(状態)を表す変数。
private:
	
	void Move();
	//メンバ変数。
	ModelRender modelRender;	//モデルレンダ―。
	Vector3 position;			//座標。



	//CharacterController characterController;  //キャラクターコントローラー。
	Vector3 moveSpeed;		//移動速度。
	Quaternion rotation;  //クォータニオン。
	Vector3 firstPosition;		//最初の座標。
	

	PhysicsSphereObject physicsSphereObject;

};
