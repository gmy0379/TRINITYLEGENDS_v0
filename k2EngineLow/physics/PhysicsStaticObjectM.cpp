#include "k2EngineLowPreCompile.h"
#include "PhysicsStaticObjectM.h"
/*!
* @brief	静的オブジェクト。
*/

namespace nsK2EngineLow {
	PhysicsStaticObjectM::PhysicsStaticObjectM()
	{
	}
	PhysicsStaticObjectM::~PhysicsStaticObjectM()
	{
	}
	void PhysicsStaticObjectM::CreateFromModel(Model& model, const Matrix& worldMatrix, const float restitution)
	{
		m_meshCollider.CreateFromModel(model, worldMatrix);
		RigidBodyInitData rbInfo;
		rbInfo.collider = &m_meshCollider;
		rbInfo.mass = 0.0f;
		rbInfo.restitution = restitution;
		m_rigidBody.Init(rbInfo);
	}
}
