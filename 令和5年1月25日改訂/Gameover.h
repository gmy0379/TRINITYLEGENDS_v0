#pragma once

//�Q�[���N���A
class Gameover :public IGameObject
{
public:
	Gameover();
	~Gameover();
	//�X�V����
	void Update();
	//�`�揈��
	void Render(RenderContext& rc);

	//�����o�ϐ�	
	SpriteRender spriteRender;   //�X�v���C�g�����_�[
	SoundSource* titleBGM;			//�^�C�g����BGM�B
};