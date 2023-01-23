#include "stdafx.h"
#include "PR_Doom.h"

namespace  //変数・定数の宣言
{
	//float ROTATION = 3.0f * 0.9f;
	//Vector3 C_HEIGHT = Vector3(0.0f, 25.0f, 0.0f);
	//Vector3 COLLISION_SIZE = Vector3(120.0f, 30.0f, 20.0f);
}
PR_Doom::PR_Doom()
{
	//モデルを読み込む。
	//modelRender.SetPosition(-120.768, 650.000, -562.369);
	modelRender.SetPosition(-120.768, 300.000, 0);
	modelRender.SetRaytracingWorld(false);
	modelRender.Init("Assets/modelData/MEDAL/PR/Doom.tkm", 0, enModelUpAxisZ);
	/*modelRender.IniTranslucent("Assets/modelData/MEDAL/PR/Doom.tkm",nullptr,0, enModelUpAxisZ,
		true, false);*/
	physicsStaticObjectM.CreateFromModel(modelRender.GetModel(),
		modelRender.GetModel().GetWorldMatrix(), 0.0f);
	//modelRender.SetScale(Vector3(100.0f, 100.0f, 100.0f));
	modelRender.Update();

	//modelRender.SetRotation(Quaternion(0.0f, 180.0f, 0.0f, 0.0f));



	//collisionObject = NewGO<CollisionObject>(0, "collisionObject");

	/*collisionObject->CreateBox(
		position + C_HEIGHT,
		Quaternion(0.0f,0.0f,0.0f,0.0f),
		COLLISION_SIZE
		);
	collisionObject->SetIsEnableAutoDelete(false);*/

	/*ball = FindGO<Ball>("ball");*/
}

PR_Doom::~PR_Doom()
{
	DeleteGO(this);
}

//更新処理。
void PR_Doom::Update()
{
	//Rotation();

	//絵描きさんの更新処理。
	modelRender.Update();

	physicsStaticObjectM.SetPosition(position);
	//collisionObject->SetPosition(position + C_HEIGHT);
}


//描画処理。
void PR_Doom::Render(RenderContext& rc)
{
	//モデルを描画する。
	modelRender.Draw(rc);
}
