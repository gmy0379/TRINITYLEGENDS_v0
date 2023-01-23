#pragma once
#include <physics/PhysicsStaticObjectP.h>

class Medal;
class Pusher : public IGameObject
{
public:
	
	Pusher();
	~Pusher();
	//�X�V�����B
	void Update();
	void Render(RenderContext& rc);
	void SetPosition(const Vector3& pos)
	{
		 position = pos;
	}
	Vector3 position;			//���W

private:
	//�ړ������B
	void Move();
	//�����蔻�菈��
	//�����蔻��̏���
	void Collision();

	Medal* medal = nullptr;
	CollisionObject* top = nullptr;		//�V�ʃR���W�����I�u�W�F�N�g�B
	//CollisionObject* side = nullptr;		//���ʃR���W�����I�u�W�F�N�g�B
	
	Vector3	firstPosition;	//�������W
	Vector3 moveVec;		// �ړ��x�N�g��
	Vector3 moveSpeed=Vector3::Zero;	//�ړ����x

	ModelRender modelRender;
	PhysicsStaticObjectP physicsStaticObjectP;

	enum enMovingFloorState
	{
		enMovingFloorState_MovingBack,
		enMovingFloorState_MovingFront
	};
	enMovingFloorState		m_MovingFloorState = enMovingFloorState_MovingBack;
};


