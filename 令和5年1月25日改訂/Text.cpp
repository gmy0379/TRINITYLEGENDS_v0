#include "stdafx.h"
#include "Text.h"
#include "Game.h"
#include "Counter.h"
#include <iostream>

Text::Text()
{
	counter = FindGO<Counter>("counter");
	game = FindGO<Game>("game");
}

Text::~Text()
{

}

void Text::Update()
{
	if (game == nullptr) {
		game = FindGO<Game>("game");
		return;
	}
	/*if (game->GameState == 1 || game->GameState == 2 || game->GameState == 3) {
		State = 1;
	}
	else {
		State = 0;
	}*/
	fcount++;
	ManageState();
//JP枚数計測
wchar_t wcsbuf[256];
if (fcount < 250) {
swprintf_s(wcsbuf, 256, L"ルビーJP枚数 %g",RJP+(addR/57.3));
fontRender.SetColor(1.0f, 0.0f, 1.0f, 1.0f);
fontRender.SetShadowParam(true, 1.0f, Vector4(0.0f, 0.0f, 0.0f, 1.0f));
}

else if (fcount >= 250 && fcount < 400)
{
swprintf_s(wcsbuf, 256, L"アクアマリンJP枚数 %g", AJP + (addA / 57.3));
fontRender.SetColor(0.2f, 0.2f, 0.8f, 1.0f);
fontRender.SetShadowParam(true, 0.6f, Vector4(0.0f, 0.0f, 0.0f, 0.4f));
}

else 
{
swprintf_s(wcsbuf, 256, L"パイライトJP枚数 %g", PJP + (addP / 57.3));
fontRender.SetColor(1.0f, 0.7f, 0.0f, 1.0f);
fontRender.SetShadowParam(true, 0.6f, Vector4(0.0f, 0.0f, 0.0f, 0.4f));
}

float rjpc = (RJP + addR);

if (g_pad[0]->IsTrigger(enButtonA))
{
	addR += 0.06f;
	addA += 0.07f;
}

//addR += g_gameTime->GetFrameDeltaTime();
//addA += g_gameTime->GetFrameDeltaTime()*1.2;
//addP += g_gameTime->GetFrameDeltaTime()*6.5;

if (RJP >= 2999.99f) {
	RJP = 3000.0f;
}

if (AJP >= 4999.99f) {
	AJP = 5000.0f;
}

if (PJP >= 9999.99f) {
	PJP = 10000.0f;
}

//表示するテキストを設定。
fontRender.SetText(wcsbuf);
//フォントの位置を設定。
//fontRender.SetPosition(Vector3(180.0f, 400.0f, 0.0f));
//fontRender.SetPosition(Vector3(-200.0f, 300.0f, 0.0f));
fontRender.SetPosition(Vector3(-900.0f, 200.0f, 0.0f));
//フォントの大きさを設定。
fontRender.SetScale(1.0f);

if (fcount > 573)
fcount = 0;
}

void Text::ManageState()
{
	switch (State)
	{
	case 1:
		addR += g_gameTime->GetFrameDeltaTime() * 0;
		addA += g_gameTime->GetFrameDeltaTime() * 0;
		addP += g_gameTime->GetFrameDeltaTime() * 0;
		break;
	default:
		float rjpc = (RJP + addR);

		addR += g_gameTime->GetFrameDeltaTime();
		addA += g_gameTime->GetFrameDeltaTime() * 1.2f;
		addP += g_gameTime->GetFrameDeltaTime() * 6.5f;
		break;
	}
}

void Text::Render(RenderContext& rc)
{
	fontRender.Draw(rc);
}

