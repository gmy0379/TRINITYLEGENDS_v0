#include "stdafx.h"
#include "Bout2.h"

Bout2::Bout2()
{
	//�R�����g�A�E�g����B
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	//�s���������쐬�B
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