#pragma once
class Bout : public IGameObject
{
public:
	Bout();
	~Bout();

	void Render(RenderContext& rc);

	ModelRender modelRender;
	PhysicsStaticObject physicsStaticObject;
};

