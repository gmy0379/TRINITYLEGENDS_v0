#pragma once
#include "sound/SoundSource.h"

class game;
//ゲームクリア
class GameClear:public IGameObject
{
public:
	GameClear();
	~GameClear();
	//更新処理
	void Update();
	//描画処理
	void Render(RenderContext& rc);

	//メンバ変数	
	SpriteRender spriteRender;   //スプライトレンダー
	SoundSource* titleBGM;			//タイトルのBGM。
	FontRender* fontRender;
};

