#pragma once
#include "sound/SoundSource.h"

//�^�C�g���B
class Rule : public IGameObject
{
public:
	Rule();
	~Rule();
	void Update();
	void Render(RenderContext& rc);

	SpriteRender RULE;
	SoundSource* ruleBGM;			//�^�C�g����BGM�B
};

