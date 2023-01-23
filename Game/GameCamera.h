#pragma once

class Medal;
//class Rjpc;
//class Ajpc;
//class Pjpc;
//ゲーム中のカメラを制御する。
class GameCamera : public IGameObject
{
public:
	GameCamera();
	~GameCamera();
	bool Start();
	void Update();
	void ManageState();
	Medal* medal;
	/*Rjpc* j1;
	Ajpc* j2;
	Pjpc* j3;*/
	/////////////////////////////////////
	//メンバ変数
	/////////////////////////////////////
	Vector3 m_toCameraPos;	//注視点から視点に向かうベクトル。
	Vector3 target;			//注視点

	int CamState = 0;		//カメラステート(カメラの注視点を変更予定)
};
