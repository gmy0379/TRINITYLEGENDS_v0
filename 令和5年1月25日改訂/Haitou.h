#pragma once
class Counter;
class Game;
class Ball1;
class Ball2;
class Ball3;

class Haitou : public IGameObject
{
	Counter* counter;
	Game* game;
	//SoundSource* gameBGM;		//ÉQÅ[ÉÄíÜÇÃBGMÅB
	
public:
	Haitou();
	~Haitou();
	void ManageState();
	void Update();
	void Render(RenderContext& rc);
	Ball1* ball1;
	Ball2* ball2;
	Ball3* ball3;
	FontRender wintext;
	float RJP = 1000.00f;
	float AJP = 1500.00f;
	float PJP = 3000.00f;
	float addR = 0.001f;
	float addA = 0.001f;
	float addP = 0.08f;
	float fcount = 0;
	int State = 0;
};

