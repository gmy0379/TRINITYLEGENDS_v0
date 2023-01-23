#include "stdafx.h"
#include "Medal.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"
#include "Counter.h"
#include <time.h>

float fall = 0.5f;

Medal::Medal()
{
	srand((unsigned int)time(NULL));
	//���f����ǂݍ��ށB
	modelRender.SetRaytracingWorld(false);
	modelRender.Init("Assets/modelData/MEDAL/medalv10.tkm");
	modelRender.SetScale({1.5f,1.2f,1.5f});
	position = (Vector3(rand() % 100 -rand()%350, 370, -480));
	g_soundEngine->ResistWaveFileBank(1, "Assets/sound/medalGET.wav");
	g_soundEngine->ResistWaveFileBank(2, "Assets/sound/m_fall.wav");

	counter = FindGO<Counter>("counter");

	physicsCylinderObject.CreateCylinder({ 40.0f, 4.0f, 40.0f },
		position +(Vector3(0.0f,40.0f,0.0f)), rotation, 0.3f, 5.0f);
	physicsCylinderObject.SetFriction(0.62f);
}

Medal::~Medal()
{
	DeleteGO(collisionObject);
	DeleteGO(this);
}

//�X�V�����B
void Medal::Update()
{
	//Rotation();
	//Move();
	PlayMusic();
	
	//�J�E���^�[�̉��Z(1�����̃N���𑫂�)
	if (position.y <= -400 && position.y >= -415 && position.z > 300.0f) {
		counter->Mcount++;
		counter->Msum++;
		counter->Mget++;
		DeleteGO(this);
	}
	//�������_���J�E���^�[�̉��Z
	else if (position.y <= -100 && position.y >= -115 && position.z <= 300.0f) {
		counter->Mlost++;
		DeleteGO(this);
	}

	/*Vector3 Vel = physicsCylinderObject.GetRigidBody()->GetLinearVelocity();

	Vel.x = min(Vel.x, 5000.0f);
	Vel.y = min(Vel.y, 5000.0f);
	Vel.z = min(Vel.z, 5000.0f);
	Vel.x = max(Vel.x, -5000.0f);
	Vel.y = max(Vel.y, -5000.0f);
	Vel.z = max(Vel.z, -5000.0f);

	physicsCylinderObject.GetRigidBody()->SetLinearVelocity(Vel);*/

	physicsCylinderObject.GetRigidBody()->GetPositionAndRotation(position, rotation);
	modelRender.SetPosition(position);
	modelRender.SetRotation(rotation);

	if (position.z < -290.0f && position.y < 50.0f) {
		counter->Mlost++;
		DeleteGO(this);
	}

	//collisionObject->SetPosition(position);
	//collisionObject->SetRotation(rotation);
	//moveSpeed.y *= 1.02f;
	//�G�`������̍X�V�����B
	modelRender.Update();

	
}

//��]����
void Medal::Rotation()
{

}

//�ړ�����
//void Medal::Move()
//{
//	//xz�̈ړ����x�B
//	/*moveSpeed.z = 0.0f;
//	moveSpeed.x = 0.0f;*/
//
//
//	position = characterControllerC.Execute(moveSpeed, g_gameTime->GetFrameDeltaTime());
//	//�L�����N�^�[�R���g���[���[���g���č��W���ړ�������B
//	
//	//�G�`������ɍ��W��������B
//	modelRender.SetPosition(position);
//
//	//�n�ʂɐڂ��Ă���Ƃ��͏d�͂�؂�(�ڂ��Ă��Ȃ��Ƃ��͗���������)
//	if (characterControllerC.IsOnGround()) {
//		moveSpeed.y = 0.0f;
//	}
//	else if(position.z<315.0f){
//		moveSpeed.y -= 9.8f;
//		moveSpeed.z = 10.0f;
//	}
//	else {
//		moveSpeed.y -= 9.8f;
//	}
//	/*if (position.z < -425.0f) {
//		moveSpeed.z = 0.0f;
//	}*/
//
//	//���_�����d�Ȃ��Ă�����d�Ȃ�Ȃ��悤�ɂ���
//	if (collisionObject->IsHit(GetCharacterControllerC()) == true)
//	{
//		while (collisionObject->IsHit(GetCharacterControllerC()) == false)
//			moveSpeed.x += (rand() % 8);
//			moveSpeed.y += (rand() % 8);
//			moveSpeed.z += (rand() % 8);
//	}
//
//	moveSpeed.x = 0.0f;
//	moveSpeed.z = 1.0f;
//}

//���ʉ��o�͏���
void Medal::PlayMusic()
{

	//���_���̓����y�уJ�E���^�[�̉��Z(1�����̃N���𑫂�)
	if (position.y <= -400&&position.y>=-415&&position.z>300.0f) {
		//�R�C���l������炷
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(1);
		se->SetVolume(fall);
		se->Play(false);
	}
}

//�`�揈���B
void Medal::Render(RenderContext& rc)
{
	//���f����`�悷��B
	modelRender.Draw(rc);
}