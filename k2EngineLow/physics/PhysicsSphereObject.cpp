#include "k2EngineLowPreCompile.h"
#include "PhysicsSphereObject.h"

/*!
* @brief	静的オブジェクト。
*/

namespace nsK2EngineLow {
	PhysicsSphereObject::PhysicsSphereObject()
	{
	}
	PhysicsSphereObject::~PhysicsSphereObject()
	{
	}
	void PhysicsSphereObject::CreateCylinder(const float size, const Vector3 position, const Quaternion rotation,
		const float restitution, const float mass)
	{
		m_SphereCollider.Create(size);

		RigidBodyInitData rbInfo;
		rbInfo.pos = position;
		rbInfo.rot = rotation;
		rbInfo.collider = &m_SphereCollider;
		rbInfo.mass = mass;
		rbInfo.restitution = restitution;
		m_rigidBody.Init(rbInfo);
	}
}
