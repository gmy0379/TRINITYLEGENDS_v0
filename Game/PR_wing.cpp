#include "stdafx.h"
#include "PR_wing.h"
#include "Game.h"
#include <time.h>

namespace  //変数・定数の宣言
{
	float ROTATION = 30.0f * 1.1765573f;
	//Vector3 C_HEIGHT = Vector3(0.0f, 25.0f, 0.0f);
	//Vector3 COLLISION_SIZE = Vector3(120.0f, 30.0f, 20.0f);
}
PR_wing::PR_wing()
{
	srand((unsigned int)time(NULL));
	//float ROTATION = rand() % 3 * 0.8f;
	//モデルを読み込む。
	//modelRender.SetPosition(0.0, 0.0, 0.0);
	modelRender.SetScale(Vector3(1.3f, 1.3f, 1.3f));
	modelRender.SetRaytracingWorld(false);
	modelRender.Init("Assets/modelData/MEDAL/PR/wing.tkm", 0, enModelUpAxisZ);

	physicsStaticObjectM.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix(), 5.0f);
	modelRender.SetPosition(Vector3(-120.768f, 190.000f, 0.0f));
	//modelRender.SetRotation(Quaternion(0.0f, 180.0f, 0.0f, 0.0f));
	physicsStaticObjectM.SetFriction(0.0f);
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

PR_wing::~PR_wing()
{

}

//更新処理。
void PR_wing::Update()
{
	/*if (ball == nullptr)
	{
		ball = FindGO<Ball>("ball");
		return;
	}*/
	ROTATION = ROTATION * 0.99999999999f;

	Rotation();

	//絵描きさんの更新処理。
	modelRender.Update();
	physicsStaticObjectM.SetPosition(Vector3(-120.768f, 190.000f, 0.0f));
	physicsStaticObjectM.SetRotation(rotation);

	//collisionObject->SetPosition(position + C_HEIGHT);
}



void PR_wing::Rotation()
{
	rotation.AddRotationDegY(ROTATION);
	modelRender.SetRotation(rotation);
}


//描画処理。
void PR_wing::Render(RenderContext& rc)
{
	//モデルを描画する。
	modelRender.Draw(rc);
}
