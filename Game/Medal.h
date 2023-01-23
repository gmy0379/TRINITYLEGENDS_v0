#pragma once

class Counter;
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

	//void AddForce(const Vector3& force, const Vector3& relPos)
	//{
	//	btVector3 btForce;
	//	btVector3 btRelPos;
	//	btForce.setValue(force.x, force.y, force.z);
	//	btRelPos.setValue(relPos.x, relPos.y, relPos.z);
	//	/*position->applyForce(btForce, btRelPos);
	//	position->activate();*/
	//}
	void AddMoveSpeed(const Vector3& addMoveSpeed)
	{
		position += addMoveSpeed;
	}

	/*CharacterControllerCylinder& GetCharacterControllerC()
	{
		return characterControllerC;
	}*/
	/*CollisionObject& GetCollisionObject()
	{
		return collisionObject;
	}*/

	//移動処理。
	
	void Rotation();
	//ステート管理。
	//void ManageState();
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

	
	ModelRender modelRender;	//モデルレンダ―。
	Counter* counter;
	Quaternion rotation;  //クォータニオン。
	int playerState = 0;	//プレイヤーのステート(状態)を表す変数。
	FontRender fontRender;
	int M = 0;

	PhysicsCylinderObject physicsCylinderObject;
};
