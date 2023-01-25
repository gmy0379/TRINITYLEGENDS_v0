#include "stdafx.h"
#include "Yokoana.h"
#include "Choice.h"

Yokoana::Yokoana()
{
	choice = FindGO<Choice>("choice");
	//コメントアウトする。
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
	
	//CHOICEで設定したレベルの横穴を読み込む。
	switch (choice->sentaku)
	{case 1:
		modelRender.Init("Assets/modelData/MEDAL/L1.tkm");
		break;
	case 2:
		modelRender.Init("Assets/modelData/MEDAL/L2.tkm");
		break;
	case 3:
		modelRender.Init("Assets/modelData/MEDAL/L3.tkm");
		break;
	case 4:
		modelRender.Init("Assets/modelData/MEDAL/L4.tkm");
		break;
	case 5:
		modelRender.Init("Assets/modelData/MEDAL/L5.tkm");
		break;
	case 6:
		modelRender.Init("Assets/modelData/MEDAL/L6.tkm");
		break;
	default:
		modelRender.Init("Assets/modelData/MEDAL/L6.tkm");
	}
	
	modelRender.Update();
	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix());
}

Yokoana::~Yokoana()
{
	DeleteGO(this);
}

void Yokoana::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}