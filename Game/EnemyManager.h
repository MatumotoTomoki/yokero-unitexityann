// EnemyManager.h
#pragma once
#include "Enemy.h"
#include"Player.h"
class Player;
class EnemyManager {
public:
    void Init(int enemyCount);   // ‰Šú‰»
    void Update(Player* player);               // XV
    void Render(RenderContext& rc); // •`‰æ

private:
    int m_enemyCount = 0; // Å‘å“¯”
    std::vector<std::unique_ptr<Enemy>> m_enemies;
};

