#pragma once
class Choice;
class Yokoana : public IGameObject
{
public:
	Yokoana();
	~Yokoana();
	Choice* choice;
	void Render(RenderContext& rc);

	ModelRender modelRender;
	PhysicsStaticObject physicsStaticObject;
};
