#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"

GameClear::GameClear()
{
	//�Q�[���N���A�̉摜��ǂݍ���
	spriteRender.Init("Assets/Sprite/MG_gameclear.dds", 1920.0f, 1080.0f);
	g_soundEngine->ResistWaveFileBank(26, "Assets/sound/MG_gameclear.wav");
	//�Q�[���N���A��BGM���Đ�����B
	titleBGM = NewGO<SoundSource>(0);
	titleBGM->Init(26);
	titleBGM->SetVolume(2.5f);
	titleBGM->Play(true);
}

GameClear::~GameClear()
{

}

//�X�V����
void GameClear::Update()
{
	//A�{�^���������ꂽ��
	if (g_pad[0]->IsTrigger(enButtonA))
	{
	
		DeleteGO(titleBGM);
		//�^�C�g���̃I�u�W�F�N�g�����
		NewGO<Title>(0, "title");
		//���g���폜����
		DeleteGO(this);
	}

}

//�`�揈��
void GameClear::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}