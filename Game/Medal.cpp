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
	//モデルを読み込む。
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

//更新処理。
void Medal::Update()
{
	//Rotation();
	//Move();
	PlayMusic();
	
	//カウンターの加算(1枚分のクレを足す)
	if (position.y <= -400 && position.y >= -415 && position.z > 300.0f) {
		counter->Mcount++;
		counter->Msum++;
		counter->Mget++;
		DeleteGO(this);
	}
	//損失メダルカウンターの加算
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
	//絵描きさんの更新処理。
	modelRender.Update();

	
}

//回転処理
void Medal::Rotation()
{

}

//移動処理
//void Medal::Move()
//{
//	//xzの移動速度。
//	/*moveSpeed.z = 0.0f;
//	moveSpeed.x = 0.0f;*/
//
//
//	position = characterControllerC.Execute(moveSpeed, g_gameTime->GetFrameDeltaTime());
//	//キャラクターコントローラーを使って座標を移動させる。
//	
//	//絵描きさんに座標を教える。
//	modelRender.SetPosition(position);
//
//	//地面に接しているときは重力を切る(接していないときは落下させる)
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
//	//メダルが重なっていたら重ならないようにする
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

//効果音出力処理
void Medal::PlayMusic()
{

	//メダルの投下及びカウンターの加算(1枚分のクレを足す)
	if (position.y <= -400&&position.y>=-415&&position.z>300.0f) {
		//コイン獲得音を鳴らす
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(1);
		se->SetVolume(fall);
		se->Play(false);
	}
}

//描画処理。
void Medal::Render(RenderContext& rc)
{
	//モデルを描画する。
	modelRender.Draw(rc);
}