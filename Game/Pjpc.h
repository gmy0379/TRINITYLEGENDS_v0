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
    Vector3 position;			//座標。

	//ステート管理。
	//void ManageState();
	void Render(RenderContext& rc);

private:
	void Rotation();
	Game* game;
	Jball* jball = nullptr;
	
	Vector3 moveSpeed;		//移動速度。
	Quaternion rotation;  //クォータニオン。

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

