#include "stdafx.h"
#include "Rule.h"
#include "Game.h"
#include "sound/SoundEngine.h"
#include "Choice.h"

Rule::Rule()
{
	//ルール説明
	RULE.Init("Assets/sprite/MG_Rule1.dds", 1920.0f, 1080.0f);

	//ルールBGM
	g_soundEngine->ResistWaveFileBank(16, "Assets/sound/MG_Rule.wav");
	//ルールのBGMを再生する。
	ruleBGM = NewGO<SoundSource>(0);
	ruleBGM->Init(16);
	ruleBGM->Play(true);
}

Rule::~Rule()
{
}

void Rule::Update()
{
	
}

void Rule::Render(RenderContext& rc)
{
	RULE.Draw(rc);
}