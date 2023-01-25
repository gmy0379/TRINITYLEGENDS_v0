#include "stdafx.h"
#include "JPCball.h"
#include "Game.h"

JPCball::JPCball()
{
	//srand((unsigned int)time(NULL));
	//モデルを読み込む。
	//btSphereShape(10.0f);
	modelRender.SetRaytracingWorld(false);
	modelRender.Init("Assets/modelData/MEDAL/JPC/Jball2.tkm");
	modelRender.SetScale(Vector3(10.0f, 10.0f, 10.0f));
	//キャラコンを初期化する。
	position = (Vector3(-120.768f, 880.000f, -612.369f));
	/*characterController.Init(25.0f, 0.0f, position-(Vector3(0.0f,200.0f,0.0f)));
	characterController.SetPosition(position);*/

	physicsSphereObject.CreateCylinder(28.0f,
		position, rotation, 0.0f, 10.0f);
	physicsSphereObject.GetRigidBody()->AddForce({ 0.0f,0.0f,-0.4f }, position);

	game = FindGO<Game>("game");
}

JPCball::~JPCball()
{

}

//更新処理。
void JPCball::Update()
{

	//Rotation();
	//Move();
	//PlayMusic();

	if (position.z <= -635.0f) {
		game->m_time += 0;
	}

	physicsSphereObject.GetRigidBody()->GetPositionAndRotation(position, rotation);
	modelRender.SetPosition(position);
	modelRender.SetRotation(rotation);

	//絵描きさんの更新処理。
	modelRender.Update();
}

//効果音出力処理
void JPCball::PlayMusic()
{

}

//描画処理。
void JPCball::Render(RenderContext& rc)
{
	//モデルを描画する。
	modelRender.Draw(rc);
}