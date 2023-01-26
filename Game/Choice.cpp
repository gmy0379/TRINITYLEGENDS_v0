#include "stdafx.h"
#include "Choice.h"
#include "sound/SoundEngine.h"
#include "TItle.h"
#include "Game.h"

float VOLch = 2.0f;

Choice::Choice()
{
	//�w�i��p�ӂ���
	Levelselect.Init("Assets/sprite/MG_Level.dds", 1920.0f, 1080.0f);
	//�I����
	g_soundEngine->ResistWaveFileBank(2, "Assets/sound/updown.wav");
	g_soundEngine->ResistWaveFileBank(3, "Assets/sound/kettei.wav");
	g_soundEngine->ResistWaveFileBank(4, "Assets/sound/MG_choiceBGM.wav");
	//���[����BGM���Đ�����B
	choiceBGM = NewGO<SoundSource>(0);
	choiceBGM->Init(4);
	choiceBGM->SetVolume(VOLch);
	choiceBGM->Play(true);
	game = FindGO<Game>("game");
}

Choice::~Choice()
{
	DeleteGO(choiceBGM);
}

void Choice::Update()
{
		//�����̃��x����I��
		if (sentaku < 6) {
			if (g_pad[0]->IsTrigger(enButtonUp))
			{
				SoundSource* se = NewGO<SoundSource>(0);
				se->Init(2);
				se->SetVolume(1.7f);
				se->Play(false);
				sentaku++;
			}
		}
		if (sentaku > 1) {
			if (g_pad[0]->IsTrigger(enButtonDown))
			{
				SoundSource* se = NewGO<SoundSource>(0);
				se->Init(2);
				se->SetVolume(1.5f);
				se->Play(false);
				sentaku--;
			}
		}

		if (g_pad[0]->IsTrigger(enButtonStart)&& st==0) {
			SoundSource* se = NewGO<SoundSource>(0);
			se->Init(3);
			se->SetVolume(1.5f);
			se->Play(false);
			while (VOLch == 0) {
				VOLch -= 0.04f;
			}
			st = 1;
			DeleteGO(choiceBGM);
			fontRender.SetColor(0.0f, 0.0f, 0.0f, 0.0f);
			fontRender.SetShadowParam(false,0.0f,Vector4(0,0,0,0));
			NewGO<Game>(0, "game");
		}
		if(st==0)
		{
			//�^�C���v��
			wchar_t wcsbuf[256];
			swprintf_s(wcsbuf, 256, L"���x�� %d", sentaku);

			//�\������e�L�X�g��ݒ�B
			fontRender.SetText(wcsbuf);
			//�t�H���g�̈ʒu��ݒ�B
			fontRender.SetPosition(Vector3(-300.0f, -170.0f, 0.0f));
			//�t�H���g�̑傫����ݒ�B
			fontRender.SetScale(3.5f);
			fontRender.SetShadowParam(true, 0.2f, Vector4(0.0f, 0.0f, 0.0f, 1.0f));
			if (sentaku == 1)
			{
				fontRender.SetColor(0.0f, 1.0f, 0.0f, 1.0f);
			}
			else if (sentaku == 2)
			{
				fontRender.SetColor(0.8f, 1.0f, 0.0f, 1.0f);
			}
			else if (sentaku == 3)
			{
				fontRender.SetColor(1.0f, 1.0f, 0.0f, 1.0f);
			}
			else if (sentaku == 4)
			{
				fontRender.SetColor(1.0f, 0.8f, 0.0f, 1.0f);
			}
			else if (sentaku == 5)
			{
				fontRender.SetColor(1.0f, 0.5f, 0.0f, 1.0f);
			}
			else if (sentaku == 6)
			{
				fontRender.SetColor(1.0f, 0.0f, 0.0f, 1.0f);
			}
		}
		if (game == nullptr)
		{
			game = FindGO<Game>("game");
			return;
		}

		if (game->timer == 0) {
			DeleteGO(this);
		}

		/*if (yokoana!=nullptr) {
			DeleteGO(this);
		}*/

}

void Choice::Render(RenderContext& rc)
{	
	Levelselect.Draw(rc);
	fontRender.Draw(rc);

}