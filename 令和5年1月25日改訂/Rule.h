#pragma once
#include "sound/SoundSource.h"

//タイトル。
class Rule : public IGameObject
{
public:
	Rule();
	~Rule();
	void Update();
	void Render(RenderContext& rc);

	SpriteRender RULE;
	SoundSource* ruleBGM;			//タイトルのBGM。
};

