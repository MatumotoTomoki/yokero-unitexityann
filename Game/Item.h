class Item : public IGameObject
{
public:
    Item();
    ~Item();

    void Update();
    void Render(RenderContext& rc);

    bool IsAlive() const { return m_isAlive; }
    void Respawn();     // ランダム座標に再出現
    void OnPickup();    // プレイヤーが拾ったとき呼ぶ
    const Vector3& GetPosition() const { return m_position; }

private:
    ModelRender m_modelRender;
    

    Vector3 m_position;
    Vector3 m_spawnPos;
    Vector3 m_goalPos;
    Vector3 m_direction;

    bool m_isAlive = true;
    int m_respawnTimer = 0;
    int m_respawnDelay = 300;

    float m_speed = 7.0f; // アイテム移動速度
};
