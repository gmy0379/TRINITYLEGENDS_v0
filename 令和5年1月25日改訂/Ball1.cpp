#include "stdafx.h"
#include "Ball1.h"
#include <time.h>
#include "Bouto.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Ball1::Ball1()
{
	g_soundEngine->ResistWaveFileBank(22, "Assets/sound/rubyfall.wav");
	g_soundEngine->ResistWaveFileBank(29, "Assets/sound/ballget.wav");
	srand((unsigned int)time(NULL));
	modelRender.SetRaytracingWorld(false);
	//ballState = rand() % 2;
	//position = (Vector3(0.565, 1082.856, 330.404));
	position = (Vector3(343.768, 1000.017, -370.369));
	modelRender.Init("Assets/modelData/MEDAL/ballR.tkm");
	//modelRender.Init("Assets/modelData/MEDAL/PR/not.tkm");

	physicsSphereObject.CreateCylinder(35.0f,
		position + (Vector3(0.0f, 25.0f, 0.0f)), rotation, 0.7f, 13.0f);
	physicsSphereObject.SetFriction(2.0f);
	ballState = 0;
	SoundSource* se = NewGO<SoundSource>(0);
	se->Init(22);
	se->SetVolume(2.5f);
	se->Play(false);
}

Ball1::~Ball1()
{
	SoundSource* se = NewGO<SoundSource>(0);
	se->Init(29);
	se->SetVolume(2.5f);
	se->Play(false);
	ballState = 1;
	DeleteGO(this);
}

//更新処理。
void Ball1::Update()
{
	//Rotation();
	//移動処理。
	//Move();
	//ManageState();

	if (position.y <= -400.0f && position.y >= -415.0f) {
		ballState = 1;
		//DeleteGO(this);
		//MessageBoxA(nullptr, "ボールを消去します", "確認", MB_OK);
	}

	physicsSphereObject.GetRigidBody()->GetPositionAndRotation(position, rotation);
	modelRender.SetPosition(position);
	modelRender.SetRotation(rotation);

	//絵描きさんの更新処理。
	modelRender.Update();
}

//void Ball1::ManageState()
//{
//	//ballStateによって投下するボールを変更する
//	switch (ballState)
//	{
//		ballState = rand() % 3;
//	case 0:
//		//RJPに向かうためのボールを読み込む。
//		modelRender.SetRaytracingWorld(false);
//		//position = (Vector3(424.565, 1052.856, -220.404));
//		position = { 424.0f,200.0f,-145.404f };
//		modelRender.Init("Assets/modelData/MEDAL/ballR.tkm");
//
//		physicsSphereObject.CreateCylinder(35.0f,
//			position + (Vector3(0.0f, 25.0f, 0.0f)), rotation, 0.1f, 10.0f);
//		physicsSphereObject.SetFriction(4.0f);
//		ballState = 0;
//
//	case 1:
//		//AJPに向かうためのボールを読み込む。
//		modelRender.SetRaytracingWorld(false);
//		//position = (Vector3(424.565, 1052.856, -220.404));
//		position = { 424.0f,200.0f,-145.404f };
//		modelRender.Init("Assets/modelData/MEDAL/ballA.tkm");
//
//		physicsSphereObject.CreateCylinder(35.0f,
//			position + (Vector3(0.0f, 25.0f, 0.0f)), rotation, 0.1f, 1300.0f);
//		physicsSphereObject.SetFriction(10.0f);
//		ballState = 0;
//		break;
//
//	case 2:
//		//RJPに向かうためのボールを読み込む。
//		modelRender.SetRaytracingWorld(false);
//		//position = (Vector3(424.565, 1052.856, -220.404));
//		position = { 424.0f,200.0f,-145.404f };
//		modelRender.Init("Assets/modelData/MEDAL/ballR.tkm");
//
//		physicsSphereObject.CreateCylinder(35.0f,
//			position + (Vector3(0.0f, 25.0f, 0.0f)), rotation, 0.1f, 1300.0f);
//		physicsSphereObject.SetFriction(10.0f);
//		ballState = 0;
//
//	default:
//		break;
//	}
//}

//void Ball::Move()
//{
//	//xzの移動速度を0.0fにする。
//	moveSpeed.x = 0.0f;
//	moveSpeed.z = 0.0f;
//
//		//重力を発生させる。
//		moveSpeed.y -= 0.001f;
//
//		float mx = moveSpeed.x;
//		float my = moveSpeed.y;
//		float mz = moveSpeed.z;
//
//	//キャラクターコントローラーを使って座標を移動させる。
//	position = characterController.Execute(moveSpeed, 1.0f / 60.0f);
//	
//	if (characterController.IsOnGround()&&position.y<500.0f) {
//		//地面についた。
//		moveSpeed.y = 0.0f;
//		moveSpeed.z = -100.0f;
//	}
//
//	//絵描きさんに座標を教える。
//	modelRender.SetPosition(position);
//}

//void Ball::Rotation()
//{
//	if (moveSpeed.x != 0) {
//		rotation.AddRotationDegX(mx *= 1.5);
//	}
//	else { rotation.AddRotationDegX(0.0f);
//	}
//	if (moveSpeed.y < 0) {
//		rotation.AddRotationDegZ(my *= 10);
//	}
//	else { rotation.AddRotationDegZ(0.0f);
//	}
//	if (moveSpeed.z != 0) {
//		rotation.AddRotationDegZ(mz *= 1.5);
//	}
//	else { rotation.AddRotationDegZ(0.0f);
//	}
//	modelRender.SetRotation(rotation);
//}

void Ball1::PlayMusic()
{

}

//描画処理。
void Ball1::Render(RenderContext& rc)
{
	//モデルを描画する。
	modelRender.Draw(rc);
}