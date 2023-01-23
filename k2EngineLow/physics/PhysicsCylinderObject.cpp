#include "k2EngineLowPreCompile.h"
#include "PhysicsCylinderObject.h"

/*!
* @brief	静的オブジェクト。
*/

namespace nsK2EngineLow {
	PhysicsCylinderObject::PhysicsCylinderObject()
	{
	}
	PhysicsCylinderObject::~PhysicsCylinderObject()
	{
	}
	void PhysicsCylinderObject::CreateCylinder(const Vector3 size, const Vector3 position, const Quaternion rotation,
		const float restitution, const float mass)
	{
		m_cylinderCollider.Init(size);

		RigidBodyInitData rbInfo;
		rbInfo.pos = position;
		rbInfo.rot = rotation;
		rbInfo.collider = &m_cylinderCollider;
		rbInfo.mass = mass;
		rbInfo.restitution = restitution;
		m_rigidBody.Init(rbInfo);
	}
}
