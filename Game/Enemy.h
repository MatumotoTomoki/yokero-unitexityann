#pragma once
// エネミークラス

class Enemy : public IGameObject
{
public:
    Enemy();
    ~Enemy();

    // 更新処理
    void Update();
    // 描画処理
    void Render(RenderContext& rc);
    // 回転処理
    void Rotation();

    bool IsAlive() const { return m_isAlive; }
    const Vector3& GetPosition() const { return m_position; }
private:
    ModelRender m_modelRender;              // モデルレンダー
    Vector3 m_position;                     // 現在座標
    CharacterController m_characterController; // キャラクターコントローラー
    Quaternion m_rotation;                  // 回転

    // --- 移動管理 ---
    Vector3 m_spawnPos;     // 出現位置
    Vector3 m_goalPos;      // ゴール位置
    Vector3 m_direction;    // 移動方向
    float   m_speed;        // 移動速度
    bool    m_isAlive;      // 生存フラグ
};
