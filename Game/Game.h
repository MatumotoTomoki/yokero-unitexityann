#pragma once
#include "EnemyManager.h"
#include "ItemManager.h"
class Player;
class GameCamera;
class Stage;
class Enemy;
class Item;
class EnemyManager;
class  ItemManager;
class Game : public IGameObject
{
public:
	Game();
	~Game();
	void Update();
	void Init();
	void Render(RenderContext& rc);
	//�����o�[�ϐ��B
	Player* player = nullptr;			//�v���C���[�B
	GameCamera* gameCamera = nullptr;			//�Q�[���J�����B
	Stage* stage; //�X�e�[�W
	SoundSource* gamebgm;
	Item* item;
	Enemy* enemy;
	FontRender fontRender; //����
	int m_defeatCount = 0;
	float m_elapsedTime = 0.0f; // �o�ߎ��ԁi�b�j
	FontRender timeFontRender; // ���ԕ\���p�̃t�H���g
	
	bool m_isGameClear = false;
	float m_itemRespawnTimer = 0.0f;
	EnemyManager m_enemyManager;
	ItemManager m_itemManager;
private:

	Vector3 m_pos;
	
};

