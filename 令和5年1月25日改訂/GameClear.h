#pragma once
#include "sound/SoundSource.h"

class game;
//�Q�[���N���A
class GameClear:public IGameObject
{
public:
	GameClear();
	~GameClear();
	//�X�V����
	void Update();
	//�`�揈��
	void Render(RenderContext& rc);

	//�����o�ϐ�	
	SpriteRender spriteRender;   //�X�v���C�g�����_�[
	SoundSource* titleBGM;			//�^�C�g����BGM�B
	FontRender* fontRender;
};

