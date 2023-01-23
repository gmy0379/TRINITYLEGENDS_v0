#pragma once
class Medal;
class Game;
class Gameover;
//class Text;
//class Ball;
class Counter : public IGameObject
{
Game* game;
Medal* medal;
Gameover* gameover;
//Text* text;
//Ball* ball;
public:
	Counter();
	~Counter();
	void Update();
	void Render(RenderContext& rc);
	
	float Mcount = 1000.0f;	//cƒƒ_ƒ‹”
	float Mfall = 1.0f;
	float Mlost = 1.0f;
	int Msum = 0;
	float Mget = 1.0f;
	float PO = 46.24f;
	int textchange = 0;
	int End = 0;
	int clear = 0;
	FontRender fontRender;

};

