#include "stdafx.h"
#include "Bouto.h"

namespace  //変数・定数の宣言
{
	//Vector3 C_HEIGHT = Vector3(0.0f, 25.0f, 0.0f);
	//Vector3 COLLISION_SIZE = Vector3(120.0f, 30.0f, 20.0f);
}
Bouto::Bouto()
{
	//モデルを読み込む。
	//modelRender.SetPosition(Vector3(420.768, 352.017, -162.369));
	//modelRender.SetPosition(Vector3(0.768, 352.017, -162.369));

	modelRender.Init("Assets/modelData/MEDAL/bouto10.tkm");
	modelRender.Update();
	
	physicsStaticObjectM.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix(),0.0f);
	physicsStaticObjectM.SetFriction(3.0f);
	//modelRender.SetPosition(Vector3(420.768, 352.017, -162.369));
	modelRender.SetPosition(Vector3(343.768, 652.017, -370.369));

	modelRender.Update();

	//collisionObject = NewGO<CollisionObject>(0, "collisionObject");
	
	/*collisionObject->CreateBox(
		position + C_HEIGHT,
		Quaternion(0.0f,0.0f,0.0f,0.0f),
		COLLISION_SIZE
		);
	collisionObject->SetIsEnableAutoDelete(false);*/
	
	/*ball = FindGO<Ball>("ball");*/
}

Bouto::~Bouto()
{

}

//更新処理。
void Bouto::Update()
{
	/*if (ball == nullptr)
	{
		ball = FindGO<Ball>("ball");
		return;
	}*/

	Rotation();

	//絵描きさんの更新処理。
	modelRender.Update();
	//physicsStaticObjectM.SetPosition(Vector3(420.768, 352.017, -162.369));
	physicsStaticObjectM.SetPosition(Vector3(343.768, 652.017, -370.369));
	physicsStaticObjectM.SetRotation(rotation);
	//collisionObject->SetPosition(position + C_HEIGHT);
}



void Bouto::Rotation()
{
	
	rotation.AddRotationDegY(1.0f);
	modelRender.SetRotation(rotation);
}


//描画処理。
void Bouto::Render(RenderContext& rc)
{
	//モデルを描画する。
	modelRender.Draw(rc);
}