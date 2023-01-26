#include "stdafx.h"
#include "Ball2.h"
#include <time.h>
#include "Bouto.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Ball2::Ball2()
{
	g_soundEngine->ResistWaveFileBank(20, "Assets/sound/aquafall.wav");

	srand((unsigned int)time(NULL));
	modelRender.SetRaytracingWorld(false);

	//開発用座標
	//position = (Vector3(0.565, 1082.856, 370.404));

	//実装用座標
	position = (Vector3(343.768, 1000.017, -360.369));
	modelRender.Init("Assets/modelData/MEDAL/BallA.tkm");

	physicsSphereObject.CreateCylinder(35.0f,
		position + (Vector3(0.0f, 25.0f, 0.0f)), rotation, 0.3f, 12.0f);
	physicsSphereObject.SetFriction(3.0f);
	ballState = 0;
	SoundSource* se = NewGO<SoundSource>(0);
	se->Init(20);
	se->SetVolume(2.5f);
	se->Play(false);
}

Ball2::~Ball2()
{
	SoundSource* se = NewGO<SoundSource>(0);
	se->Init(22);
	se->SetVolume(2.5f);
	se->Play(false);
	DeleteGO(this);
}

//更新処理。
void Ball2::Update()
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

void Ball2::PlayMusic()
{

}

//描画処理。
void Ball2::Render(RenderContext& rc)
{
	//モデルを描画する。
	modelRender.Draw(rc);
}