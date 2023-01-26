#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "sound/SoundEngine.h"
#include "Choice.h"

//#include "Fade.h"

float VOLUME = 70.0f;

Title::Title()
{
	TITLE.Init("Assets/sprite/MG_TITLE.dds", 1920.0f, 1080.0f);

	//タイトル中のBGMを前もって読み込む。
	g_soundEngine->ResistWaveFileBank(1, "Assets/sound/MG_TITLEbgm.wav");

	
	////タイトルのBGMを再生する。
	titleBGM = NewGO<SoundSource>(0);
	titleBGM->Init(1);
	titleBGM->SetVolume(VOLUME/100);
	titleBGM->Play(true);

	//m_fade = FindGO<Fade>("fade");
}

Title::~Title()
{
	//タイトルのBGMを削除する
	DeleteGO(titleBGM);
}

void Title::Update()
{
	if (frame <= 130&&st==0) {
	frame++;
	}

	else if (st==1) {
		frame--;
	}
	
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		/*while (VOLUME == 0.0f) {
			VOLUME=VOLUME - 0.2f;
		}
	
		if(VOLUME<=0.0f){*/
		DeleteGO(titleBGM);
		NewGO<Choice>(0, "choice");
		DeleteGO(this);
		//}


	}

	//表示するテキストを設定。
	fontRender.SetText(L"PRESS A BUTTON");
	fontRender.SetPosition(Vector3(-650.0f, -100.0f, 0.0f));
	fontRender.SetScale(4.0f);
	fontRender.SetShadowParam(true, 0.3f, Vector4(1.0f, 1.0f, 0.0f, 0.4f));

	//フォントのイン・アウト
	if (frame <= 10)fontRender.SetColor(1.0f, 0.0f, 0.0f, 1.0f);
	else if (frame <= 20 && frame > 10)
	{
		fontRender.SetColor(0.9f, 0.0f, 0.0f, 0.9f);
	}
	else if (frame <= 30 && frame > 20)
	{
		fontRender.SetColor(0.8f, 0.0f, 0.0f, 0.8f);
	}
	else if (frame <= 40 && frame > 30)
	{
		fontRender.SetColor(0.7f, 0.0f, 0.0f, 0.7f);
	}
	else if (frame <= 50 && frame > 40)
	{
		fontRender.SetColor(0.6f, 0.0f, 0.0f, 0.6f);
	}
	else if (frame <= 60 && frame > 50)
	{
		fontRender.SetColor(0.5f, 0.0f, 0.0f, 0.5f);
	}
	else if (frame <= 70 && frame > 60)
	{
		fontRender.SetColor(0.4f, 0.0f, 0.0f, 0.4f);
	}
	else if (frame <= 80 && frame > 70)
	{
		fontRender.SetColor(0.3f, 0.0f, 0.0f, 0.3f);
	}
	else if (frame <= 90 && frame > 80)
	{
		fontRender.SetColor(0.2f, 0.0f, 0.0f, 0.2f);
	}
	else if (frame <= 100 && frame > 90)
	{
		fontRender.SetColor(0.1f, 0.0f, 0.0f, 0.1f);
	}
	else if (frame > 100)
	{
		fontRender.SetColor(0.0f, 0.0f, 0.0f, 0.0f);
	}
	if (frame >= 130)
	{
		st = 1;
	}
	if (frame <= 0)
	{
		st = 0;
	}

	//画像の更新。
	TITLE.Update();
}

void Title::Render(RenderContext& rc)
{
	TITLE.Draw(rc);
	fontRender.Draw(rc);
	
}