#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround()
{
	//�R�����g�A�E�g����B(�����蔻��̕`��)
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	//���f���f�[�^�ɂ͌����_��s14���̗p����B
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