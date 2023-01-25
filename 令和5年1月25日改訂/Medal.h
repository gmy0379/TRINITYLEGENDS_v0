#pragma once

class Counter;
class Choice;
//�v���C���[�N���X�B
class Medal : public IGameObject
{
public:
	Medal();
	~Medal();
	//�X�V�����B
	void Update();
	//�`�揈���B
	void Render(RenderContext& rc);
	const Vector3& GetPosition() const
	{
		return position;
	}

	void AddMoveSpeed(const Vector3& addMoveSpeed)
	{
		position += addMoveSpeed;
	}

	//�ړ������B
	
	void Rotation();
	//�X�e�[�g�Ǘ��B
	void LevelState();
	//�A�j���[�V�����̍Đ��B
	//void PlayAnimation();
	//���y�̍Đ�
	void PlayMusic();

	CollisionObject* collisionObject;		//�R���W�����I�u�W�F�N�g�B
	Vector3 position;			//���W�B
	Vector3 firstPosition;		//�ŏ��̍��W�B
	Vector3 moveSpeed;		//�ړ����x�B
	private:
	//�����o�ϐ�
	//void Move();

	Choice* choice;
	ModelRender modelRender;	//���f�������_�\�B
	Counter* counter;
	Quaternion rotation;  //�N�H�[�^�j�I���B
	int playerState = 0;	//�v���C���[�̃X�e�[�g(���)��\���ϐ��B
	FontRender fontRender;
	int M = 0;
	int GetSentaku = 0;

	PhysicsCylinderObject physicsCylinderObject;
};
