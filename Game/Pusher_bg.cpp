#include "stdafx.h"
#include "Pusher_bg.h"

Pusher_bg::Pusher_bg()
{
	//�R�����g�A�E�g����B
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

