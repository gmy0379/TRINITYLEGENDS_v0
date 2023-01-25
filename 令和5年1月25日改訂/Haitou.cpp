#include "stdafx.h"
#include "Haitou.h"
#include "Game.h"
#include "Counter.h"
#include "Text.h"
#include "Ball1.h"
#include "Ball2.h"
#include "Ball3.h"
#include <iostream>

Haitou::Haitou()
{
	counter = FindGO<Counter>("counter");
	game = FindGO<Game>("game");
	/*ball1 = FindGO<Ball1>("ball1");
	ball2 = FindGO<Ball2>("ball2");
	ball3 = FindGO<Ball3>("ball3");*/
}

Haitou::~Haitou()
{

}

void Haitou::Update()
{
	if (game == nullptr) {
		game = FindGO<Game>("game");
		return;
	}
	//if (ball1 == nullptr) {
	//	ball1 = FindGO<Ball1>("ball1");
	//	return;
	//}
	//if (ball2 == nullptr) {
	//	ball2 = FindGO<Ball2>("ball2");
	//	return;
	//}
	//if (ball3 == nullptr) {
	//	ball3 = FindGO<Ball3>("ball3");
	//	return;
	//}

//表示するテキストを設定。

//win枚数表示
	wchar_t wcsbuf[256];

//if (State==1) {
	//if (game->win != 0) {

	//フォントの位置を設定。
	//wintext.SetPosition(Vector3(180.0f, 400.0f, 0.0f));
	wintext.SetPosition(Vector3(-200.0f, 300.0f, 0.0f));
	if (game->win > 1000&&game->win<=1500) {
		fcount++;
		swprintf_s(wcsbuf, 256, L"CONGRATURATIONS!!\nルビーJP %d win", game->win);
		wintext.SetColor(Vector4(1.0f, 0.0f, 0.2f, 1.0f));
		wintext.SetShadowParam(true, 0.3f, Vector4(0.0f, 0.0f, 0.0f, 0.4f));
		if (State == 0) {
			game->m_time = 0;
			State = 1;
		}
		if (fcount > 300) {
			game->win = 0;
			State = 0;
		}
	}
	else if (game->win > 1500 && game->win <= 3000) {
		fcount++;
		swprintf_s(wcsbuf, 256, L"CONGRATURATIONS!!\nアクアマリンJP %d win", game->win);
		wintext.SetColor(Vector4(0.2f, 0.2f, 1.0f, 1.0f));
		wintext.SetShadowParam(true, 0.3f, Vector4(0.0f, 0.0f, 0.0f, 0.4f));
		if (State == 0) {
			game->m_time = 0;
			State = 1;
		}
		if (fcount > 300) {
			game->win = 0;
			State = 0;
		}
	}
	else if (game->win > 3000 && game->win <= 4500) {
		fcount++;
		swprintf_s(wcsbuf, 256, L"CONGRATURATIONS!!\nパイライトJP %d win", game->win);
		wintext.SetColor(Vector4(1.0f, 1.0f, 0.1f, 0.8f));
		wintext.SetShadowParam(true, 0.3f, Vector4(0.0f, 0.0f, 0.0f, 0.4f));
		if (State == 0) {
			game->m_time = 0;
			State = 1;
		}
		if (fcount > 500) {
			game->win = 0;
			State = 0;
		}
	}
	else if (game->win > 4500) {
		fcount++;
		swprintf_s(wcsbuf, 256, L"CONGRATURATIONS!!\nパイライトJP %d win", game->win);
		wintext.SetColor(Vector4(1.0f, 1.0f, 0.1f, 0.6f));
		wintext.SetShadowParam(true, 0.3f, Vector4(0.0f, 0.0f, 0.0f, 0.4f));
		if (State == 0) {
			game->m_time = 0;
			State = 1;
		}
		if (fcount > 500) {
			game->win = 0;
			State = 0;
		}
	}
	else if(game->win<=1000&&game->win>0){
		fcount++;
		if (game->win > 100&&game->win<=300) {
			wintext.SetColor(Vector4(0.8f, 0.2f, 0.2f, 1.0f));
		}
		swprintf_s(wcsbuf, 256, L"%d win", game->win);
		wintext.SetShadowParam(true, 0.3f, Vector4(0.0f, 0.0f, 0.0f, 0.4f));
		if (State == 0) {
		game->m_time = 0;
		//game->m_time += 0.0f;
		State = 1;
		fcount = 0;
		}
		if (fcount>500) {
			game->win = 0;
			State = 0;
		}

	}
	else
	{
		//counter = FindGO<Counter>("counter");
	swprintf_s(wcsbuf, 256, L"ペイアウト率 \n%g ％", counter->PO);
	wintext.SetColor(0.5f, 0.0f, 0.0f, 1.0f);
	wintext.SetShadowParam(true, 0.3f, Vector4(0.0f, 0.0f, 0.0f, 0.4f));
	}

	wintext.SetText(wcsbuf);
	wintext.SetPosition(Vector3(-900.0f, 100.0f, 0.0f));
	//フォントの大きさを設定。
	wintext.SetScale(1.5f);
}



//if (RJP >= 2999.99f) {
//	RJP = 3000.0f;
//}
//
//if (AJP >= 4999.99f) {
//	AJP = 5000.0f;
//}
//
//if (PJP >= 9999.99f) {
//	PJP = 10000.0f;
//}
//
//if (fcount > 800)
//fcount = 0;
//}

void Game::Ballwin()
{
		float GET_main = 1.0f;
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
	}

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

void Haitou::ManageState()
{
	/*switch (State)
	{
	case 1:
		addR += g_gameTime->GetFrameDeltaTime() * 0;
		addA += g_gameTime->GetFrameDeltaTime() * 0;
		addP += g_gameTime->GetFrameDeltaTime() * 0;
		break;
	default:
		float rjpc = (RJP + addR);

		addR += g_gameTime->GetFrameDeltaTime();
		addA += g_gameTime->GetFrameDeltaTime() * 1.2f;
		addP += g_gameTime->GetFrameDeltaTime() * 6.5f;
		break;
	}*/
}

void Haitou::Render(RenderContext& rc)
{
	wintext.Draw(rc);
}

