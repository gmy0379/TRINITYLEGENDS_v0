#include "stdafx.h"
#include "Bout.h"

Bout::Bout()
{
	//コメントアウトする。
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	//不動部分を作成。
	//modelRender.IniTranslucent("Assets/modelData/MEDAL/boutx5.tkm");
	modelRender.Init("Assets/modelData/MEDAL/boutx8.tkm");
	modelRender.Update();
	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix(),0.2f);
}

Bout::~Bout()
{
	DeleteGO(this);
}

void Bout::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}