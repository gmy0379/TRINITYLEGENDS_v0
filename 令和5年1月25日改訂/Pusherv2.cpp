#include "stdafx.h"
#include "Pusherv2.h"

Pusherv2::Pusherv2()
{
	//モデルを読み込む。
	modelRender.Init("Assets/modelData/MEDAL/pusher_daitai.tkm");
	//キャラコンを初期化する。
	position = (Vector3(-123.992f, 110.747f, -483.082f));
	characterController.Init(3.0f, 10.0f, position);
	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix());
}

Pusherv2::~Pusherv2()
{

}
int moveCount = 0;
float framecount = 0;
//更新処理。
void Pusherv2::Update()
{
	framecount++;
	//移動処理。
	Move();

	//絵描きさんの更新処理。
	modelRender.Update();
}

void Pusherv2::Move()
{

	switch (moveCount) {
	case 0:
		moveSpeed.z = 90.0f;
		if (framecount == 60) {
			moveCount = 1;
			framecount = 0;
		}
		break;
	case 1:
		moveSpeed.z = -90.0f;
		if (framecount == 60) {
			moveCount = 0;
			framecount = 0;
		}
	}

	//キャラクターコントローラーを使って座標を移動させる。
	position = characterController.Execute(moveSpeed, 1.0f / 60.0f);

	//絵描きさんに座標を教える。
	modelRender.SetPosition(position);
}

//描画処理。
void Pusherv2::Render(RenderContext& rc)
{
	//モデルを描画する。
	modelRender.Draw(rc);
	//フォントを描画する。
	fontRender.Draw(rc);
}