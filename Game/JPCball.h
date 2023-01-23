#pragma once
class Game;
class JPCball :public IGameObject
{
public:
	JPCball();
	~JPCball();
	//�X�V�����B
	void Update();
	//�`�揈���B
	void Render(RenderContext& rc);
	/*const Vector3& GetPosition() const
	{
		return position;
	}*/

	//�ړ������B

	void Rotation();
	//�X�e�[�g�Ǘ��B
	//void ManageState();
	//�A�j���[�V�����̍Đ��B
	//void PlayAnimation();
	//���y�̍Đ�
	void PlayMusic();

	Game* game;

	Vector3 position;			//���W�B
	Vector3 firstPosition;		//�ŏ��̍��W�B
	PhysicsSphereObject physicsSphereObject;
private:
	//�����o�ϐ�
	void Move();
	ModelRender modelRender;	//���f�������_�\�B
	//CharacterController characterController;  //�L�����N�^�[�R���g���[���[�B
	Quaternion rotation;  //�N�H�[�^�j�I���B
	int playerState = 0;	//�v���C���[�̃X�e�[�g(���)��\���ϐ��B
	FontRender fontRender;
	int M = 0;

};

