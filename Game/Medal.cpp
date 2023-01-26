#include "stdafx.h"
#include "Medal.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"
#include "Counter.h"
#include <time.h>
#include "Choice.h"

float fall = 0.5f;

Medal::Medal()
{
	srand((unsigned int)time(NULL));
	//���f����ǂݍ��ށB
	modelRender.SetRaytracingWorld(false);
	modelRender.Init("Assets/modelData/MEDAL/medalv10.tkm");
	modelRender.SetScale({1.5f,1.2f,1.5f});
	position = (Vector3(rand() % 100 -rand()%350, 370, -440));
	physicsCylinderObject.CreateCylinder({ 40.0f, 4.0f, 40.0f },
		position + (Vector3(0.0f, 40.0f, 0.0f)), rotation, 0.2f, 5.0f);
	physicsCylinderObject.SetFriction(0.35f);

	counter = FindGO<Counter>("counter");
	choice = FindGO<Choice>("choice");

	//���x���ɂ���ē�Փx�𒲐�����(1���Ղ���)
	/*switch (choice->sentaku)
	{
	case 1:
		physicsCylinderObject.CreateCylinder({ 40.0f, 4.0f, 40.0f },
			position + (Vector3(0.0f, 40.0f, 0.0f)), rotation, 0.3f, 5.0f);
		physicsCylinderObject.SetFriction(0.02f);
		GetSentaku = choice->sentaku;
		break;
	case 2:
		physicsCylinderObject.CreateCylinder({ 40.0f, 4.0f, 40.0f },
			position + (Vector3(0.0f, 40.0f, 0.0f)), rotation, 0.3f, 5.0f);
		physicsCylinderObject.SetFriction(0.12f);
		GetSentaku = choice->sentaku;
		break;
	case 3:
		physicsCylinderObject.CreateCylinder({ 40.0f, 4.0f, 40.0f },
			position + (Vector3(0.0f, 40.0f, 0.0f)), rotation, 0.3f, 5.0f);
		physicsCylinderObject.SetFriction(0.22f);
		GetSentaku = choice->sentaku;
		break;
	case 4:
		physicsCylinderObject.CreateCylinder({ 40.0f, 4.0f, 40.0f },
			position + (Vector3(0.0f, 40.0f, 0.0f)), rotation, 0.3f, 5.0f);
		physicsCylinderObject.SetFriction(0.32f);
		GetSentaku = choice->sentaku;
		break;
	case 5:
		physicsCylinderObject.CreateCylinder({ 40.0f, 4.0f, 40.0f },
			position + (Vector3(0.0f, 40.0f, 0.0f)), rotation, 0.3f, 5.0f);
		physicsCylinderObject.SetFriction(0.42f);
		GetSentaku = choice->sentaku;
		break;
	case 6:
		physicsCylinderObject.CreateCylinder({ 40.0f, 4.0f, 40.0f },
			position + (Vector3(0.0f, 40.0f, 0.0f)), rotation, 0.3f, 5.0f);
		physicsCylinderObject.SetFriction(0.52f);
		GetSentaku = choice->sentaku;
		break;
	default:
		physicsCylinderObject.CreateCylinder({ 40.0f, 4.0f, 40.0f },
			position + (Vector3(0.0f, 40.0f, 0.0f)), rotation, 0.3f, 5.0f);
		physicsCylinderObject.SetFriction(0.38f);
		GetSentaku = choice->sentaku;
		break;
	}*/
}

Medal::~Medal()
{
	//DeleteGO(collisionObject);
	DeleteGO(this);
}

//�X�V�����B
void Medal::Update()
{
	//LevelState();

	PlayMusic();
	
	//�J�E���^�[�̉��Z(1�����̃N���𑫂�)
	if (position.y <= -400 && position.y >= -410 && position.z > 300.0f) {
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

	physicsCylinderObject.GetRigidBody()->GetPositionAndRotation(position, rotation);
	modelRender.SetPosition(position);
	modelRender.SetRotation(rotation);

	if (position.z < -290.0f && position.y < 50.0f) {
		counter->Mlost++;
		DeleteGO(this);
	}


	//�G�`������̍X�V�����B
	modelRender.Update();

	
}

//���x���I����ʂŎ󂯎�����ݒ�̔��f
//void Medal::LevelState()
//{
//	switch (GetSentaku)
//	{
//	case 1:
//		physicsCylinderObject.CreateCylinder({ 40.0f, 4.0f, 40.0f },
//			position + (Vector3(0.0f, 40.0f, 0.0f)), rotation, 0.3f, 5.0f);
//		physicsCylinderObject.SetFriction(0.02f);
//		break;
//	case 2:
//		physicsCylinderObject.CreateCylinder({ 40.0f, 4.0f, 40.0f },
//			position + (Vector3(0.0f, 40.0f, 0.0f)), rotation, 0.3f, 5.0f);
//		physicsCylinderObject.SetFriction(0.12f);
//		break;
//	case 3:
//		physicsCylinderObject.CreateCylinder({ 40.0f, 4.0f, 40.0f },
//			position + (Vector3(0.0f, 40.0f, 0.0f)), rotation, 0.3f, 5.0f);
//		physicsCylinderObject.SetFriction(0.22f);
//		break;
//	case 4:
//		physicsCylinderObject.CreateCylinder({ 40.0f, 4.0f, 40.0f },
//			position + (Vector3(0.0f, 40.0f, 0.0f)), rotation, 0.3f, 5.0f);
//		physicsCylinderObject.SetFriction(0.32f);
//		break;
//	case 5:
//		physicsCylinderObject.CreateCylinder({ 40.0f, 4.0f, 40.0f },
//			position + (Vector3(0.0f, 40.0f, 0.0f)), rotation, 0.3f, 5.0f);
//		physicsCylinderObject.SetFriction(0.42f);
//		break;
//	case 6:
//		physicsCylinderObject.CreateCylinder({ 40.0f, 4.0f, 40.0f },
//			position + (Vector3(0.0f, 40.0f, 0.0f)), rotation, 0.3f, 5.0f);
//		physicsCylinderObject.SetFriction(0.52f);
//		break;
//	default:
//		physicsCylinderObject.CreateCylinder({ 40.0f, 4.0f, 40.0f },
//			position + (Vector3(0.0f, 40.0f, 0.0f)), rotation, 0.3f, 5.0f);
//		physicsCylinderObject.SetFriction(0.38f);
//		break;
//	}
//}

//���ʉ��o�͏���
void Medal::PlayMusic()
{

	//���_���̓����y�уJ�E���^�[�̉��Z(1�����̃N���𑫂�)
	if (position.y <= -400&&position.y>=-415&&position.z>300.0f) {
		//�R�C���l������炷
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(18);
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