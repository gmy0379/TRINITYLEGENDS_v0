#pragma once

//ゲームクリア
class Gameover :public IGameObject
{
public:
	Gameover();
	~Gameover();
	//更新処理
	void Update();
	//描画処理
	void Render(RenderContext& rc);

	//メンバ変数	
	SpriteRender spriteRender;   //スプライトレンダー
	SoundSource* titleBGM;			//タイトルのBGM。
};