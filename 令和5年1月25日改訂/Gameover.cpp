#include "stdafx.h"
#include "Gameover.h"
#include "Title.h"

Gameover::Gameover()
{
	//ゲームオーバーの画像を読み込む
	spriteRender.Init("Assets/Sprite/MG_Gameover.dds", 1920.0f, 1080.0f);
	g_soundEngine->ResistWaveFileBank(17, "Assets/sound/MG_Gameover.wav");
	titleBGM = NewGO<SoundSource>(0);
	titleBGM->Init(17);
	titleBGM->SetVolume(1.5f);
	titleBGM->Play(true);
}

Gameover::~Gameover()
{
	DeleteGO(titleBGM);
}

//更新処理
void Gameover::Update()
{

	//Aボタンが押されたら
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		//タイトルのオブジェクトを作る
		NewGO<Title>(0, "title");
		//自身を削除する
		DeleteGO(this);
	}
}

//描画処理
void Gameover::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}
