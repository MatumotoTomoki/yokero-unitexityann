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
            // �v���C���[�Ƃ̋����`�F�b�N
            float dist = (player->m_position - item->GetPosition()).Length();
            if (dist < 50.0f) { // 50�ȓ��Ȃ�擾
                item->OnPickup();
                player->AddSpeedBoost(3.0f, 300); // ���x�A�b�v(3�{, 300�t���[��)
            }
        }
    }
}

void ItemManager::Render(RenderContext& rc) {
    for (auto& item : m_items) {
        item->Render(rc);
    }
}
