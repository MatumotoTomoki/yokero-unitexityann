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
	//メンバー変数。
	Player* player = nullptr;			//プレイヤー。
	GameCamera* gameCamera = nullptr;			//ゲームカメラ。
	Stage* stage; //ステージ
	SoundSource* gamebgm;
	Item* item;
	Enemy* enemy;
	FontRender fontRender; //文字
	int m_defeatCount = 0;
	float m_elapsedTime = 0.0f; // 経過時間（秒）
	FontRender timeFontRender; // 時間表示用のフォント
	
	bool m_isGameClear = false;
	float m_itemRespawnTimer = 0.0f;
	EnemyManager m_enemyManager;
	ItemManager m_itemManager;
private:

	Vector3 m_pos;
	
};

