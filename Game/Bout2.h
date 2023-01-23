#pragma once
class Bout2 : public IGameObject
{
public:
	Bout2();
	~Bout2();

	int ballState = 0;	//プレイヤーのステート(状態)を表す変数。
	void Render(RenderContext& rc);

	ModelRender modelRender;
	PhysicsStaticObject physicsStaticObject;
};