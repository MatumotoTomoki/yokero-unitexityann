// EnemyManager.cpp
#include "stdafx.h"
#include "EnemyManager.h"

void EnemyManager::Init(int enemyCount)
{
    m_enemyCount = enemyCount;
    m_enemies.reserve(enemyCount);

    for (int i = 0; i < enemyCount; i++) {
        m_enemies.push_back(std::make_unique<Enemy>());
    }
}

void EnemyManager::Update(Player* player)
{
    for (auto& enemy : m_enemies) {
        if (enemy) enemy->Update(); // ★安全チェック
    }

    for (int i = 0; i < m_enemyCount; i++) {
        if (m_enemies[i] && !m_enemies[i]->IsAlive()) {
            m_enemies[i] = std::make_unique<Enemy>();
        }
    }

    for (auto& enemy : m_enemies) {
        if (enemy && enemy->IsAlive()) {
            float dist = (player->m_position - enemy->GetPosition()).Length();
            if (dist < 50.0f) { // 当たり判定の距離
                player->TakeDamage(1); // プレイヤーのライフを1減らす
            }
        }
    }
}

void EnemyManager::Render(RenderContext& rc)
{
    for (auto& enemy : m_enemies) {
        enemy->Render(rc);
    }
}
