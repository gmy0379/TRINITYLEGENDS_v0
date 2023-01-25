#include "stdafx.h"
#include "JPCball.h"
#include "Game.h"

JPCball::JPCball()
{
	//srand((unsigned int)time(NULL));
	//���f����ǂݍ��ށB
	//btSphereShape(10.0f);
	modelRender.SetRaytracingWorld(false);
	modelRender.Init("Assets/modelData/MEDAL/JPC/Jball2.tkm");
	modelRender.SetScale(Vector3(10.0f, 10.0f, 10.0f));
	//�L�����R��������������B
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

//�X�V�����B
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

	//�G�`������̍X�V�����B
	modelRender.Update();
}

//���ʉ��o�͏���
void JPCball::PlayMusic()
{

}

//�`�揈���B
void JPCball::Render(RenderContext& rc)
{
	//���f����`�悷��B
	modelRender.Draw(rc);
}