#pragma once
#include <physics/PhysicsStaticObjectM.h>
//class PR_Doom;

class PR_Doom : public IGameObject
{
public:
	PR_Doom();
	~PR_Doom();
	void Update();


	//�X�e�[�g�Ǘ��B
	//void ManageState();
	void Render(RenderContext& rc);

private:
	void Rotation();
	//Jball* jball = nullptr;
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