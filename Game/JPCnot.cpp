#include "stdafx.h"
#include "JPCnot.h"

namespace  //�ϐ��E�萔�̐錾
{
	//float ROTATION = 3.0f * 0.9f;
	//Vector3 C_HEIGHT = Vector3(0.0f, 25.0f, 0.0f);
	//Vector3 COLLISION_SIZE = Vector3(120.0f, 30.0f, 20.0f);
}
JPCnot::JPCnot()
{
	//���f����ǂݍ��ށB
	modelRender.SetPosition(-120.768, 650.000, -562.369);
	modelRender.SetRaytracingWorld(false);
	modelRender.Init("Assets/modelData/MEDAL/JPC/Jnot10x7.tkm", 0, enModelUpAxisZ);
	
	physicsStaticObjectM.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix(), 3.0f);
	physicsStaticObjectM.SetFriction(4.0f);
	//modelRender.SetScale(Vector3(10.0f, 10.0f, 10.0f));
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

JPCnot::~JPCnot()
{

}

//�X�V�����B
void JPCnot::Update()
{
	/*if (ball == nullptr)
	{
		ball = FindGO<Ball>("ball");
		return;
	}*/

	//Rotation();

	//�G�`������̍X�V�����B
	//modelRender.Update();

	//physicsStaticObjectM.SetRotation(rotation);
	//collisionObject->SetPosition(position + C_HEIGHT);
}



//void RJPCnot::Rotation()
//{
//	rotation.AddRotationDegZ(ROTATION);
//	modelRender.SetRotation(rotation);
//}


//�`�揈���B
void JPCnot::Render(RenderContext& rc)
{
	//���f����`�悷��B
	modelRender.Draw(rc);
}
