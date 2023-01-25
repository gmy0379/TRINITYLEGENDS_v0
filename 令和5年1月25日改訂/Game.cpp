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
float VOL_main = 0.6f;
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
	NewGO<Haitou>(0);

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

	if (choice == nullptr) {
	//ゲーム中の通常BGMを再生する。
		gameBGM = NewGO<SoundSource>(0);
		gameBGM->Init(25);
		gameBGM->SetVolume(VOL_main);
		gameBGM->Play(false);
		music = 1;
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
	DeleteGO(ball1);
	DeleteGO(ball2);
	DeleteGO(ball3);
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
	BGM();

	//メダルの投下及びカウンターの減算(RATE枚分のクレを引く)
	if (counter->Mcount > 0) {
		if (g_pad[0]->/*IsTrigger*/IsPress(enButtonA))
		{
			Mctrl++;
			if (Mctrl >= 25) {
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

	// 開発用。BGMの緊急停止(BACKボタンで作動。完成時には動かないようにする)
	if (g_pad[0]->IsTrigger(enButtonStart)) {
		gameBGM->Stop();
	}

	//初期時間の設定
	const int TIME = 0;

	//タイム計測
	wchar_t wcsbuf[256];
	swprintf_s(wcsbuf, 256, L"経過時間  %d", TIME + int(m_time));

	timer = (TIME + int(m_time));

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

	haitou = FindGO<Haitou>("haitou");
	//Ballwin();
		if (haitou == nullptr) {
			haitou = FindGO<Haitou>("haitou");
			return;
		}

		//RJPボールの配当設定(1/10)
		//if (ball1 != nullptr) {
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
				DeleteGO(ball1);
				haitou->State = 1;
				//timer = 0;
				haitou->fcount = 0;
				//m_time += g_gameTime->GetFrameDeltaTime()/200;
				for (int i = 0; i < win; i++) {
					counter->Mcount++;
				}
				//m_time += g_gameTime->GetFrameDeltaTime();
			}
		//}

		//AJPボールの配当設定(1/100)
		if (ball2 != nullptr) {
			if (ball2->BallState == 1) {
				jpstate = rand() % 99;
				switch (jpstate) {
				case 7:
					gameBGM = NewGO<SoundSource>(0);
					gameBGM->Init(20);
					gameBGM->SetVolume(GET_main);
					gameBGM->Play(false);
					win = 300;
					text->AJP += 300;
					ball2->BallState = 0;
					break;
				case 9:
					gameBGM = NewGO<SoundSource>(0);
					gameBGM->Init(20);
					gameBGM->SetVolume(GET_main);
					gameBGM->Play(false);
					win = 300;
					text->AJP += 300;
					ball2->BallState = 0;
					break;
				case 77:
					gameBGM = NewGO<SoundSource>(0);
					gameBGM->Init(21);
					gameBGM->SetVolume(GET_main);
					gameBGM->Play(false);
					win = text->RJP;
					text->RJP = 1000.0f;
					ball2->BallState = 0;
					break;
				case 38:
					gameBGM = NewGO<SoundSource>(0);
					gameBGM->Init(20);
					gameBGM->SetVolume(GET_main);
					gameBGM->Play(false);
					win = 300;
					text->AJP += 300;
					ball2->BallState = 0;
					break;
				case 74:
					gameBGM = NewGO<SoundSource>(0);
					gameBGM->Init(20);
					gameBGM->SetVolume(GET_main);
					gameBGM->Play(false);
					win = 300;
					text->AJP += 300;
					ball2->BallState = 0;
					break;
				default:
					gameBGM = NewGO<SoundSource>(0);
					gameBGM->Init(19);
					gameBGM->SetVolume(GET_main);
					gameBGM->Play(false);
					win = 200;
					text->AJP += 200;
					ball2->BallState = 0;
					break;
				}
				DeleteGO(ball2);
				haitou->State = 1;
				//timer = 0;
				haitou->fcount = 0;
				//m_time += g_gameTime->GetFrameDeltaTime() / 20;
				for (int i = 0; i < win; i++) {
					counter->Mcount++;
				}
				//m_time += g_gameTime->GetFrameDeltaTime();
				jpstate = 0;
				haitou->State = 0;
			}
		}

		//PJPボールの配当設定(1/300)
		if (ball3 != nullptr) {
			if (ball3->BallState == 1) {
				jpstate = rand() % 299;
				switch (jpstate3) {
				case 7:
					gameBGM = NewGO<SoundSource>(0);
					gameBGM->Init(20);
					gameBGM->SetVolume(GET_main);
					gameBGM->Play(false);
					win = 500;
					text->PJP += 500;
					ball3->BallState = 0;
					break;
				case 9:
					gameBGM = NewGO<SoundSource>(0);
					gameBGM->Init(20);
					gameBGM->SetVolume(GET_main);
					gameBGM->Play(false);
					win = 500;
					text->PJP += 500;
					ball3->BallState = 0;
					break;
				case 77:
					gameBGM = NewGO<SoundSource>(0);
					gameBGM->Init(21);
					gameBGM->SetVolume(GET_main);
					gameBGM->Play(false);
					win = text->RJP;
					text->RJP = 1000.0f;
					ball3->BallState = 0;
					break;
				case 102:
					gameBGM = NewGO<SoundSource>(0);
					gameBGM->Init(20);
					gameBGM->SetVolume(GET_main);
					gameBGM->Play(false);
					win = 500;
					text->PJP += 500;
					ball1->ballState = 0;
					break;
				case 113:
					gameBGM = NewGO<SoundSource>(0);
					gameBGM->Init(20);
					gameBGM->SetVolume(GET_main);
					gameBGM->Play(false);
					win = 500;
					text->PJP += 500;
					ball1->ballState = 0;
					break;
				case 179:
					gameBGM = NewGO<SoundSource>(0);
					gameBGM->Init(20);
					gameBGM->SetVolume(GET_main);
					gameBGM->Play(false);
					win = 500;
					text->PJP += 500;
					ball1->ballState = 0;
					break;
				case 277:
					gameBGM = NewGO<SoundSource>(0);
					gameBGM->Init(20);
					gameBGM->SetVolume(GET_main);
					gameBGM->Play(false);
					win = 500;
					text->PJP += 500;
					ball1->ballState = 0;
					break;
				default:
					gameBGM = NewGO<SoundSource>(0);
					gameBGM->Init(19);
					gameBGM->SetVolume(GET_main);
					gameBGM->Play(false);
					win = 300;
					text->PJP += 300;
					ball3->BallState = 0;
					break;
				}
				DeleteGO(ball3);
				haitou->State = 1;
				//timer = 0;
				haitou->fcount = 0;
				//m_time += g_gameTime->GetFrameDeltaTime() / 20;
				for (int i = 0; i < win; i++) {
					counter->Mcount++;
				}
				//m_time += g_gameTime->GetFrameDeltaTime();
				jpstate = 0;
				haitou->State = 0;
			}
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

//void Game::Ballwin()
//{
//	//RJPボールの配当設定(1/10)
//	if (ball1 != nullptr) {
//		if (ball1->ballState == 1) {
//			jpstate = rand() % 9;
//			switch (jpstate) {
//			case 7:
//				gameBGM = NewGO<SoundSource>(0);
//				gameBGM->Init(20);
//				gameBGM->SetVolume(GET_main);
//				gameBGM->Play(false);
//				win = 200;
//				text->RJP += 200;
//				ball1->ballState = 0;
//				break;
//			case 9:
//				gameBGM = NewGO<SoundSource>(0);
//				gameBGM->Init(20);
//				gameBGM->SetVolume(GET_main);
//				gameBGM->Play(false);
//				win = 200;
//				text->RJP += 200;
//				ball1->ballState = 0;
//				break;
//			case 1:
//				gameBGM = NewGO<SoundSource>(0);
//				gameBGM->Init(21);
//				gameBGM->SetVolume(GET_main);
//				gameBGM->Play(false);
//				win = text->RJP;
//				text->RJP = 1000.0f;
//				ball1->ballState = 0;
//				break;
//			default:
//				gameBGM = NewGO<SoundSource>(0);
//				gameBGM->Init(19);
//				gameBGM->SetVolume(GET_main);
//				gameBGM->Play(false);
//				win = 100;
//				text->RJP += 100;
//				ball1->ballState = 0;
//				break;
//			}
//			DeleteGO(ball1);
//			haitou->State = 1;
//			//timer = 0;
//			haitou->fcount = 0;
//			//m_time += g_gameTime->GetFrameDeltaTime()/200;
//			for (int i=0; i < win; i++) {
//				counter->Mcount++;
//			}
//			//m_time += g_gameTime->GetFrameDeltaTime();
//		}
//	}
//
//	//AJPボールの配当設定(1/100)
//	if (ball2 != nullptr) {
//		if (ball2->BallState == 1) {
//			jpstate = rand() % 99;
//			switch (jpstate) {
//			case 7:
//				gameBGM = NewGO<SoundSource>(0);
//				gameBGM->Init(20);
//				gameBGM->SetVolume(GET_main);
//				gameBGM->Play(false);
//				win = 300;
//				text->AJP += 300;
//				ball2->BallState = 0;
//				break;
//			case 9:
//				gameBGM = NewGO<SoundSource>(0);
//				gameBGM->Init(20);
//				gameBGM->SetVolume(GET_main);
//				gameBGM->Play(false);
//				win = 300;
//				text->AJP += 300;
//				ball2->BallState = 0;
//				break;
//			case 77:
//				gameBGM = NewGO<SoundSource>(0);
//				gameBGM->Init(21);
//				gameBGM->SetVolume(GET_main);
//				gameBGM->Play(false);
//				win = text->RJP;
//				text->RJP = 1000.0f;
//				ball2->BallState = 0;
//				break;
//			case 38:
//				gameBGM = NewGO<SoundSource>(0);
//				gameBGM->Init(20);
//				gameBGM->SetVolume(GET_main);
//				gameBGM->Play(false);
//				win = 300;
//				text->AJP += 300;
//				ball2->BallState = 0;
//				break;
//			case 74:
//				gameBGM = NewGO<SoundSource>(0);
//				gameBGM->Init(20);
//				gameBGM->SetVolume(GET_main);
//				gameBGM->Play(false);
//				win = 300;
//				text->AJP += 300;
//				ball2->BallState = 0;
//				break;
//			default:
//				gameBGM = NewGO<SoundSource>(0);
//				gameBGM->Init(19);
//				gameBGM->SetVolume(GET_main);
//				gameBGM->Play(false);
//				win = 200;
//				text->AJP += 200;
//				ball2->BallState = 0;
//				break;
//			}
//			DeleteGO(ball2);
//			haitou->State = 1;
//			//timer = 0;
//			haitou->fcount = 0;
//			//m_time += g_gameTime->GetFrameDeltaTime() / 20;
//			for (int i = 0; i < win; i++) {
//				counter->Mcount++;
//			}
//			//m_time += g_gameTime->GetFrameDeltaTime();
//			jpstate = 0;
//			haitou->State = 0;
//		}
//	}
//
//	//PJPボールの配当設定(1/300)
//	if (ball3 != nullptr) {
//		if (ball3->BallState == 1) {
//			jpstate = rand() % 299;
//			switch (jpstate3) {
//			case 7:
//				gameBGM = NewGO<SoundSource>(0);
//				gameBGM->Init(20);
//				gameBGM->SetVolume(GET_main);
//				gameBGM->Play(false);
//				win = 500;
//				text->PJP += 500;
//				ball3->BallState = 0;
//				break;
//			case 9:
//				gameBGM = NewGO<SoundSource>(0);
//				gameBGM->Init(20);
//				gameBGM->SetVolume(GET_main);
//				gameBGM->Play(false);
//				win = 500;
//				text->PJP += 500;
//				ball3->BallState = 0;
//				break;
//			case 77:
//				gameBGM = NewGO<SoundSource>(0);
//				gameBGM->Init(21);
//				gameBGM->SetVolume(GET_main);
//				gameBGM->Play(false);
//				win = text->RJP;
//				text->RJP = 1000.0f;
//				ball3->BallState = 0;
//				break;
//			case 102:
//				gameBGM = NewGO<SoundSource>(0);
//				gameBGM->Init(20);
//				gameBGM->SetVolume(GET_main);
//				gameBGM->Play(false);
//				win = 500;
//				text->PJP += 500;
//				ball1->ballState = 0;
//				break;
//			case 113:
//				gameBGM = NewGO<SoundSource>(0);
//				gameBGM->Init(20);
//				gameBGM->SetVolume(GET_main);
//				gameBGM->Play(false);
//				win = 500;
//				text->PJP += 500;
//				ball1->ballState = 0;
//				break;
//			case 179:
//				gameBGM = NewGO<SoundSource>(0);
//				gameBGM->Init(20);
//				gameBGM->SetVolume(GET_main);
//				gameBGM->Play(false);
//				win = 500;
//				text->PJP += 500;
//				ball1->ballState = 0;
//				break;
//			case 277:
//				gameBGM = NewGO<SoundSource>(0);
//				gameBGM->Init(20);
//				gameBGM->SetVolume(GET_main);
//				gameBGM->Play(false);
//				win = 500;
//				text->PJP += 500;
//				ball1->ballState = 0;
//				break;
//			default:
//				gameBGM = NewGO<SoundSource>(0);
//				gameBGM->Init(19);
//				gameBGM->SetVolume(GET_main);
//				gameBGM->Play(false);
//				win = 300;
//				text->PJP += 300;
//				ball3->BallState = 0;
//				break;
//			}
//			DeleteGO(ball3);
//			haitou->State = 1;
//			//timer = 0;
//			haitou->fcount = 0;
//			//m_time += g_gameTime->GetFrameDeltaTime() / 20;
//			for (int i = 0; i < win; i++) {
//				counter->Mcount++;
//			}
//			//m_time += g_gameTime->GetFrameDeltaTime();
//			jpstate = 0;
//			haitou->State = 0;
//		}
//	}
//}

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

//void Game::JPC()
//{
//	if (jpc1 != nullptr && GameState != 1) {
//		DeleteGO(j1ball);
//		DeleteGO(j1not);
//		DeleteGO(j1not2);
//		DeleteGO(jpc1);
//		jpc1 = nullptr;
//	}
//	else if (jpc2 != nullptr && GameState != 2) {
//		DeleteGO(jpc2);
//		DeleteGO(j1not);
//		DeleteGO(j1ball);
//		DeleteGO(j1not2);
//		jpc2 = nullptr;
//	}
//	else if (jpc3 != nullptr && GameState != 3) {
//		DeleteGO(jpc3);
//		DeleteGO(j1not);
//		DeleteGO(j1ball);
//		DeleteGO(j1not2);
//		jpc3 = nullptr;
//	/*else if(wing!=nullptr&&GameState!=3){
//		DeleteGO(wing);
//		DeleteGO(doom);
//		DeleteGO(pnot);
//		wing = nullptr;*/
//	}
//	m_time = 0;
//}
//
//void Game::JPCwin()
//{
//	switch (timer)
//	{
//	case 0:
//		gameBGM = NewGO<SoundSource>(0);
//		gameBGM->Init(19);
//		gameBGM->SetVolume(VOL_main);
//		gameBGM->Play(false);
//		counter->Mcount += 100;
//	}
//}
//
//void Game::ManageState()
//{
//	//ゲームの状態を設定
//	if (gameBGM->IsPlaying() == false) {
//		{
//			switch (GameState)
//			{
//			case 1:
//				//RJPCBGMを再生する。+モデルを生成(一度生成されていたら生成しない)
//				gameBGM = NewGO<SoundSource>(0);
//				gameBGM->Init(9);
//				gameBGM->SetVolume(VOL_main);
//				gameBGM->Play(true);
//				JPC();
//				if (jpc1 == nullptr) {
//					jpc1 = NewGO<Rjpc>(0, "jpc1");
//					j1not = NewGO<JPCnot>(0, "j1not");
//					j1ball = NewGO<JPCball>(0, "j1ball");
//					j1not2 = NewGO<JPCnot2>(0, "j1not2");
//					gameCamera->CamState = 1;
//				}
//				break;
//			case 2:
//				//AJPCBGMを再生する。+モデルを生成(一度生成されていたら生成しない)
//				gameBGM = NewGO<SoundSource>(0);
//				gameBGM->Init(10);
//				gameBGM->SetVolume(VOL_main);
//				gameBGM->Play(true);
//				JPC();
//				if (jpc2 == nullptr) {
//					jpc2 = NewGO<Ajpc>(0, "jpc2");
//					j1not = NewGO<JPCnot>(0, "j1not");
//					j1ball = NewGO<JPCball>(0, "j1ball");
//					j1not2 = NewGO<JPCnot2>(0, "j1not2");
//					gameCamera->CamState = 2;
//				}
//				break;
//			case 3:
//				//PJPCBGMを再生する。+モデルを生成(一度生成されていたら生成しない)
//				gameBGM = NewGO<SoundSource>(0);
//				gameBGM->Init(11);
//				gameBGM->SetVolume(VOL_main);
//				gameBGM->Play(true);
//				JPC();
//				if (jpc3 == nullptr) {
//					jpc3 = NewGO<Pjpc>(0, "jpc3");
//					j1not = NewGO<JPCnot>(0, "j1not");
//					j1ball = NewGO<JPCball>(0, "j1ball");
//					j1not2 = NewGO<JPCnot2>(0, "j1not2");
//					gameCamera->CamState = 3;
//				}
//				/*if (wing == nullptr) {
//					wing = NewGO<PR_wing>(0,"wing");
//					doom = NewGO<PR_Doom>(0,"doom");
//					pnot = NewGO<PR_not>(0,"pnot");
//					gameCamera->CamState = 3;
//				}*/
//				break;
//			case 4:
//				//RJPBGMを再生する。
//				gameBGM = NewGO<SoundSource>(0);
//				gameBGM->Init(12);
//				gameBGM->SetVolume(VOL_main);
//				gameBGM->Play(true);
//				JPC();
//				break;
//			case 5:
//				//AJPBGMを再生する。
//				gameBGM = NewGO<SoundSource>(0);
//				gameBGM->Init(13);
//				gameBGM->SetVolume(VOL_main);
//				gameBGM->Play(true);
//				JPC();
//				break;
//			case 6:
//				//PJPBGMを再生する。
//				gameBGM = NewGO<SoundSource>(0);
//				gameBGM->Init(14);
//				gameBGM->SetVolume(VOL_main);
//				gameBGM->Play(true);
//				JPC();
//				break;
//			case 7:
//				//スタフロ(5000枚以上のJP獲得)を再生する。
//				gameBGM = NewGO<SoundSource>(0);
//				gameBGM->Init(15);
//				gameBGM->SetVolume(VOL_main);
//				gameBGM->Play(true);
//				JPC();
//				break;
//			case 8:
//				//実験用。ここでは流れない。。
//				gameBGM = NewGO<SoundSource>(0);
//				gameBGM->Init(16);
//				gameBGM->SetVolume(VOL_main);
//				gameBGM->Play(true);
//				JPC();
//				gameCamera->CamState = 0;
//				break;
//			case 9:
//				if (EmptyState == 1) {
//				//gameBGM->Stop();
//				gameBGM = NewGO<SoundSource>(0);
//				gameBGM->Init(18);
//				gameBGM->SetVolume(VOL_main);
//				gameBGM->Play(true);
//				m_time = 0;
//				}
//
//			default:	//どの条件にもかからないときは通常BGMを再生
//				//gameBGM->Stop();
//				gameBGM = NewGO<SoundSource>(0);
//				gameBGM->Init(8);
//				gameBGM->SetVolume(VOL_main);
//				gameBGM->Play(true);
//				JPC();
//				break;
//
//			}
//
//		}
//	}
//}

void Game::Render(RenderContext& rc)
{
	fontRender.Draw(rc);
}