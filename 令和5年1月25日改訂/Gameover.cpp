#include "stdafx.h"
#include "Gameover.h"
#include "Title.h"

Gameover::Gameover()
{
	//�Q�[���I�[�o�[�̉摜��ǂݍ���
	spriteRender.Init("Assets/Sprite/MG_Gameover.dds", 1920.0f, 1080.0f);
	g_soundEngine->ResistWaveFileBank(17, "Assets/sound/MG_Gameover.wav");
	titleBGM = NewGO<SoundSource>(0);
	titleBGM->Init(17);
	titleBGM->SetVolume(1.5f);
	titleBGM->Play(true);
}

Gameover::~Gameover()
{
	DeleteGO(titleBGM);
}

//�X�V����
void Gameover::Update()
{

	//A�{�^���������ꂽ��
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		//�^�C�g���̃I�u�W�F�N�g�����
		NewGO<Title>(0, "title");
		//���g���폜����
		DeleteGO(this);
	}
}

//�`�揈��
void Gameover::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}
