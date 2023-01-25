#include "stdafx.h"
#include "Game.h"
#include "Medal.h"
#include "GameCamera.h"
#include "BackGround.h"
#include "Bout.h"
#include "Bout2.h"
#include "Bouto.h"
#include "Ball1.h"
#include "Ball2.h"
#include "Ball3.h"
#include "sound/SoundEngine.h"
#include "Yokoana.h"
#include "Counter.h"
#include "Pusher.h"
#include "Text.h"
#include "Haitou.h"
#include "Gameover.h"
#include "GameClear.h"
#include <time.h>
#include <btBulletDynamicsCommon.h>

//スカイキューブ。お空。
#include "nature/SkyCube.h"

namespace 
{
int ballfall = 0;
float VOL_main = 1.4f;
float GET_main = 1.0f;
int sky = 0;
}

Game::Game()
{
	
	PhysicsWorld::GetInstance()->SetGravity({ 0.0f,-550.0f,0.01f });
	srand((unsigned int)time(NULL));
	
	InitSky();

	//カウンタークラスを作成
	counter = NewGO<Counter>(0, "counter");

	//ゲームカメラのオブジェクトを作る。
	gameCamera = NewGO<GameCamera>(2, "gamecamera");

	//背景のオブジェクトを作る。
	backGround = NewGO<BackGround>(0);

	//スロットモデルを作成
	//L = NewGO<SlotL>(0);

	//プッシャーのオブジェクトを作成。
	//pusher_bg = NewGO<Pusher_bg>(0);
	pusher = NewGO<Pusher>(0,"pusher");
	//横穴のオブジェクトを作る。
	Yoko0 = NewGO<Yokoana>(1);

	//ボールのオブジェクトを作る。
	//ball = NewGO<Ball>(0,"ball");
	//ボール排出部のオブジェクトを作る。
	bouto = NewGO<Bouto>(0);
	//不動部。
	bout = NewGO<Bout>(0);
	bout2 = NewGO<Bout2>(0);

	text = NewGO<Text>(0);
	haitou = NewGO<Haitou>(0);

	//フィールドにばらまかれるメダルの枚数を設定
	win = rand() % 50+300;
	for (int i = 0; i < win; i++) {
		medal = NewGO<Medal>(0, "wedal");
	}
	win = 0;

	//ゲーム中のBGMを読み込む。
	g_soundEngine->ResistWaveFileBank(9, "Assets/sound/RJPCBGM.wav");
	g_soundEngine->ResistWaveFileBank(10, "Assets/sound/AJPCBGM.wav");
	g_soundEngine->ResistWaveFileBank(11, "Assets/sound/PJPCBGM.wav");
	g_soundEngine->ResistWaveFileBank(12, "Assets/sound/RJPBGM.wav");
	g_soundEngine->ResistWaveFileBank(13, "Assets/sound/AJPBGM.wav");
	g_soundEngine->ResistWaveFileBank(14, "Assets/sound/PJPBGM.wav");
	g_soundEngine->ResistWaveFileBank(15, "Assets/sound/Staffrole.wav");
	g_soundEngine->ResistWaveFileBank(16, "Assets/sound/MG_Rule.wav");
	g_soundEngine->ResistWaveFileBank(18, "Assets/sound/pinch.wav");
	g_soundEngine->ResistWaveFileBank(19, "Assets/sound/smallWIN.wav");
	g_soundEngine->ResistWaveFileBank(20, "Assets/sound/mediumWIN.wav");
	g_soundEngine->ResistWaveFileBank(21, "Assets/sound/jpWIN.wav");
	g_soundEngine->ResistWaveFileBank(25, "Assets/sound/MG_main2.wav");
	g_soundEngine->ResistWaveFileBank(26, "Assets/sound/MG_main3.wav");
	g_soundEngine->ResistWaveFileBank(27, "Assets/sound/MG_main4.wav");
	g_soundEngine->ResistWaveFileBank(28, "Assets/sound/MG_main1.wav");
	g_soundEngine->ResistWaveFileBank(29, "Assets/sound/AJPwin.wav");
	g_soundEngine->ResistWaveFileBank(29, "Assets/sound/PJPwin.wav");

	if (choice == nullptr) {
		music = rand() % 3 + 25;
	//ゲーム中のBGMを再生する。
		gameBGM = NewGO<SoundSource>(0);
		gameBGM->Init(music);
		gameBGM->SetVolume(VOL_main);
		gameBGM->Play(true);
	}

	//配当表示クラスを探しまーす
	if (haitou == nullptr) {
		haitou = FindGO<Haitou>("haitou");
		return;
	}
}

void Game::InitSky()
{
	sky = rand() % 17;
	if (sky == 16) {
		sky = 3;
	}
	// 現在の空を破棄。
	DeleteGO(m_skyCube);

	m_skyCube = NewGO<SkyCube>(1, "skycube");
	m_skyCube->SetType((EnSkyCubeType)sky);		//SkyCubeのタイプを呼び出し
	//m_skyCube->SetPosition(Vector3(-100.0f, -40.0f, -900.0f));
	m_skyCube->SetLuminance(0.5f);
	m_skyCube->SetScale(200);

	// 環境光の計算のためのIBLテクスチャをセットする。
	g_renderingEngine->SetAmbientByIBLTexture(m_skyCube->GetTextureFilePath(), 0.1f);
}

Game::~Game()
{
	//プレイヤー、ゲームカメラ、BGM、背景等を削除する
	DeleteGO(medal);
	DeleteGO(gameCamera);
	DeleteGO(gameBGM);
	DeleteGO(backGround);
	DeleteGO(text);
	DeleteGO(counter);
	DeleteGO(pusher);
	DeleteGO(Yoko0);
	DeleteGO(bouto);
	DeleteGO(bout);
	DeleteGO(bout2);
	DeleteGO(haitou);
	DeleteGO(gameBGM);
	DeleteGO(m_skyCube);
	DeleteGO(ball1);
	DeleteGO(ball2);
	DeleteGO(ball3);
}

//更新処理。
void Game::Update()
{

	//BGM();
	Ballwin();

	//メダルの投下及びカウンターの減算(RATE枚分のクレを引く)
	if (counter->Mcount > 0) {
		if (g_pad[0]->IsPress(enButtonA))
		{
			Mctrl++;

			//Aボタンを押している時間でメダルの投下を調整

			if (Mctrl >= 10) {
				//g_gameTime->GetFrameDeltaTime() * 0.001f;
				Medal* medal = NewGO<Medal>(0, "medal");
				counter->Mcount--;
				counter->Mfall++;
				Mctrl = 0;
			}
		}
		else Mctrl = 0;
	}

	//開発用。ボールを生成する
	if (g_pad[0]->IsTrigger(enButtonLB1))
	{
		ballState = 0;
		Ballfall();
	}
	if (g_pad[0]->IsTrigger(enButtonRB1))
	{
		ballState = 2;
		Ballfall();
	}
	if (g_pad[0]->IsTrigger(enButtonSelect))
	{
		ballState = 1;
		Ballfall();
	}

	// 開発用。BGMの緊急停止(STARTボタンで作動。完成時には動かないようにする)
	if (g_pad[0]->IsTrigger(enButtonStart)) {
		gameBGM->Stop();
	}

	//初期時間の設定
	int MIN = 0;
	int SEC = 0;
	const int TIME = 0;

	//タイム計測
	wchar_t wcsbuf[256];
	swprintf_s(wcsbuf, 256, L"経過時間　%d分%d秒", min,sec);

	sec = (TIME + int(m_time));
	if (sec == 60) {
		sec = 0;
		m_time = 0;
		min += 1;
		
	}

	m_time += g_gameTime->GetFrameDeltaTime();

	//表示するテキストを設定。
	fontRender.SetText(wcsbuf);
	//フォントの位置を設定。
	fontRender.SetPosition(Vector3(-950.0f, 500.0f, 0.0f));
	//フォントの大きさを設定。
	fontRender.SetScale(2.0f);
	fontRender.SetColor(1.0f, 0.0f, 0.0f, 1.0f);

	//メダルの総獲得枚数が100枚ごとにボールを投下する
	if (counter->Msum >= 100) {
		ballfall = 1;
		counter->Msum = 0;
	}

	if (ballfall == 1)
	{
		ballState = rand() % 2;
		Ballfall();
	}


	//メダルが0枚になって一定時間経つとゲーム終了
	if (counter->End > 1000)
	{
		DeleteGO(this);
		gameover = NewGO<Gameover>(0, "Gameover");
	}

	//メダルが10000枚を超えるとゲームクリア
	if (counter->clear > 0)
	{
		gameBGM->Stop();
		VOL_main = 0.0f;
		DeleteGO(this);
		gameclear = NewGO<GameClear>(0, "gameclear");
	}
		
}

void Game::BGM()
{
	//メイン楽曲の変更
	if (gameBGM->IsPlaying() == false)
		switch (music) {
		case 0:
			DeleteGO(gameBGM);
			gameBGM = NewGO<SoundSource>(0);
			gameBGM->Init(28);
			gameBGM->SetVolume(VOL_main);
			gameBGM->Play(false);
			music = 1;
			break;

		case 1:
			DeleteGO(gameBGM);
			gameBGM = NewGO<SoundSource>(0);
			gameBGM->Init(25);
			gameBGM->SetVolume(VOL_main);
			gameBGM->Play(false);
			music = 2;
			break;

		case 2:
			DeleteGO(gameBGM);
			gameBGM = NewGO<SoundSource>(0);
			gameBGM->Init(26);
			gameBGM->SetVolume(VOL_main);
			gameBGM->Play(false);
			music = 3;
			break;

		case 3:
			DeleteGO(gameBGM);
			gameBGM = NewGO<SoundSource>(0);
			gameBGM->Init(27);
			gameBGM->SetVolume(VOL_main);
			gameBGM->Play(false);
			music = 0;
			break;
		}
}

//ボール獲得後の処理
void Game::Ballwin()
{

	//RJPボールの配当設定(1/10)
	if (ball1 != nullptr) {
		if (ball1->ballState == 1) {
			jpstate = rand() % 9;
			switch (jpstate) {
			case 7:
				gameBGM = NewGO<SoundSource>(0);
				gameBGM->Init(20);
				gameBGM->SetVolume(GET_main);
				gameBGM->Play(false);
				win = 200;
				text->RJP += 200;
				ball1->ballState = 0;
				break;
			case 9:
				gameBGM = NewGO<SoundSource>(0);
				gameBGM->Init(20);
				gameBGM->SetVolume(GET_main);
				gameBGM->Play(false);
				win = 200;
				text->RJP += 200;
				ball1->ballState = 0;
				break;
			case 1:
				InitSky();
				gameBGM = NewGO<SoundSource>(0);
				gameBGM->Init(21);
				gameBGM->SetVolume(GET_main);
				gameBGM->Play(false);
				win = text->RJP;
				text->RJP = 1000.0f;
				ball1->ballState = 0;
				break;
			default:
				gameBGM = NewGO<SoundSource>(0);
				gameBGM->Init(19);
				gameBGM->SetVolume(GET_main);
				gameBGM->Play(false);
				win = 100;
				text->RJP += 100;
				ball1->ballState = 0;
				break;
			}
			counter->Mcount += win;
			DeleteGO(ball1);
			haitou->State = 1;
			haitou->fcount = 0;

		}
	}

	//AJPボールの配当設定(1/100)
	if (ball2 != nullptr) {
		if (ball2->ballState == 1) {
			jpstate = rand() % 99;
			switch (jpstate) {
			case 7:
				gameBGM = NewGO<SoundSource>(0);
				gameBGM->Init(20);
				gameBGM->SetVolume(GET_main);
				gameBGM->Play(false);
				win = 300;
				text->AJP += 300;
				ball2->ballState = 0;
				break;
			case 9:
				gameBGM = NewGO<SoundSource>(0);
				gameBGM->Init(20);
				gameBGM->SetVolume(GET_main);
				gameBGM->Play(false);
				win = 300;
				text->AJP += 300;
				ball2->ballState = 0;
				break;
			case 77:
				gameBGM = NewGO<SoundSource>(0);
				gameBGM->Init(29);
				gameBGM->SetVolume(GET_main);
				gameBGM->Play(false);
				win = text->AJP;
				text->AJP = 1500.0f;
				ball2->ballState = 0;
				break;
			case 38:
				gameBGM = NewGO<SoundSource>(0);
				gameBGM->Init(20);
				gameBGM->SetVolume(GET_main);
				gameBGM->Play(false);
				win = 300;
				text->AJP += 300;
				ball2->ballState = 0;
				break;
			case 74:
				gameBGM = NewGO<SoundSource>(0);
				gameBGM->Init(20);
				gameBGM->SetVolume(GET_main);
				gameBGM->Play(false);
				win = 300;
				text->AJP += 300;
				ball2->ballState = 0;
				break;
			default:
				gameBGM = NewGO<SoundSource>(0);
				gameBGM->Init(19);
				gameBGM->SetVolume(GET_main);
				gameBGM->Play(false);
				win = 200;
				text->AJP += 200;
				ball2->ballState = 0;
				break;
			}
			counter->Mcount += win;
			DeleteGO(ball2);
			haitou->State = 1;
			jpstate = 0;
			haitou->State = 0;
		}
	}

	//PJPボールの配当設定(1/300)
	if (ball3 != nullptr) {
		if (ball3->ballState == 1) {
			jpstate = rand() % 299;
			switch (jpstate) {
			case 7:
				gameBGM = NewGO<SoundSource>(0);
				gameBGM->Init(20);
				gameBGM->SetVolume(GET_main);
				gameBGM->Play(false);
				win = 500;
				text->PJP += 500;
				ball3->ballState = 0;
				break;
			case 9:
				gameBGM = NewGO<SoundSource>(0);
				gameBGM->Init(20);
				gameBGM->SetVolume(GET_main);
				gameBGM->Play(false);
				win = 500;
				text->PJP += 500;
				ball3->ballState = 0;
				break;
			case 77:
				gameBGM = NewGO<SoundSource>(0);
				gameBGM->Init(30);
				gameBGM->SetVolume(GET_main);
				gameBGM->Play(false);
				win = text->PJP;
				text->RJP = 3000.0f;
				ball3->ballState = 0;
				break;
			case 102:
				gameBGM = NewGO<SoundSource>(0);
				gameBGM->Init(20);
				gameBGM->SetVolume(GET_main);
				gameBGM->Play(false);
				win = 500;
				text->PJP += 500;
				ball3->ballState = 0;
				break;
			case 113:
				gameBGM = NewGO<SoundSource>(0);
				gameBGM->Init(20);
				gameBGM->SetVolume(GET_main);
				gameBGM->Play(false);
				win = 500;
				text->PJP += 500;
				ball3->ballState = 0;
				break;
			case 179:
				gameBGM = NewGO<SoundSource>(0);
				gameBGM->Init(20);
				gameBGM->SetVolume(GET_main);
				gameBGM->Play(false);
				win = 500;
				text->PJP += 500;
				ball3->ballState = 0;
				break;
			case 277:
				gameBGM = NewGO<SoundSource>(0);
				gameBGM->Init(20);
				gameBGM->SetVolume(GET_main);
				gameBGM->Play(false);
				win = 500;
				text->PJP += 500;
				ball3->ballState = 0;
				break;
			default:
				gameBGM = NewGO<SoundSource>(0);
				gameBGM->Init(19);
				gameBGM->SetVolume(GET_main);
				gameBGM->Play(false);
				win = 300;
				text->PJP += 300;
				ball3->ballState = 0;
				break;
			}
			if (haitou == nullptr) {
				haitou = FindGO<Haitou>("haitou");
				return;
			}
			counter->Mcount += win;
			DeleteGO(ball3);
			haitou->State = 1;
			jpstate = 0;
			haitou->State = 0;
		}
	}
}

void Game::Ballfall()
{
	switch (ballState)
	{
	case 0:
	{
		ball2 = NewGO<Ball2>(0, "ball2");
		ballfall = 0;
		break;
	}

	case 1:
	{
		ball3 = NewGO<Ball3>(0, "ball3");
		ballfall = 0;
		break;
	}

	default:
		{
		ball1 = NewGO<Ball1>(0, "ball1");
		ballfall = 0;
		break;
		}
	}
}

void Game::Render(RenderContext& rc)
{
	fontRender.Draw(rc);
}