#pragma once
#include "sound/SoundSource.h"

class Choice;
//class Fade;
//タイトル。
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
	SoundSource* titleBGM;			//タイトルのBGM。
	FontRender fontRender;
	int		frame = 0;
	int		st = 0;
	//Fade* m_fade = nullptr;
};

