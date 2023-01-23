#pragma once
#include <physics/PhysicsStaticObjectM.h>
class Ball;

class Bouto : public IGameObject
{
public:
	Bouto();
	~Bouto();
	void Update();

	
	//ステート管理。
	//void ManageState();
	void Render(RenderContext& rc);

private:
void Rotation();
	Ball* ball = nullptr;
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

