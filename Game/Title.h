#pragma once
#include "sound/SoundSource.h"

class Choice;
//class Fade;
//�^�C�g���B
class Title : public IGameObject
{
public:
	Title();
	~Title();
	Choice* choice;
	void Update();
	void Render(RenderContext& rc);
	int checkY = 0;
	SpriteRender TITLE;
	SoundSource* titleBGM;			//�^�C�g����BGM�B
	FontRender fontRender;
	int		frame = 0;
	int		st = 0;
	//Fade* m_fade = nullptr;
};

