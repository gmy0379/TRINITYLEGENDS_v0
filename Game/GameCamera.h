#pragma once

class Medal;
//class Rjpc;
//class Ajpc;
//class Pjpc;
//�Q�[�����̃J�����𐧌䂷��B
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
	//�����o�ϐ�
	/////////////////////////////////////
	Vector3 m_toCameraPos;	//�����_���王�_�Ɍ������x�N�g���B
	Vector3 target;			//�����_

	int CamState = 0;		//�J�����X�e�[�g(�J�����̒����_��ύX�\��)
};
