#include "stdafx.h"
#include "Bout2.h"

Bout2::Bout2()
{
	//コメントアウトする。
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	//不動部分を作成。
	modelRender.SetRaytracingWorld(false);
	modelRender.Init("Assets/modelData/MEDAL/boutx5-2.tkm");
	modelRender.Update();
	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix(), 0.2f);
}

Bout2::~Bout2()
{
	DeleteGO(this);
}

void Bout2::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}