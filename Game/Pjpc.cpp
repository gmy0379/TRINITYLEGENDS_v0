#include "stdafx.h"
#include "Pjpc.h"
#include "Game.h"

namespace  //変数・定数の宣言
{
	float ROTATION = 1.4f * 0.765f;
	//Vector3 C_HEIGHT = Vector3(0.0f, 25.0f, 0.0f);
	//Vector3 COLLISION_SIZE = Vector3(120.0f, 30.0f, 20.0f);
}
Pjpc::Pjpc()
{
	//モデルを読み込む。
	//modelRender.SetPosition(0.0, 0.0, 0.0);
	//modelRender.SetRotation(Quaternion(0.0f,180.0f,0.0f,0.0f));
	modelRender.SetRaytracingWorld(false);
	modelRender.Init("Assets/modelData/MEDAL/JPC/P_ring.tkm", 0, enModelUpAxisZ);

	physicsStaticObjectM.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix(), 5.0f);
	modelRender.SetPosition(Vector3(-120.768, 650.000, -762.369));
	physicsStaticObjectM.SetFriction(10.0f);
	//modelRender.SetScale(Vector3(10.0f, 10.0f, 10.0f));
	modelRender.Update();

	//collisionObject = NewGO<CollisionObject>(0, "collisionObject");

	/*collisionObject->CreateBox(
		position + C_HEIGHT,
		Quaternion(0.0f,0.0f,0.0f,0.0f),
		COLLISION_SIZE
		);
	collisionObject->SetIsEnableAutoDelete(false);*/
	firstPosition = position;
	/*ball = FindGO<Ball>("ball");*/
}

Pjpc::~Pjpc()
{

}

//更新処理。
void Pjpc::Update()
{
	/*if (ball == nullptr)
	{
		ball = FindGO<Ball>("ball");
		return;
	}*/

	Rotation();

	//絵描きさんの更新処理。
	modelRender.Update();
	physicsStaticObjectM.SetPosition(Vector3(-120.768, 650.000, -762.369));
	physicsStaticObjectM.SetRotation(rotation);

	//collisionObject->SetPosition(position + C_HEIGHT);
}



void Pjpc::Rotation()
{
	rotation.AddRotationDegZ(ROTATION);
	modelRender.SetRotation(rotation);
}


//描画処理。
void Pjpc::Render(RenderContext& rc)
{
	//モデルを描画する。
	modelRender.Draw(rc);
}
