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
	Vector3 position;			//座標。
	//ステート管理。
	//void ManageState();
	void Render(RenderContext& rc);
	//当たり判定
	void Collision();

private:
	void Rotation();
	Game* game;
	JPCball* jball = nullptr;
	//JPCball jballC;

	float ROTATION = 0.6f/**0.765573f*/;
	Vector3 moveSpeed;		//移動速度。
	Quaternion rotation;  //クォータニオン。
	
	//CharacterControllerCylinder characterControllerC;
	ModelRender modelRender;
	PhysicsStaticObjectM physicsStaticObjectM;

	//各当たり判定をつける
	CollisionObject* h100_1;			//100配当の当たり判定1
	CollisionObject* h100_2;			//100配当の当たり判定2
	CollisionObject* h100_3;			//100配当の当たり判定3
	CollisionObject* h100_4;			//100配当の当たり判定4
	CollisionObject* h300_1;			//100配当の当たり判定4
	CollisionObject* h300_2;			//100配当の当たり判定4
	CollisionObject* h300_3;			//100配当の当たり判定4
	CollisionObject* hJP;				//JPの当たり判定
	enum enRotationState
	{
		enRotationState_Rot,
		enRotationState_Stop
	};
	enRotationState		RotState = enRotationState_Stop;
};

