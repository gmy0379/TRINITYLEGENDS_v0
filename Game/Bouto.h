#pragma once
#include <physics/PhysicsStaticObjectM.h>
class Ball;

class Bouto : public IGameObject
{
public:
	Bouto();
	~Bouto();
	void Update();

	
	//�X�e�[�g�Ǘ��B
	//void ManageState();
	void Render(RenderContext& rc);

private:
void Rotation();
	Ball* ball = nullptr;
	Vector3 position;			//���W�B
	Vector3 moveSpeed;		//�ړ����x�B
	Quaternion rotation;  //�N�H�[�^�j�I���B
	Vector3 firstPosition;
	//CharacterControllerCylinder characterControllerC;
	ModelRender modelRender;
	PhysicsStaticObjectM physicsStaticObjectM;
	//CollisionObject* collisionObject;
	enum enRotationState
	{
		enRotationState_Rot,
		enRotationState_Stop
	};
	enRotationState		RotState = enRotationState_Stop;
};

