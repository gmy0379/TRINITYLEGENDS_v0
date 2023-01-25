#pragma once

//class Bouto;
//�{�[���N���X�B
class Ball2 : public IGameObject
{
public:
	Ball2();
	~Ball2();
	const Vector3& GetPosition() const
	{
		return position;
	}
	//Bouto* bouto;
	//�X�V�����B
	void Update();
	//�`�揈���B
	void Render(RenderContext& rc);
	//���y�̍Đ�
	void PlayMusic();
	void AddMoveSpeed(const Vector3& addMoveSpeed)
	{
		moveSpeed += addMoveSpeed;
	}

int ballState = 0;	//�v���C���[�̃X�e�[�g(���)��\���ϐ��B
private:
	
	//�����o�ϐ��B
	ModelRender modelRender;	//���f�������_�\�B
	Vector3 position;			//���W�B



	//CharacterController characterController;  //�L�����N�^�[�R���g���[���[�B
	Vector3 moveSpeed;		//�ړ����x�B
	Quaternion rotation;  //�N�H�[�^�j�I���B
	Vector3 firstPosition;		//�ŏ��̍��W�B
	

	PhysicsSphereObject physicsSphereObject;

};
