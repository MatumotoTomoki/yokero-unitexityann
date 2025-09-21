#include "stdafx.h"
#include "ItemManager.h"
#include "Player.h"

void ItemManager::Init(int numItems) {
    m_items.clear();
    m_items.reserve(numItems);

    for (int i = 0; i < numItems; i++) {
        m_items.push_back(std::make_unique<Item>());
    }
}

void ItemManager::Update(Player* player) {
    for (auto& item : m_items) {
        item->Update();

        if (item->IsAlive()) {
            // プレイヤーとの距離チェック
            float dist = (player->m_position - item->GetPosition()).Length();
            if (dist < 50.0f) { // 50以内なら取得
                item->OnPickup();
                player->AddSpeedBoost(3.0f, 300); // 速度アップ(3倍, 300フレーム)
            }
        }
    }
}

void ItemManager::Render(RenderContext& rc) {
    for (auto& item : m_items) {
        item->Render(rc);
    }
}
