#include "stdafx.h"
#include "Pusherv2.h"

Pusherv2::Pusherv2()
{
	//���f����ǂݍ��ށB
	modelRender.Init("Assets/modelData/MEDAL/pusher_daitai.tkm");
	//�L�����R��������������B
	position = (Vector3(-123.992f, 110.747f, -483.082f));
	characterController.Init(3.0f, 10.0f, position);
	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix());
}

Pusherv2::~Pusherv2()
{

}
int moveCount = 0;
float framecount = 0;
//�X�V�����B
void Pusherv2::Update()
{
	framecount++;
	//�ړ������B
	Move();

	//�G�`������̍X�V�����B
	modelRender.Update();
}

void Pusherv2::Move()
{

	switch (moveCount) {
	case 0:
		moveSpeed.z = 90.0f;
		if (framecount == 60) {
			moveCount = 1;
			framecount = 0;
		}
		break;
	case 1:
		moveSpeed.z = -90.0f;
		if (framecount == 60) {
			moveCount = 0;
			framecount = 0;
		}
	}

	//�L�����N�^�[�R���g���[���[���g���č��W���ړ�������B
	position = characterController.Execute(moveSpeed, 1.0f / 60.0f);

	//�G�`������ɍ��W��������B
	modelRender.SetPosition(position);
}

//�`�揈���B
void Pusherv2::Render(RenderContext& rc)
{
	//���f����`�悷��B
	modelRender.Draw(rc);
	//�t�H���g��`�悷��B
	fontRender.Draw(rc);
}