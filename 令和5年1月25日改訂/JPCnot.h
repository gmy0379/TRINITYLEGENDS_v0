#pragma once
#include <physics/PhysicsStaticObjectM.h>
class Jball;

class JPCnot : public IGameObject
{
public:
	JPCnot();
	~JPCnot();
	void Update();


	//ステート管理。
	//void ManageState();
	void Render(RenderContext& rc);

private:
	void Rotation();
	Jball* jball = nullptr;
	Vector3 position;			//座標。
	Vector3 moveSpeed;		//移動速度。
	Quaternion rotation;  //クォータニオン。
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



