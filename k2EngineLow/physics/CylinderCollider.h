#pragma once
#include "physics/ICollider.h"

namespace nsK2EngineLow {
	class CylinderCollider : public ICollider
	{
	public:
		/// <summary>
		/// 初期化
		/// </summary>
		/// <param name="radius"></param>
		/// <param name="height"></param>
		void Init(const Vector3& halfExtents)
		{
			btVector3 bV = btVector3(halfExtents.x, halfExtents.y, halfExtents.z);
			m_shape = std::make_unique<btCylinderShape>(bV);
			//m_radius = radius;
			//m_height = height;
		}
		/// <summary>
		/// BulletPhysicsのコリジョン形状を取得。
		/// </summary>
		/// <returns></returns>
		btCollisionShape* GetBody() const override
		{
			return m_shape.get();
		}
		/// <summary>
		/// 半径を取得。
		/// </summary>
		/// <returns></returns>
		float GetRadius() const
		{
			return m_radius;
		}
		/// <summary>
		/// 高さを取得。
		/// </summary>
		/// <returns></returns>
		float GetHeight() const
		{
			return m_height;
		}
	private:
		std::unique_ptr<btCylinderShape>	m_shape;
		float m_radius = 0.0f;
		float m_height = 0.0f;
	};
}

