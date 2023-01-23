#include "stdafx.h"
#include "Ball2.h"
#include <time.h>
#include "Bouto.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Ball2::Ball2()
{
	g_soundEngine->ResistWaveFileBank(23, "Assets/sound/aquafall.wav");
	g_soundEngine->ResistWaveFileBank(25, "Assets/sound/ballget.wav");
	srand((unsigned int)time(NULL));
	modelRender.SetRaytracingWorld(false);
	//position = (Vector3(0.565, 1082.856, 330.404));
	position = (Vector3(343.768, 1000.017, -360.369));
	modelRender.Init("Assets/modelData/MEDAL/BallA.tkm");
	//modelRender.Init("Assets/modelData/MEDAL/PR/not.tkm");

	physicsSphereObject.CreateCylinder(35.0f,
		position + (Vector3(0.0f, 25.0f, 0.0f)), rotation, 0.3f, 130.0f);
	physicsSphereObject.SetFriction(3.0f);
	BallState = 0;
	SoundSource* se = NewGO<SoundSource>(0);
	se->Init(23);
	se->SetVolume(2.5f);
	se->Play(false);
}

Ball2::~Ball2()
{
	SoundSource* se = NewGO<SoundSource>(0);
	se->Init(25);
	se->SetVolume(2.5f);
	se->Play(false);
	DeleteGO(this);
}

//更新処理。
void Ball2::Update()
{
	//Rotation();
	//移動処理。
	//Move();
	//ManageState();
	if (position.y <= -400.0f && position.y >= -415.0f) {
		BallState = 1;
		//DeleteGO(this);
	}

	physicsSphereObject.GetRigidBody()->GetPositionAndRotation(position, rotation);
	modelRender.SetPosition(position);
	modelRender.SetRotation(rotation);

	//絵描きさんの更新処理。
	modelRender.Update();
}

//void Ball2::ManageState()
//{
//	//Ball2Stateによって投下するボールを変更する
//	switch (BallState)
//	{
//		Ball2State = rand() % 3;
//	case 0:
//		//RJPに向かうためのボールを読み込む。
//		modelRender.SetRaytracingWorld(false);
//		//position = (Vector3(424.565, 1052.856, -220.404));
//		position = { 424.0f,200.0f,-145.404f };
//		modelRender.Init("Assets/modelData/MEDAL/BallR.tkm");
//
//		physicsSphereObject.CreateCylinder(35.0f,
//			position + (Vector3(0.0f, 25.0f, 0.0f)), rotation, 0.1f, 10.0f);
//		physicsSphereObject.SetFriction(4.0f);
//		Ball2State = 0;
//
//	case 1:
//		//AJPに向かうためのボールを読み込む。
//		modelRender.SetRaytracingWorld(false);
//		//position = (Vector3(424.565, 1052.856, -220.404));
//		position = { 424.0f,200.0f,-145.404f };
//		modelRender.Init("Assets/modelData/MEDAL/Ball2A.tkm");
//
//		physicsSphereObject.CreateCylinder(35.0f,
//			position + (Vector3(0.0f, 25.0f, 0.0f)), rotation, 0.1f, 1300.0f);
//		physicsSphereObject.SetFriction(10.0f);
//		Ball2State = 0;
//		break;
//
//	case 2:
//		//RJPに向かうためのボールを読み込む。
//		modelRender.SetRaytracingWorld(false);
//		//position = (Vector3(424.565, 1052.856, -220.404));
//		position = { 424.0f,200.0f,-145.404f };
//		modelRender.Init("Assets/modelData/MEDAL/Ball2R.tkm");
//
//		physicsSphereObject.CreateCylinder(35.0f,
//			position + (Vector3(0.0f, 25.0f, 0.0f)), rotation, 0.1f, 1300.0f);
//		physicsSphereObject.SetFriction(10.0f);
//		Ball2State = 0;
//
//	default:
//		break;
//	}
//}

//void Ball2::Move()
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

//void Ball2::Rotation()
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

void Ball2::PlayMusic()
{

}

//描画処理。
void Ball2::Render(RenderContext& rc)
{
	//モデルを描画する。
	modelRender.Draw(rc);
}