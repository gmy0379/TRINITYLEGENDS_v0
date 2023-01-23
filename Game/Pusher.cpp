#include "stdafx.h"
#include "Pusher.h"
#include "Medal.h"

namespace
{
	float SPEED = -50.0f;
	Vector3 COLLISION_HEIGHT = Vector3(-124.0f, 108.0f, -300.0f);
	Vector3	COLLISION_SIZE = Vector3(500.0f, 2.0f, 240.0f);
	Vector3 COLLISION_HEIGHT2 = Vector3(-124.0f, 20.0f, -117.0f);
	Vector3	COLLISION_SIZE2 = Vector3(500.0f, 40.0f, 10.0f);
	const float LIMITA = 20.0f;	//もっとも引く場所
	const float LIMITB = -136.0f;	//もっとも出る場所
	int moveCount = 0;
	float framecount = 0;
}

Pusher::Pusher()
{
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
	
	//モデルを読み込む。
	modelRender.Init("Assets/modelData/MEDAL/pusher11.tkm");
	modelRender.Update();
	physicsStaticObjectP.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix(),2.0f);
	physicsStaticObjectP.SetFriction(0.0f);

	//天面のコリジョンオブジェクト
	/*top = NewGO<CollisionObject>(0, "top");

	top->CreateBox(
		position+ COLLISION_HEIGHT,
		Quaternion::Identity,
		COLLISION_SIZE
	);
	top->SetIsEnableAutoDelete(false);
	firstPosition = position;*/

	//側面のコリジョンオブジェクト
	/*side = NewGO<CollisionObject>(0, "side");

	side->CreateBox(
		position + COLLISION_HEIGHT2,
		Quaternion::Identity,
		COLLISION_SIZE2
	);
	side->SetIsEnableAutoDelete(false);
	firstPosition = position;

	medal = FindGO<Medal>("medal");*/
}

Pusher::~Pusher()
{
	DeleteGO(this);
}

//更新処理。
void Pusher::Update()
{

	if (medal == nullptr)
	{
		medal = FindGO<Medal>("medal");
		//return;
	}

		medal = FindGO<Medal>("medal");

		framecount++;

		Collision();
		Move();

		//絵描きさんの更新処理。
		modelRender.Update();

		modelRender.SetPosition(position);
		physicsStaticObjectP.SetPosition(position);
		//top->SetPosition(position + COLLISION_HEIGHT);
		//side->SetPosition(position + COLLISION_HEIGHT2);
}

void Pusher::Move()
{
	Vector3 moveSpeed = Vector3::Zero;

	if (m_MovingFloorState == enMovingFloorState_MovingBack)
	{
		moveSpeed.z = SPEED;
	}
	else if (m_MovingFloorState == enMovingFloorState_MovingFront)
	{
		moveSpeed.z = -SPEED;
	}

	position += moveSpeed * g_gameTime->GetFrameDeltaTime();

	if (m_MovingFloorState == enMovingFloorState_MovingBack)
	{

		if (firstPosition.z + LIMITB >= position.z)
		{
			m_MovingFloorState = enMovingFloorState_MovingFront;
			framecount = 0;
		}
	}
	else if (m_MovingFloorState == enMovingFloorState_MovingFront)
	{
		if (firstPosition.z - LIMITA <= position.z)
		{
			m_MovingFloorState = enMovingFloorState_MovingBack;
			framecount = 0;
		}

	}
	
	//絵描きさんに座標を教える。
	modelRender.SetPosition(position);
}

void Pusher::Collision()
{
	//天面コリジョンに当たった(条件式開始)
	//if (medal != nullptr) {
		//if (top->IsHit(medal->physicsCyllinderObject) == true)
	//	{
	//		//動く床の移動速度をキャラクターの移動速度に加算。
	//		//MessageBoxA(nullptr, "プッシャー天面と接触しています。", "確認", MB_OK);
	//		//medal->AddForce(position+(Vector3(0.0f,30.0f,50.0f)), position);
	//		//medal->AddMoveSpeed(Vector3(0.0f, 0.0f, 10.0f));

	//		////メダルの位置判定(条件通りなら速度渡す)
	//		if (medal->position.z > -418.0f) {
	//			//medal->AddForce(position + (Vector3(0.0f, 30.0f, 50.0f)), position);
	//			medal->AddMoveSpeed(position * 1);
	//		}

	//		//めり込もうとしたときに跳ね上げる
	//		if (medal->position.y <= 0.0f) {
	//			medal->position.y += 0.5f;
	//		}
	//		////ステート判定(手前移動で速度渡す)
	//		//else if (m_MovingFloorState == enMovingFloorState_MovingFront) {
	//		//	medal->AddMoveSpeed(position * 1);
	//		//}

	//		////どの条件にもかからなかったら移動を禁止
	//		//else medal->position.z +=50.0f;
	//		if (medal->position.z <= -60.0f) {
	//			medal->moveSpeed.z += 20.0f;
	//		}
	//	}
	//}
	

		////側面コリジョンに当たった
		//if (side->IsHit(medal->GetCharacterControllerC()) == true)
		//{
		//	//動く床の移動速度をキャラクターの移動速度に加算。
		//	//MessageBoxA(nullptr, "プッシャー側面と接触しています。", "確認", MB_OK);
		//	medal->AddMoveSpeed(Vector3(0.0f, 0.0f, 10.0f));
		//	
		//	//メダルの位置判定(条件通りなら速度渡す)
		//	if (medal->position.z > -275.0f) {
		//		medal->AddMoveSpeed(position * -1);
		//	}

		//	//ステート判定(手前移動で速度渡す)
		//	else if (m_MovingFloorState == enMovingFloorState_MovingFront) {
		//		medal->AddMoveSpeed(position * -1);
		//	}

		//	//どの条件にもかからなかったら移動を禁止
		//	//else medal->position.z = -420.0f;
		//	else medal->moveSpeed.z += 20.0f;
		//}

		//絵描きさんに座標を教える。
	modelRender.SetPosition(position);
}

//描画処理。
void Pusher::Render(RenderContext& rc)
{
	//モデルを描画する。
	modelRender.Draw(rc);
}