#pragma once

class Pusherv2 : public IGameObject
{
public:
	Pusherv2();
	~Pusherv2();
	//更新処理。
	void Update();
	void Render(RenderContext& rc);
	//移動処理。
	void Move();

	FontRender fontRender;
	Vector3 position;			//座標。
	CharacterController characterController;  //キャラクターコントローラー。
	Vector3 moveSpeed;		//移動速度。
	ModelRender modelRender;
	PhysicsStaticObject physicsStaticObject;
};

