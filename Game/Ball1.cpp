#include "stdafx.h"
#include "Ball1.h"
#include <time.h>
#include "Bouto.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Ball1::Ball1()
{
	srand((unsigned int)time(NULL));
	modelRender.SetRaytracingWorld(false);
	//ballState = rand() % 2;
	
	//開発用座標
	//position = (Vector3(0.565, 1082.856, 370.404));

	//実装用座標
	position = (Vector3(343.768, 1000.017, -370.369));

	modelRender.Init("Assets/modelData/MEDAL/ballR.tkm");

	physicsSphereObject.CreateCylinder(35.0f,
		position + (Vector3(0.0f, 25.0f, 0.0f)), rotation, 0.2f, 10.0f);
	physicsSphereObject.SetFriction(2.0f);
	ballState = 0;
	SoundSource* se = NewGO<SoundSource>(0);
	se->Init(19);
	se->SetVolume(2.5f);
	se->Play(false);
}

Ball1::~Ball1()
{
	SoundSource* se = NewGO<SoundSource>(0);
	se->Init(22);
	se->SetVolume(2.5f);
	se->Play(false);
	//ballState = 1;
	DeleteGO(this);
}

//更新処理。
void Ball1::Update()
{

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

void Ball1::PlayMusic()
{

}

//描画処理。
void Ball1::Render(RenderContext& rc)
{
	//モデルを描画する。
	modelRender.Draw(rc);
}