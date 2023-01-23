#pragma once

class Pusherv2 : public IGameObject
{
public:
	Pusherv2();
	~Pusherv2();
	//�X�V�����B
	void Update();
	void Render(RenderContext& rc);
	//�ړ������B
	void Move();

	FontRender fontRender;
	Vector3 position;			//���W�B
	CharacterController characterController;  //�L�����N�^�[�R���g���[���[�B
	Vector3 moveSpeed;		//�ړ����x�B
	ModelRender modelRender;
	PhysicsStaticObject physicsStaticObject;
};

