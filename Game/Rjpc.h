#pragma once
#include <physics/PhysicsStaticObjectM.h>
#include <physics/PhysicsSphereObject.h>
class JPCball;
class Game;

class Rjpc : public IGameObject
{
public:
	Rjpc();
	~Rjpc();
	void Update();
	Vector3 firstPosition;
	Vector3 position;			//���W�B
	//�X�e�[�g�Ǘ��B
	//void ManageState();
	void Render(RenderContext& rc);
	//�����蔻��
	void Collision();

private:
	void Rotation();
	Game* game;
	JPCball* jball = nullptr;
	//JPCball jballC;

	float ROTATION = 0.6f/**0.765573f*/;
	Vector3 moveSpeed;		//�ړ����x�B
	Quaternion rotation;  //�N�H�[�^�j�I���B
	
	//CharacterControllerCylinder characterControllerC;
	ModelRender modelRender;
	PhysicsStaticObjectM physicsStaticObjectM;

	//�e�����蔻�������
	CollisionObject* h100_1;			//100�z���̓����蔻��1
	CollisionObject* h100_2;			//100�z���̓����蔻��2
	CollisionObject* h100_3;			//100�z���̓����蔻��3
	CollisionObject* h100_4;			//100�z���̓����蔻��4
	CollisionObject* h300_1;			//100�z���̓����蔻��4
	CollisionObject* h300_2;			//100�z���̓����蔻��4
	CollisionObject* h300_3;			//100�z���̓����蔻��4
	CollisionObject* hJP;				//JP�̓����蔻��
	enum enRotationState
	{
		enRotationState_Rot,
		enRotationState_Stop
	};
	enRotationState		RotState = enRotationState_Stop;
};

