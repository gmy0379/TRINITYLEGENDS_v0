#pragma once
//#include "Level3DRender/LevelRender.h"
#include "sound/SoundSource.h"

//���_���Q�[���̊�{�N���X
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

//�{�[���֌W�N���X
class Bout;
class Bouto;
class Bout2;
class Ball1;
class Ball2;
class Ball3;


//JPC�֌W�N���X(�Ԃɍ��������ɂȂ��̂Ŏg�p��f�O)
//class Rjpc;
//class Ajpc;
//class Pjpc;
//class JPCnot;
//class JPCnot2;
//class JPCball;

//�v���l�b�g���b�V���̃N���X(�{�����͂��Ȃ��\��)
//class PR_Doom;
//class PR_wing;
//class PR_not;

//Game�V�[�����Ǘ�����N���X�B
class Game : public IGameObject
{
public:
	Game();
	~Game();
	//�X�V�����B
	void Update();
	//�X�e�[�g�Ǘ��B
	void ManageState();

	//�eJPC�I����̊Ǘ�
	void JPC();

	//�{�[����������
	void Ballfall();

	//JPC�̔z������
	//void JPCwin();
	
	//BGM�̍Đ����� 
	void BGM();

	//�{�[���l��(JPC���I)���̏���
	void Ballwin();

/// ����������B
	void InitSky();

	SkyCube* m_skyCube = nullptr;		//�X�J�C�L���[�u�B
	Gameover* gameover;
	GameClear* gameclear;
	Choice* choice;
	Text* text;
	Haitou* haitou;
	Pusher* pusher;				//�v�b�V���[
	Counter* counter;
	Medal* medal;			//�v���C���[�B
	GameCamera* gameCamera;			//�Q�[���J�����B
	BackGround* backGround;		//�T�e���C�g�{��
	Bout* bout;
	Bout2* bout2;
	Bouto* bouto;
	Ball1* ball1;
	Ball2* ball2;
	Ball3* ball3;
	Yokoana* Yoko0;				//����
	SoundSource* gameBGM;		//�Q�[������BGM�B
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

