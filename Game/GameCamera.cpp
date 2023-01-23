#include "stdafx.h"
#include "GameCamera.h"
#include "Medal.h"
//#include "Rjpc.h"
//#include "Ajpc.h"
//#include "Pjpc.h"

GameCamera::GameCamera()
{
}


GameCamera::~GameCamera()
{
}
bool GameCamera::Start()
{
	//�����_���王�_�܂ł̃x�N�g����ݒ�B
	m_toCameraPos.Set(-150.0f, 600.0f, 1000.0f);
	//�v���C���[�̃C���X�^���X��T���B
	medal = FindGO<Medal>("medal");

	/*j1 = FindGO<Rjpc>("j1");
	j2 = FindGO<Ajpc>("j2");
	j3 = FindGO<Pjpc>("j3");*/

	//�J�����̃j�A�N���b�v�ƃt�@�[�N���b�v��ݒ肷��B
	g_camera3D->SetNear(1.0f);
	g_camera3D->SetFar(10000.0f);

	return true;
}
void GameCamera::Update()
{
	//�J�������X�V�B
	//�����_���v�Z����B
	//Vector3 target = medal->position;
	//Vector3 target=Vector3(30.0f,-30.0f,-200.0f);

	//ManageState();

	//target = Vector3(30.0f, 300.0f, -200.0f);

	Vector3 toCameraPosOld = m_toCameraPos;
	//�p�b�h�̓��͂��g���ăJ�������񂷁B
	float x = g_pad[0]->GetRStickXF();
	float y = g_pad[0]->GetRStickYF();
	//Y������̉�]
	Quaternion qRot;
	qRot.SetRotationY(200.0f);
	qRot.SetRotationDegY(0.0f);
	qRot.SetRotationDeg(Vector3::AxisY, 1.1f * x);
	qRot.Apply(m_toCameraPos);
	//X������̉�]�B
	Vector3 axisX;
	axisX.Cross(Vector3::AxisY, m_toCameraPos);
	axisX.Normalize();
	qRot.SetRotationDeg(axisX, 1.1f * y);
	qRot.Apply(m_toCameraPos);
	//�J�����̉�]�̏�����`�F�b�N����B
	//�����_���王�_�܂ł̃x�N�g���𐳋K������B
	//���K������ƁA�x�N�g���̑傫�����P�ɂȂ�B
	//�傫�����P�ɂȂ�Ƃ������Ƃ́A�x�N�g�����狭�����Ȃ��Ȃ�A�����݂̂̏��ƂȂ�Ƃ������ƁB
	Vector3 toPosDir = m_toCameraPos;
	toPosDir.Normalize();
	//toPosDir.y = 0.5f;
	//�J�����̏㉺����
	//if (toPosDir.y < 0.3f) {
	//	//�J����������������B
	//	m_toCameraPos = toCameraPosOld;
	//}
	//else if (toPosDir.y > 0.9f) {
	//	//�J�����������������B
	//	m_toCameraPos = toCameraPosOld;
	//}

	//�J�����̍��E����
	if (toPosDir.x < -0.7f) {
		//�J����������������B
		m_toCameraPos = toCameraPosOld;
	}
	else if (toPosDir.x> 0.7f) {
		//�J�����������������B
		m_toCameraPos = toCameraPosOld;
	}

	//�J�����̉�p�������Ă���B
	float angle = g_camera3D->GetViewAngle();
	//X�{�^���������ꂽ��B
	//if (g_pad[0]->IsPress(enButtonX))
	//{
	//	//��p�����Z����B
	//	angle += 0.02f;
	//}
	//if (g_pad[0]->IsPress(enButtonY))
	//{
	//	//��p�����Z����B
	//	angle -= 0.02f;
	//}
	g_camera3D->SetViewAngle(angle);

	//���_���v�Z����B
	Vector3 pos = target + m_toCameraPos;

	//���C���J�����ɒ����_�Ǝ��_��ݒ肷��B
	g_camera3D->SetTarget(target);
	g_camera3D->SetPosition(pos);

	//�J�����̍X�V�B
	g_camera3D->Update();

}

//void GameCamera::ManageState()
//{
//	//�J�����̃X�e�[�g�ɂ���Ē����_��ύX����
//	switch (CamState) {
//	case 1:
//		j1 = FindGO<Rjpc>("j1");
//		if (j1 == nullptr) {
//			j1 = FindGO<Rjpc>("j1");
//			return;
//		}
//		target = j1->position;
//		target.x -= 100.0f;
//		target.y += 300.0f;
//		target.z += 600.0f;
//		break;
//	case 2:
//		j2 = FindGO<Ajpc>("j2");
//		if (j2 == nullptr) {
//			j2 = FindGO<Ajpc>("j2");
//			return;
//		}
//		target = j2->position;
//		break;
//	case 3:
//		j3 = FindGO<Pjpc>("j3");
//		if (j3 == nullptr) {
//			j3 = FindGO<Pjpc>("j3");
//			return;
//		}
//		target = j3->position;
//		break;
//	default:
//		target = Vector3(30.0f, -30.0f, -200.0f);
//		//�v�b�V���[�̏����炿����Ə�𒍎��_�Ƃ���B
//		target.x -= 150.0f;
//		target.y += 300.0f;
//		target.z += 150.0f;
//	}
//}