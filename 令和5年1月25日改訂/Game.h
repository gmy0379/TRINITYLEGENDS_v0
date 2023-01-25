#pragma once
//#include "Level3DRender/LevelRender.h"
#include "sound/SoundSource.h"

//メダルゲームの基本クラス
class Medal;
class GameCamera;
class BackGround;
class Pusher;
class Yokoana;
class YokoR;
class Counter;
class Text;
class Haitou;
class Choice;
class SlotL;
class Gameover;
class GameClear;

//ボール関係クラス
class Bout;
class Bouto;
class Bout2;
class Ball1;
class Ball2;
class Ball3;


//JPC関係クラス(間に合いそうにないので使用を断念)
//class Rjpc;
//class Ajpc;
//class Pjpc;
//class JPCnot;
//class JPCnot2;
//class JPCball;

//プラネットラッシュのクラス(本実装はしない予定)
//class PR_Doom;
//class PR_wing;
//class PR_not;

//Gameシーンを管理するクラス。
class Game : public IGameObject
{
public:
	Game();
	~Game();
	//更新処理。
	void Update();
	//ステート管理。
	void ManageState();

	//各JPC終了後の管理
	void JPC();

	//ボール投下処理
	void Ballfall();

	//JPCの配当処理
	//void JPCwin();
	
	//BGMの再生処理 
	void BGM();

	//ボール獲得(JPC抽選)時の処理
	void Ballwin();

/// 空を初期化。
	void InitSky();

	SkyCube* m_skyCube = nullptr;		//スカイキューブ。
	Gameover* gameover;
	GameClear* gameclear;
	Choice* choice;
	Text* text;
	Haitou* haitou;
	Pusher* pusher;				//プッシャー
	Counter* counter;
	Medal* medal;			//プレイヤー。
	GameCamera* gameCamera;			//ゲームカメラ。
	BackGround* backGround;		//サテライト本体
	Bout* bout;
	Bout2* bout2;
	Bouto* bouto;
	Ball1* ball1;
	Ball2* ball2;
	Ball3* ball3;
	Yokoana* Yoko0;				//横穴
	SoundSource* gameBGM;		//ゲーム中のBGM。
	Vector3 position;
	FontRender fontRender;
	FontRender wintext;
	SpriteRender spriteRender;
	void Render(RenderContext& rc);
	float m_time = 0.0f;
	int timer = 0;
	int m = 0;
	int j = 0;
	int GameState = 0;
	int EmptyState = 0;
	int ballState = 0;
	int pinchState = 0;
	int jpstate1= 0;
	int jpstate2= 0;
	int jpstate3= 0;
	int jpstate = 0;
	int Frame = 0;
	int win = 0;
	int Ball = 0;
	int Endframe = 0;
	int music = 1;
	int Mctrl = 0;

};

