#include "stdafx.h"
#include "Pusher_bg.h"

Pusher_bg::Pusher_bg()
{
	//コメントアウトする。
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	modelRender.Init("Assets/modelData/MEDAL/pusher_bg2.tkm");
	modelRender.Update();
	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix());
}

Pusher_bg::~Pusher_bg()
{

}

void Pusher_bg::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}

