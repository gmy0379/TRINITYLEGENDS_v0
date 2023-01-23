#include "stdafx.h"
#include "Rjpc.h"
#include "JPCball.h"
#include "Game.h"
#include <time.h>
#include <JPCball.h>

namespace  //�ϐ��E�萔�̐錾
{
	Vector3 C_HEIGHT = Vector3(-120.0f, -120.0f, 0.0f);
	Vector3 COLLISION_SIZE = Vector3(100.0f, 00.0f, -5.0f);
}
Rjpc::Rjpc()
{
	srand((unsigned int)time(NULL));
	//float ROTATION = rand() % 3 * 0.8f;
	//���f����ǂݍ��ށB
	//modelRender.SetPosition(0.0, 0.0, 0.0);
	modelRender.SetRaytracingWorld(false);
	modelRender.Init("Assets/modelData/MEDAL/JPC/Jring10_10x.tkm",0,enModelUpAxisZ);

	physicsStaticObjectM.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix(), 0.0f);
	modelRender.SetPosition(Vector3(-120.768f, 650.000f, -762.369f));
	modelRender.SetRotation(Quaternion(0.0f, 180.0f, 0.0f, 0.0f));
	physicsStaticObjectM.SetFriction(1.0f);
	//modelRender.SetScale(Vector3(10.0f, 10.0f, 10.0f));
	modelRender.Update();

	h100_1 = NewGO<CollisionObject>(0, "h100_1");

	h100_1->CreateBox(
		position + C_HEIGHT,
		Quaternion(0.0f,0.0f,0.0f,0.0f),
		COLLISION_SIZE
		);
	h100_1->SetIsEnableAutoDelete(false);
	firstPosition = position;
	/*ball = FindGO<Ball>("ball");*/
}

Rjpc::~Rjpc()
{

}

//�X�V�����B
void Rjpc::Update()
{
	/*if (ball == nullptr)
	{
		ball = FindGO<Ball>("ball");
		return;
	}*/
	ROTATION =ROTATION* 0.99999999999f;

	Rotation();
	Collision();

	//�G�`������̍X�V�����B
	modelRender.Update();
	physicsStaticObjectM.SetPosition(Vector3( - 120.768f, 650.000f, -762.369f));
	physicsStaticObjectM.SetRotation(rotation);

	h100_1->SetPosition(Vector3(-120.768f, 650.000f, -662.369f));
	h100_1->SetRotation(rotation);
}



void Rjpc::Rotation()
{
	if (jball != nullptr) {
		if (jball->position.y > 470.0f)
		{
			if (jball->position.z < -629.0f)
			{
				ROTATION =0.0f ;
				game->m_time=0;
			}
		}
	}

	rotation.AddRotationDegZ(ROTATION);
	modelRender.SetRotation(rotation);
}

void Rjpc::Collision()
{
	//if (game->m_time == 0);
	/*if (h100_1->IsHit(jballC& physicsSphereObject) == true) {
		rotation.AddRotationDegZ(0);
	}*/
}

//�`�揈���B
void Rjpc::Render(RenderContext& rc)
{
	//���f����`�悷��B
	modelRender.Draw(rc);
}
