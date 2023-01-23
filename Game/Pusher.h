#pragma once
#include <physics/PhysicsStaticObjectP.h>

class Medal;
class Pusher : public IGameObject
{
public:
	
	Pusher();
	~Pusher();
	//更新処理。
	void Update();
	void Render(RenderContext& rc);
	void SetPosition(const Vector3& pos)
	{
		 position = pos;
	}
	Vector3 position;			//座標

private:
	//移動処理。
	void Move();
	//当たり判定処理
	//当たり判定の処理
	void Collision();

	Medal* medal = nullptr;
	CollisionObject* top = nullptr;		//天面コリジョンオブジェクト。
	//CollisionObject* side = nullptr;		//側面コリジョンオブジェクト。
	
	Vector3	firstPosition;	//初期座標
	Vector3 moveVec;		// 移動ベクトル
	Vector3 moveSpeed=Vector3::Zero;	//移動速度

	ModelRender modelRender;
	PhysicsStaticObjectP physicsStaticObjectP;

	enum enMovingFloorState
	{
		enMovingFloorState_MovingBack,
		enMovingFloorState_MovingFront
	};
	enMovingFloorState		m_MovingFloorState = enMovingFloorState_MovingBack;
};


