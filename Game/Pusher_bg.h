#pragma once
class Pusher_bg : public IGameObject
{
public:
	Pusher_bg();
	~Pusher_bg();

	void Render(RenderContext& rc);

	ModelRender modelRender;
	PhysicsStaticObject physicsStaticObject;
};

