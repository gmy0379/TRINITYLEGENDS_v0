/*!
 * @brief	円柱の当たり判定。
 */

#pragma once

#include "physics/CylinderCollider.h"
#include "physics/RigidBody.h"

namespace nsK2EngineLow {
	/// <summary>
	/// 円柱型物理オブジェクト
	/// </summary>
	class PhysicsCylinderObject : public Noncopyable {
	public:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		PhysicsCylinderObject();
		/// <summary>
		/// デストラクタ
		/// </summary>
		~PhysicsCylinderObject();
		/// <summary>
		/// シリンダーの作成。
		/// </summary>
		/// <param name="size">シリンダーの大きさ。</param>
		/// <param name="position">シリンダーの座標。</param>
		/// <param name="rotation">シリンダーの回転。</param>
		/// <param name="restitution">シリンダーの反発力。</param>
		/// <param name="mass">シリンダーの重さ。0にすると動かない。</param>
		void CreateCylinder(const Vector3 size, const Vector3 position, const Quaternion rotation,
			const float restitution = 0.0f, const float mass = 0.0f);
		/// <summary>
		/// 摩擦力を設定する。
		/// </summary>
		/// <param name="friction">摩擦力。10が最大値。</param>
		void SetFriction(float friction)
		{
			m_rigidBody.SetFriction(friction);
		}
		btCollisionObject* GetbtCollisionObject()
		{
			return m_rigidBody.GetBody();
		}

		/// <summary>
		/// 剛体を取得。
		/// </summary>
		RigidBody* GetRigidBody() {
			return &m_rigidBody;
		}
		/// <summary>
		/// 剛体を破棄。
		/// </summary>
		void Release()
		{
			m_rigidBody.Release();
		}
	private:
		CylinderCollider m_cylinderCollider;		//シリンダーコライダー。
		RigidBody m_rigidBody;						//剛体。
	};
}