#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "GameCamera.h"
#include "Stage.h"
#include "Enemy.h"
#include"GameClear.h"
#include"GameOver.h"
#include "EnemyManager.h"
#include "ItemManager.h"

Game::Game()
{
	//プレイヤーのオブジェクトを作る。
	player = NewGO<Player>(0, "player");

	//ゲームカメラのオブジェクトを作る。
	gameCamera = NewGO<GameCamera>(0, "gamecamera");

	//ステージを作る
	Stage* stage = NewGO<Stage>(0, "stage");

	g_soundEngine->ResistWaveFileBank(4, "Assets/sound/GameBgm.wav");
	gamebgm = NewGO<SoundSource>(0);
	gamebgm->Init(4);
	gamebgm->Play(true);

	m_enemyManager.Init(3);

	m_itemManager.Init(3); // アイテムを3個生成
}

Game::~Game()
{
	//プレイヤーを削除する。
	DeleteGO(player);
	//ゲームカメラを削除する。
	DeleteGO(gameCamera);
	//背景を削除する。
	DeleteGO(stage);
	//エネミーを削除する。
	DeleteGO(enemy);
	//ゲームBGMを削除する。
	DeleteGO(gamebgm);
	//アイテムを削除する。
	DeleteGO(item);
}



void Game::Init()
{
	m_enemyManager.Init(3); // 常に3体
}

void Game::Update()
{
	if (!m_isGameClear) {
		m_elapsedTime += 1.0f / 60.0f;

		if (m_elapsedTime >= 60.0f) {
			m_isGameClear = true;

			// GameClearシーンを作成
			NewGO<GameClear>(0);

			// このGameを削除（もうプレイ中じゃないから）
			DeleteGO(this);
			return;
		}
	}

	// 経過時間表示
	wchar_t text[256];
	swprintf_s(text, 256, L"Time: %.2f sec", m_elapsedTime);
	timeFontRender.SetText(text);
	timeFontRender.SetPosition(Vector3(-100.0f, 300.0f, 0.0f));
	timeFontRender.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

	if (!m_isGameClear) {
		m_enemyManager.Update(player);
		m_itemManager.Update(player);
	}

	// プレイヤーが死んだらゲームオーバー画面に遷移
	if (!player->IsAlive()) {
		NewGO<GameOver>(0); // ゲームオーバー画面を生成
		DeleteGO(this);     // ゲーム画面を削除
		return;
	}
}

void Game::Render(RenderContext& rc)
{
	fontRender.Draw(rc); 
	m_enemyManager.Render(rc);
	m_itemManager.Render(rc);
	timeFontRender.Draw(rc);
}