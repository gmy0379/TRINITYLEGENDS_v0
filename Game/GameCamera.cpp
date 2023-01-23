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
	//注視点から視点までのベクトルを設定。
	m_toCameraPos.Set(-150.0f, 600.0f, 1000.0f);
	//プレイヤーのインスタンスを探す。
	medal = FindGO<Medal>("medal");

	/*j1 = FindGO<Rjpc>("j1");
	j2 = FindGO<Ajpc>("j2");
	j3 = FindGO<Pjpc>("j3");*/

	//カメラのニアクリップとファークリップを設定する。
	g_camera3D->SetNear(1.0f);
	g_camera3D->SetFar(10000.0f);

	return true;
}
void GameCamera::Update()
{
	//カメラを更新。
	//注視点を計算する。
	//Vector3 target = medal->position;
	//Vector3 target=Vector3(30.0f,-30.0f,-200.0f);

	//ManageState();

	//target = Vector3(30.0f, 300.0f, -200.0f);

	Vector3 toCameraPosOld = m_toCameraPos;
	//パッドの入力を使ってカメラを回す。
	float x = g_pad[0]->GetRStickXF();
	float y = g_pad[0]->GetRStickYF();
	//Y軸周りの回転
	Quaternion qRot;
	qRot.SetRotationY(200.0f);
	qRot.SetRotationDegY(0.0f);
	qRot.SetRotationDeg(Vector3::AxisY, 1.1f * x);
	qRot.Apply(m_toCameraPos);
	//X軸周りの回転。
	Vector3 axisX;
	axisX.Cross(Vector3::AxisY, m_toCameraPos);
	axisX.Normalize();
	qRot.SetRotationDeg(axisX, 1.1f * y);
	qRot.Apply(m_toCameraPos);
	//カメラの回転の上限をチェックする。
	//注視点から視点までのベクトルを正規化する。
	//正規化すると、ベクトルの大きさが１になる。
	//大きさが１になるということは、ベクトルから強さがなくなり、方向のみの情報となるということ。
	Vector3 toPosDir = m_toCameraPos;
	toPosDir.Normalize();
	//toPosDir.y = 0.5f;
	//カメラの上下制限
	//if (toPosDir.y < 0.3f) {
	//	//カメラが上向きすぎ。
	//	m_toCameraPos = toCameraPosOld;
	//}
	//else if (toPosDir.y > 0.9f) {
	//	//カメラが下向きすぎ。
	//	m_toCameraPos = toCameraPosOld;
	//}

	//カメラの左右制限
	if (toPosDir.x < -0.7f) {
		//カメラが上向きすぎ。
		m_toCameraPos = toCameraPosOld;
	}
	else if (toPosDir.x> 0.7f) {
		//カメラが下向きすぎ。
		m_toCameraPos = toCameraPosOld;
	}

	//カメラの画角を持ってくる。
	float angle = g_camera3D->GetViewAngle();
	//Xボタンが押されたら。
	//if (g_pad[0]->IsPress(enButtonX))
	//{
	//	//画角を加算する。
	//	angle += 0.02f;
	//}
	//if (g_pad[0]->IsPress(enButtonY))
	//{
	//	//画角を減算する。
	//	angle -= 0.02f;
	//}
	g_camera3D->SetViewAngle(angle);

	//視点を計算する。
	Vector3 pos = target + m_toCameraPos;

	//メインカメラに注視点と視点を設定する。
	g_camera3D->SetTarget(target);
	g_camera3D->SetPosition(pos);

	//カメラの更新。
	g_camera3D->Update();

}

//void GameCamera::ManageState()
//{
//	//カメラのステートによって注視点を変更する
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
//		//プッシャーの床からちょっと上を注視点とする。
//		target.x -= 150.0f;
//		target.y += 300.0f;
//		target.z += 150.0f;
//	}
//}