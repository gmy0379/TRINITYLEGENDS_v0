#pragma once
#include <physics/PhysicsStaticObjectM.h>
class Jball;
class Game;

class Pjpc : public IGameObject
{
public:
	Pjpc();
	~Pjpc();
	void Update();
	Vector3 firstPosition;
    Vector3 position;			//���W�B

	//�X�e�[�g�Ǘ��B
	//void ManageState();
	void Render(RenderContext& rc);

private:
	void Rotation();
	Game* game;
	Jball* jball = nullptr;
	
	Vector3 moveSpeed;		//�ړ����x�B
	Quaternion rotation;  //�N�H�[�^�j�I���B

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

