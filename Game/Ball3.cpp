#include "stdafx.h"
#include "Ball3.h"
#include <time.h>
#include "Bouto.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Ball3::Ball3()
{
	g_soundEngine->ResistWaveFileBank(24, "Assets/sound/premiumfall.wav");
	g_soundEngine->ResistWaveFileBank(31, "Assets/sound/ballget.wav");
	modelRender.SetRaytracingWorld(false);
	//開発用座標
	position = (Vector3(0.565, 1082.856, 370.404));

	//実装用座標
	//position = (Vector3(343.768, 1000.017, -350.369));
	modelRender.Init("Assets/modelData/MEDAL/Ball4.tkm");
	//modelRender.Init("Assets/modelData/MEDAL/PR/not.tkm");

	physicsSphereObject.CreateCylinder(35.0f,
		position + (Vector3(0.0f, 25.0f, 0.0f)), rotation, 0.1f, 17.0f);
	physicsSphereObject.SetFriction(3.6f);
	ballState = 0;
	SoundSource* se = NewGO<SoundSource>(0);
	se->Init(24);
	se->SetVolume(2.5f);
	se->Play(false);
}

Ball3::~Ball3()
{
	SoundSource* se = NewGO<SoundSource>(0);
	se->Init(31);
	se->SetVolume(1.5f);
	se->Play(false);
	DeleteGO(this);
}

//更新処理。
void Ball3::Update()
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

void Ball3::PlayMusic()
{

}

//描画処理。
void Ball3::Render(RenderContext& rc)
{
	//モデルを描画する。
	modelRender.Draw(rc);
}