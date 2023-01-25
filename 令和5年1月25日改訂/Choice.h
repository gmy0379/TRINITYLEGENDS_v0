#pragma once
#include "sound/SoundSource.h"
class Game;
class Yokoana;
//�^�C�g���B
class Choice : public IGameObject
{
public:
	Choice();
	~Choice();
	void Update();
	void Render(RenderContext& rc);
	Game*game=nullptr;
	Yokoana*yokoana=nullptr;
	SpriteRender Levelselect;
	FontRender fontRender;
	SoundSource* choiceBGM;			//�I����ʂ�BGM�B
	int sentaku = 3;
	int st = 0;
};