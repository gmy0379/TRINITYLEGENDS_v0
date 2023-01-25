#include "stdafx.h"
#include "Counter.h"
#include "Medal.h"
//#include "Text.h"
#include "Game.h"
#include "Gameover.h"

Counter::Counter()
{
	medal = FindGO<Medal>("medal");
	game = FindGO<Game>("game");
	//text = FindGO<Text>("text");
}

Counter::~Counter()
{
}

void Counter::Update()
{
	PO =  Mget/ Mfall*100.0f;
	/*if (PO <= 0.0f)
		PO = 0.0f;
	else if (PO >= 100.0f)
		PO = 100.0f;*/
	//���_�������\��

	wchar_t wcsbuf[256];
	swprintf_s(wcsbuf, 256, L"���_������ %g",Mcount);
	
	//�\������e�L�X�g��ݒ�B
	fontRender.SetText(wcsbuf);
	fontRender.SetShadowParam(true, 0.3f, Vector4(0.0f, 0.0f, 0.0f, 0.6f));
	//�t�H���g�̈ʒu��ݒ�B
	fontRender.SetPosition(Vector3(150.0f, 500.0f, 0.0f));
	//�t�H���g�̑傫����ݒ�B
	fontRender.SetScale(2.0f);

	if (Mcount < 1) {
		textchange++;
		End++;
		if (textchange > 0 && textchange <= 25) {
			fontRender.SetColor(1.0f, 0.0f, 0.0f, 1.0f);
		}
		else if (textchange > 25 && textchange <= 50) {
			fontRender.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
		}
		if (textchange > 50) {
			textchange = 0;
		}
	}
	else if (Mcount > 10000) {
		clear = 1;
	}
	else {
		fontRender.SetColor(0.0f, 0.0f, 1.0f, 1.0f);
		End = 0;
	}
}

void Counter::Render(RenderContext& rc)
{
	//�t�H���g��`�悷��B
	fontRender.Draw(rc);
}