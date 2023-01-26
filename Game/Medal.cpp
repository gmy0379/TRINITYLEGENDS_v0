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
	//モデルを読み込む。
	modelRender.SetRaytracingWorld(false);
	modelRender.Init("Assets/modelData/MEDAL/medalv10.tkm");
	modelRender.SetScale({1.5f,1.2f,1.5f});
	position = (Vector3(rand() % 100 -rand()%350, 370, -440));
	physicsCylinderObject.CreateCylinder({ 40.0f, 4.0f, 40.0f },
		position + (Vector3(0.0f, 40.0f, 0.0f)), rotation, 0.2f, 5.0f);
	physicsCylinderObject.SetFriction(0.35f);

	counter = FindGO<Counter>("counter");
	choice = FindGO<Choice>("choice");

	//レベルによって難易度を調整する(1が易しい)
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

//更新処理。
void Medal::Update()
{
	//LevelState();

	PlayMusic();
	
	//カウンターの加算(1枚分のクレを足す)
	if (position.y <= -400 && position.y >= -410 && position.z > 300.0f) {
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

	physicsCylinderObject.GetRigidBody()->GetPositionAndRotation(position, rotation);
	modelRender.SetPosition(position);
	modelRender.SetRotation(rotation);

	if (position.z < -290.0f && position.y < 50.0f) {
		counter->Mlost++;
		DeleteGO(this);
	}


	//絵描きさんの更新処理。
	modelRender.Update();

	
}

//レベル選択画面で受け取った設定の反映
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

//効果音出力処理
void Medal::PlayMusic()
{

	//メダルの投下及びカウンターの加算(1枚分のクレを足す)
	if (position.y <= -400&&position.y>=-415&&position.z>300.0f) {
		//コイン獲得音を鳴らす
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(18);
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