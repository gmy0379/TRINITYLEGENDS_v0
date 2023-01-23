#pragma once
class Counter;
class Game;

class Text : public IGameObject
{
	Counter* counter;
	Game* game;
public:
	Text();
	~Text();
	void ManageState();
	void Update();
	void Render(RenderContext& rc);
	FontRender fontRender;
	float RJP = 1000.00f;
	float AJP = 1500.00f;
	float PJP = 3000.00f;
	float addR = 0.001f;
	float addA = 0.001f;
	float addP = 0.08f;
	float fcount = 0;
	int State = 0;
};

