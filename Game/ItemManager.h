#pragma once
#include "Item.h"
class Player;
class ItemManager {
public:
    void Init(int numItems);                // 複数アイテムを初期化
    void Update(Player* player);            // プレイヤーと当たり判定
    void Render(RenderContext& rc);

private:
    std::vector<std::unique_ptr<Item>> m_items;
};
