#include "stdafx.h"
#include "JPCnot2.h"

namespace  //�ϐ��E�萔�̐錾
{
	//float ROTATION = 3.0f * 0.9f;
	//Vector3 C_HEIGHT = Vector3(0.0f, 25.0f, 0.0f);
	//Vector3 COLLISION_SIZE = Vector3(120.0f, 30.0f, 20.0f);
}
JPCnot2::JPCnot2()
{
	//���f����ǂݍ��ށB
	modelRender.SetPosition(-120.768, 650.000, -562.369);
	modelRender.SetRaytracingWorld(false);
	modelRender.Init("Assets/modelData/MEDAL/JPC/Jnot10x7-2.tkm", 0, enModelUpAxisZ);
	//modelRender.IniTranslucent("Assets/modelData/MEDAL/JPC/Jnot10x3-2.tkm",nullptr,0, enModelUpAxisZ,
		//true, false);
	physicsStaticObjectM.CreateFromModel(modelRender.GetModel(),
		modelRender.GetModel().GetWorldMatrix(), 0.0f);
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

JPCnot2::~JPCnot2()
{
	DeleteGO(this);
}

//�X�V�����B
void JPCnot2::Update()
{
	/*if (ball == nullptr)
	{
		ball = FindGO<Ball>("ball");
		return;
	}*/

	//Rotation();

	//�G�`������̍X�V�����B
	modelRender.Update();

	physicsStaticObjectM.SetPosition(position);
	//collisionObject->SetPosition(position + C_HEIGHT);
}



//void RJPCnot2::Rotation()
//{
//	rotation.AddRotationDegZ(ROTATION);
//	modelRender.SetRotation(rotation);
//}


//�`�揈���B
void JPCnot2::Render(RenderContext& rc)
{
	//���f����`�悷��B
	modelRender.Draw(rc);
}
