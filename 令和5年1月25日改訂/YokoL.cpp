#include "stdafx.h"
#include "YokoL.h"

YokoL::YokoL()
{
	//モデルを読み込む。
	modelRender.Init("Assets/modelData/MEDAL/yokoanaL.tkm");
	//キャラコンを初期化する。
	position = (Vector3(-400.758f, -46.954f, -260.934f));
	characterController.Init(3.0f, 10.0f, position);
}

YokoL::~YokoL()
{

}
//更新処理。
void YokoL::Update()
{
	//移動処理。
	Move();

	//絵描きさんの更新処理。
	modelRender.Update();
}

void YokoL::Move()
{

	//キャラクターコントローラーを使って座標を移動させる。
	position = characterController.Execute(moveSpeed, 1.0f / 60.0f);

	//絵描きさんに座標を教える。
	modelRender.SetPosition(position);
}

//描画処理。
void YokoL::Render(RenderContext& rc)
{
	//モデルを描画する。
	modelRender.Draw(rc);
	//フォントを描画する。
	fontRender.Draw(rc);
}
