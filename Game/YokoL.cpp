#include "stdafx.h"
#include "YokoL.h"

YokoL::YokoL()
{
	//���f����ǂݍ��ށB
	modelRender.Init("Assets/modelData/MEDAL/yokoanaL.tkm");
	//�L�����R��������������B
	position = (Vector3(-400.758f, -46.954f, -260.934f));
	characterController.Init(3.0f, 10.0f, position);
}

YokoL::~YokoL()
{

}
//�X�V�����B
void YokoL::Update()
{
	//�ړ������B
	Move();

	//�G�`������̍X�V�����B
	modelRender.Update();
}

void YokoL::Move()
{

	//�L�����N�^�[�R���g���[���[���g���č��W���ړ�������B
	position = characterController.Execute(moveSpeed, 1.0f / 60.0f);

	//�G�`������ɍ��W��������B
	modelRender.SetPosition(position);
}

//�`�揈���B
void YokoL::Render(RenderContext& rc)
{
	//���f����`�悷��B
	modelRender.Draw(rc);
	//�t�H���g��`�悷��B
	fontRender.Draw(rc);
}
