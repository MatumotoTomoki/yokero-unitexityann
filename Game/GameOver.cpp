#include "stdafx.h"
#include "GameOver.h"
#include"Title.h"
#include "sound/SoundEngine.h"
GameOver::GameOver()
{
	spriteRender.Init("Assets/sprite/GameOver.DDS", 1920.0f, 1080.0f);
	//タイトルのBGMを読み込む。
	g_soundEngine->ResistWaveFileBank(2, "Assets/sound/GameOver.wav");
	//タイトルのBGMを再生する。
	gameoverBGM = NewGO<SoundSource>(0);
	gameoverBGM->Init(2);
	gameoverBGM->Play(true);
}

GameOver::~GameOver()
{
	DeleteGO(gameoverBGM);
}

void GameOver::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{

		NewGO<Title>(0);
		DeleteGO(this);
	}
}

void GameOver::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}
