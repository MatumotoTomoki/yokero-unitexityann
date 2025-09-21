#pragma once
#include "Item.h"
class Player;
class ItemManager {
public:
    void Init(int numItems);                // �����A�C�e����������
    void Update(Player* player);            // �v���C���[�Ɠ����蔻��
    void Render(RenderContext& rc);

private:
    std::vector<std::unique_ptr<Item>> m_items;
};
