#pragma once
class Bout2 : public IGameObject
{
public:
	Bout2();
	~Bout2();

	int ballState = 0;	//�v���C���[�̃X�e�[�g(���)��\���ϐ��B
	void Render(RenderContext& rc);

	ModelRender modelRender;
	PhysicsStaticObject physicsStaticObject;
};