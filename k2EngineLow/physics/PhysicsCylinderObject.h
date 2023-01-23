/*!
 * @brief	�~���̓����蔻��B
 */

#pragma once

#include "physics/CylinderCollider.h"
#include "physics/RigidBody.h"

namespace nsK2EngineLow {
	/// <summary>
	/// �~���^�����I�u�W�F�N�g
	/// </summary>
	class PhysicsCylinderObject : public Noncopyable {
	public:
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		PhysicsCylinderObject();
		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~PhysicsCylinderObject();
		/// <summary>
		/// �V�����_�[�̍쐬�B
		/// </summary>
		/// <param name="size">�V�����_�[�̑傫���B</param>
		/// <param name="position">�V�����_�[�̍��W�B</param>
		/// <param name="rotation">�V�����_�[�̉�]�B</param>
		/// <param name="restitution">�V�����_�[�̔����́B</param>
		/// <param name="mass">�V�����_�[�̏d���B0�ɂ���Ɠ����Ȃ��B</param>
		void CreateCylinder(const Vector3 size, const Vector3 position, const Quaternion rotation,
			const float restitution = 0.0f, const float mass = 0.0f);
		/// <summary>
		/// ���C�͂�ݒ肷��B
		/// </summary>
		/// <param name="friction">���C�́B10���ő�l�B</param>
		void SetFriction(float friction)
		{
			m_rigidBody.SetFriction(friction);
		}
		btCollisionObject* GetbtCollisionObject()
		{
			return m_rigidBody.GetBody();
		}

		/// <summary>
		/// ���̂��擾�B
		/// </summary>
		RigidBody* GetRigidBody() {
			return &m_rigidBody;
		}
		/// <summary>
		/// ���̂�j���B
		/// </summary>
		void Release()
		{
			m_rigidBody.Release();
		}
	private:
		CylinderCollider m_cylinderCollider;		//�V�����_�[�R���C�_�[�B
		RigidBody m_rigidBody;						//���́B
	};
}