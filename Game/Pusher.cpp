#include "stdafx.h"
#include "Pusher.h"
#include "Medal.h"

namespace
{
	float SPEED = -50.0f;
	Vector3 COLLISION_HEIGHT = Vector3(-124.0f, 108.0f, -300.0f);
	Vector3	COLLISION_SIZE = Vector3(500.0f, 2.0f, 240.0f);
	Vector3 COLLISION_HEIGHT2 = Vector3(-124.0f, 20.0f, -117.0f);
	Vector3	COLLISION_SIZE2 = Vector3(500.0f, 40.0f, 10.0f);
	const float LIMITA = 20.0f;	//�����Ƃ������ꏊ
	const float LIMITB = -136.0f;	//�����Ƃ��o��ꏊ
	int moveCount = 0;
	float framecount = 0;
}

Pusher::Pusher()
{
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
	
	//���f����ǂݍ��ށB
	modelRender.Init("Assets/modelData/MEDAL/pusher11.tkm");
	modelRender.Update();
	physicsStaticObjectP.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix(),2.0f);
	physicsStaticObjectP.SetFriction(0.0f);

	//�V�ʂ̃R���W�����I�u�W�F�N�g
	/*top = NewGO<CollisionObject>(0, "top");

	top->CreateBox(
		position+ COLLISION_HEIGHT,
		Quaternion::Identity,
		COLLISION_SIZE
	);
	top->SetIsEnableAutoDelete(false);
	firstPosition = position;*/

	//���ʂ̃R���W�����I�u�W�F�N�g
	/*side = NewGO<CollisionObject>(0, "side");

	side->CreateBox(
		position + COLLISION_HEIGHT2,
		Quaternion::Identity,
		COLLISION_SIZE2
	);
	side->SetIsEnableAutoDelete(false);
	firstPosition = position;

	medal = FindGO<Medal>("medal");*/
}

Pusher::~Pusher()
{
	DeleteGO(this);
}

//�X�V�����B
void Pusher::Update()
{

	if (medal == nullptr)
	{
		medal = FindGO<Medal>("medal");
		//return;
	}

		medal = FindGO<Medal>("medal");

		framecount++;

		Collision();
		Move();

		//�G�`������̍X�V�����B
		modelRender.Update();

		modelRender.SetPosition(position);
		physicsStaticObjectP.SetPosition(position);
		//top->SetPosition(position + COLLISION_HEIGHT);
		//side->SetPosition(position + COLLISION_HEIGHT2);
}

void Pusher::Move()
{
	Vector3 moveSpeed = Vector3::Zero;

	if (m_MovingFloorState == enMovingFloorState_MovingBack)
	{
		moveSpeed.z = SPEED;
	}
	else if (m_MovingFloorState == enMovingFloorState_MovingFront)
	{
		moveSpeed.z = -SPEED;
	}

	position += moveSpeed * g_gameTime->GetFrameDeltaTime();

	if (m_MovingFloorState == enMovingFloorState_MovingBack)
	{

		if (firstPosition.z + LIMITB >= position.z)
		{
			m_MovingFloorState = enMovingFloorState_MovingFront;
			framecount = 0;
		}
	}
	else if (m_MovingFloorState == enMovingFloorState_MovingFront)
	{
		if (firstPosition.z - LIMITA <= position.z)
		{
			m_MovingFloorState = enMovingFloorState_MovingBack;
			framecount = 0;
		}

	}
	
	//�G�`������ɍ��W��������B
	modelRender.SetPosition(position);
}

void Pusher::Collision()
{
	//�V�ʃR���W�����ɓ�������(�������J�n)
	//if (medal != nullptr) {
		//if (top->IsHit(medal->physicsCyllinderObject) == true)
	//	{
	//		//�������̈ړ����x���L�����N�^�[�̈ړ����x�ɉ��Z�B
	//		//MessageBoxA(nullptr, "�v�b�V���[�V�ʂƐڐG���Ă��܂��B", "�m�F", MB_OK);
	//		//medal->AddForce(position+(Vector3(0.0f,30.0f,50.0f)), position);
	//		//medal->AddMoveSpeed(Vector3(0.0f, 0.0f, 10.0f));

	//		////���_���̈ʒu����(�����ʂ�Ȃ瑬�x�n��)
	//		if (medal->position.z > -418.0f) {
	//			//medal->AddForce(position + (Vector3(0.0f, 30.0f, 50.0f)), position);
	//			medal->AddMoveSpeed(position * 1);
	//		}

	//		//�߂荞�����Ƃ����Ƃ��ɒ��ˏグ��
	//		if (medal->position.y <= 0.0f) {
	//			medal->position.y += 0.5f;
	//		}
	//		////�X�e�[�g����(��O�ړ��ő��x�n��)
	//		//else if (m_MovingFloorState == enMovingFloorState_MovingFront) {
	//		//	medal->AddMoveSpeed(position * 1);
	//		//}

	//		////�ǂ̏����ɂ�������Ȃ�������ړ����֎~
	//		//else medal->position.z +=50.0f;
	//		if (medal->position.z <= -60.0f) {
	//			medal->moveSpeed.z += 20.0f;
	//		}
	//	}
	//}
	

		////���ʃR���W�����ɓ�������
		//if (side->IsHit(medal->GetCharacterControllerC()) == true)
		//{
		//	//�������̈ړ����x���L�����N�^�[�̈ړ����x�ɉ��Z�B
		//	//MessageBoxA(nullptr, "�v�b�V���[���ʂƐڐG���Ă��܂��B", "�m�F", MB_OK);
		//	medal->AddMoveSpeed(Vector3(0.0f, 0.0f, 10.0f));
		//	
		//	//���_���̈ʒu����(�����ʂ�Ȃ瑬�x�n��)
		//	if (medal->position.z > -275.0f) {
		//		medal->AddMoveSpeed(position * -1);
		//	}

		//	//�X�e�[�g����(��O�ړ��ő��x�n��)
		//	else if (m_MovingFloorState == enMovingFloorState_MovingFront) {
		//		medal->AddMoveSpeed(position * -1);
		//	}

		//	//�ǂ̏����ɂ�������Ȃ�������ړ����֎~
		//	//else medal->position.z = -420.0f;
		//	else medal->moveSpeed.z += 20.0f;
		//}

		//�G�`������ɍ��W��������B
	modelRender.SetPosition(position);
}

//�`�揈���B
void Pusher::Render(RenderContext& rc)
{
	//���f����`�悷��B
	modelRender.Draw(rc);
}