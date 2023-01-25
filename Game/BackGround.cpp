#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround()
{
	//コメントアウトする。(当たり判定の描写)
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	//モデルデータには現時点でs14を採用する。
	modelRender.Init("Assets/modelData/MEDAL/s30.tkm");
	modelRender.Update();
	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix(),0.7f);
	physicsStaticObject.SetFriction(0.7f);
}

BackGround::~BackGround()
{

}

void BackGround::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}