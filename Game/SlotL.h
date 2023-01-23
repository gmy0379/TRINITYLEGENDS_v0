#pragma once
class SlotL : public IGameObject
{
public:
	SlotL();
	~SlotL();

	//void Update();
	void Render(RenderContext& rc);

	Vector3 position;
	CharacterController slocon;
	ModelRender modelRender;
	//FontRender fontRender;
	//PhysicsStaticObject physicsStaticObject;

	int L;

};

