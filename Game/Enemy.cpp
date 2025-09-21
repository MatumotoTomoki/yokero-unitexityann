#include "stdafx.h"
#include "Enemy.h"

// 出現候補 (スタート → ゴール のペア)
struct SpawnPair {
    Vector3 start;
    Vector3 goal;
};

static std::vector<SpawnPair> spawnPairs = {
    { { -1239.32f, -50.0f, -1450.31f }, { 1294.64f, -50.0f, 1423.91f } },
    { { 649.96f,   -50.0f, 1788.96f },  { -1899.03f, -50.0f, 205.41f } },
    { { 1921.11f,  -50.0f, -302.63f },  { -1894.63f, -50.0f, 284.36f } },
    { { 1831.24f,  -50.0f, -372.61f },  { 0.0f, -50.0f, -1937.72f } },
    { { 0.0f,      -50.0f, 1877.84f },  { -500.0f, -50.0f, -1800.0f } } // ←追加ペア
};

Enemy::Enemy()
{
    // モデル読み込み
    m_modelRender.Init("Assets/modelData/Barry.tkm");
    m_modelRender.Update();

    // ランダムにスタート＆ゴールを選ぶ
    int index = rand() % spawnPairs.size();
    m_spawnPos = spawnPairs[index].start;
    m_goalPos = spawnPairs[index].goal;

    // 初期位置セット
    m_position = m_spawnPos;

    // ゴール方向を計算
    m_direction = m_goalPos - m_spawnPos;
    m_direction.Normalize();

    m_speed = 10.0f;
    m_isAlive = true;

    // モデルに位置を反映
    m_modelRender.SetPosition(m_position);
    m_characterController.Init(30.0f, 30.0f, m_position);
}

Enemy::~Enemy()
{
}

void Enemy::Rotation()
{
    // エネミーを180度回転させる
    m_rotation.SetRotationDegY(180.0f);
    m_modelRender.SetRotation(m_rotation);
}

void Enemy::Update()
{
    if (!m_isAlive) {
        // 新しい座標ペアを選んでリスポーン
        int index = rand() % spawnPairs.size();
        m_spawnPos = spawnPairs[index].start;
        m_goalPos = spawnPairs[index].goal;

        m_position = m_spawnPos;
        m_direction = m_goalPos - m_spawnPos;
        m_direction.Normalize();

        m_isAlive = true;
        return; // このフレームは終了
    }

    // 移動処理
    m_position += m_direction * m_speed;
    m_modelRender.SetPosition(m_position);

    // ゴール到達チェック
    if ((m_goalPos - m_position).Length() < 10.0f) {
        m_isAlive = false; // → 次のフレームでリスポーン
    }

    m_modelRender.Update();
}


void Enemy::Render(RenderContext& rc)
{
    if (!m_isAlive) return;
    m_modelRender.Draw(rc);
}
