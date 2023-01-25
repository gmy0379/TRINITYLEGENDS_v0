#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"

GameClear::GameClear()
{
	//ゲームクリアの画像を読み込む
	spriteRender.Init("Assets/Sprite/MG_gameclear.dds", 1920.0f, 1080.0f);
	g_soundEngine->ResistWaveFileBank(26, "Assets/sound/MG_gameclear.wav");
	//ゲームクリアのBGMを再生する。
	titleBGM = NewGO<SoundSource>(0);
	titleBGM->Init(26);
	titleBGM->SetVolume(2.5f);
	titleBGM->Play(true);
}

GameClear::~GameClear()
{

}

//更新処理
void GameClear::Update()
{
	//Aボタンが押されたら
	if (g_pad[0]->IsTrigger(enButtonA))
	{
	
		DeleteGO(titleBGM);
		//タイトルのオブジェクトを作る
		NewGO<Title>(0, "title");
		//自身を削除する
		DeleteGO(this);
	}

}

//描画処理
void GameClear::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}