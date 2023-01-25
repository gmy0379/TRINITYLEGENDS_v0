#include "stdafx.h"
#include "Ajpc.h"
#include "Game.h"

namespace  //変数・定数の宣言
{
	float ROTATION = 1.2f * 0.573f;
	//Vector3 C_HEIGHT = Vector3(0.0f, 25.0f, 0.0f);
	//Vector3 COLLISION_SIZE = Vector3(120.0f, 30.0f, 20.0f);
}
Ajpc::Ajpc()
{
	//モデルを読み込む。
	//modelRender.SetPosition(0.0, 0.0, 0.0);
	//modelRender.SetRotation(Quaternion(0.0f,180.0f,0.0f,0.0f));
	modelRender.SetRaytracingWorld(false);
	modelRender.Init("Assets/modelData/MEDAL/JPC/A_ring.tkm", 0, enModelUpAxisZ);

	physicsStaticObjectM.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix(), 1.0f);
	modelRender.SetPosition(Vector3(-120.768f, 650.000f, -762.369f));
	physicsStaticObjectM.SetFriction(6.3f);
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

Ajpc::~Ajpc()
{

}

//更新処理。
void Ajpc::Update()
{
	/*if (ball == nullptr)
	{
		ball = FindGO<Ball>("ball");
		return;
	}*/

	Rotation();

	//絵描きさんの更新処理。
	modelRender.Update();
	physicsStaticObjectM.SetPosition(Vector3(-120.768f, 650.000f, -762.369f));
	physicsStaticObjectM.SetRotation(rotation);

	//collisionObject->SetPosition(position + C_HEIGHT);
}



void Ajpc::Rotation()
{
	rotation.AddRotationDegZ(ROTATION);
	modelRender.SetRotation(rotation);
}


//描画処理。
void Ajpc::Render(RenderContext& rc)
{
	//モデルを描画する。
	modelRender.Draw(rc);
}
