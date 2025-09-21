// EnemyManager.h
#pragma once
#include "Enemy.h"
#include"Player.h"
class Player;
class EnemyManager {
public:
    void Init(int enemyCount);   // ������
    void Update(Player* player);               // �X�V
    void Render(RenderContext& rc); // �`��

private:
    int m_enemyCount = 0; // �ő哯����
    std::vector<std::unique_ptr<Enemy>> m_enemies;
};

