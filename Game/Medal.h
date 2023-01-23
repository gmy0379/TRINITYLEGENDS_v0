#pragma once

class Counter;
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

	//void AddForce(const Vector3& force, const Vector3& relPos)
	//{
	//	btVector3 btForce;
	//	btVector3 btRelPos;
	//	btForce.setValue(force.x, force.y, force.z);
	//	btRelPos.setValue(relPos.x, relPos.y, relPos.z);
	//	/*position->applyForce(btForce, btRelPos);
	//	position->activate();*/
	//}
	void AddMoveSpeed(const Vector3& addMoveSpeed)
	{
		position += addMoveSpeed;
	}

	/*CharacterControllerCylinder& GetCharacterControllerC()
	{
		return characterControllerC;
	}*/
	/*CollisionObject& GetCollisionObject()
	{
		return collisionObject;
	}*/

	//�ړ������B
	
	void Rotation();
	//�X�e�[�g�Ǘ��B
	//void ManageState();
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

	
	ModelRender modelRender;	//���f�������_�\�B
	Counter* counter;
	Quaternion rotation;  //�N�H�[�^�j�I���B
	int playerState = 0;	//�v���C���[�̃X�e�[�g(���)��\���ϐ��B
	FontRender fontRender;
	int M = 0;

	PhysicsCylinderObject physicsCylinderObject;
};
