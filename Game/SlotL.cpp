#include "stdafx.h"
#include "SlotL.h"

SlotL::SlotL()
{
	//�R�����g�A�E�g����B(�����蔻��̕`��)
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	//���f���f�[�^���̗p����B
	position = (Vector3(100.565, 152.856, -120.404));
	modelRender.SetRaytracingWorld(false);
	modelRender.Init("Assets/modelData/SLOT/slot8.tkm");
	modelRender.SetScale(Vector3(5.0f, 5.0f, 5.0f));
	
	slocon.Init(5.0f, 0.0f, position);
	slocon.SetPosition(position);
	//physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix(), 0.0f);
	modelRender.Update();
}

SlotL::~SlotL()
{

}

void SlotL::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}