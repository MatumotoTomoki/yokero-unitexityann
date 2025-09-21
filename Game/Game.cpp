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
	//�v���C���[�̃I�u�W�F�N�g�����B
	player = NewGO<Player>(0, "player");

	//�Q�[���J�����̃I�u�W�F�N�g�����B
	gameCamera = NewGO<GameCamera>(0, "gamecamera");

	//�X�e�[�W�����
	Stage* stage = NewGO<Stage>(0, "stage");

	g_soundEngine->ResistWaveFileBank(4, "Assets/sound/GameBgm.wav");
	gamebgm = NewGO<SoundSource>(0);
	gamebgm->Init(4);
	gamebgm->Play(true);

	m_enemyManager.Init(3);

	m_itemManager.Init(3); // �A�C�e����3����
}

Game::~Game()
{
	//�v���C���[���폜����B
	DeleteGO(player);
	//�Q�[���J�������폜����B
	DeleteGO(gameCamera);
	//�w�i���폜����B
	DeleteGO(stage);
	//�G�l�~�[���폜����B
	DeleteGO(enemy);
	//�Q�[��BGM���폜����B
	DeleteGO(gamebgm);
	//�A�C�e�����폜����B
	DeleteGO(item);
}



void Game::Init()
{
	m_enemyManager.Init(3); // ���3��
}

void Game::Update()
{
	if (!m_isGameClear) {
		m_elapsedTime += 1.0f / 60.0f;

		if (m_elapsedTime >= 60.0f) {
			m_isGameClear = true;

			// GameClear�V�[�����쐬
			NewGO<GameClear>(0);

			// ����Game���폜�i�����v���C������Ȃ�����j
			DeleteGO(this);
			return;
		}
	}

	// �o�ߎ��ԕ\��
	wchar_t text[256];
	swprintf_s(text, 256, L"Time: %.2f sec", m_elapsedTime);
	timeFontRender.SetText(text);
	timeFontRender.SetPosition(Vector3(-100.0f, 300.0f, 0.0f));
	timeFontRender.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

	if (!m_isGameClear) {
		m_enemyManager.Update(player);
		m_itemManager.Update(player);
	}

	// �v���C���[�����񂾂�Q�[���I�[�o�[��ʂɑJ��
	if (!player->IsAlive()) {
		NewGO<GameOver>(0); // �Q�[���I�[�o�[��ʂ𐶐�
		DeleteGO(this);     // �Q�[����ʂ��폜
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