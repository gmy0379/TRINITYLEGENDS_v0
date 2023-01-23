/*!
 * @brief	球の当たり判定。
 */

#pragma once

#include "physics/SphereCollider.h"
#include "physics/RigidBody.h"

namespace nsK2EngineLow {
	/// <summary>
	/// 球型物理オブジェクト
	/// </summary>
	class PhysicsSphereObject : public Noncopyable {
	public:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		PhysicsSphereObject();
		/// <summary>
		/// デストラクタ
		/// </summary>
		~PhysicsSphereObject();
		/// <summary>
		/// 球の作成。
		/// </summary>
		/// <param name="size">球の大きさ。</param>
		/// <param name="position">球の座標。</param>
		/// <param name="rotation">球の回転。</param>
		/// <param name="restitution">球の反発力。</param>
		/// <param name="mass">球の重さ。0にすると動かない。</param>
		void CreateCylinder(const float size, const Vector3 position, const Quaternion rotation,
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
		SphereCollider m_SphereCollider;		//球コライダー。
		RigidBody m_rigidBody;						//剛体。
	};
}