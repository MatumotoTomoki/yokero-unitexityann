class Item : public IGameObject
{
public:
    Item();
    ~Item();

    void Update();
    void Render(RenderContext& rc);

    bool IsAlive() const { return m_isAlive; }
    void Respawn();     // �����_�����W�ɍďo��
    void OnPickup();    // �v���C���[���E�����Ƃ��Ă�
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

    float m_speed = 7.0f; // �A�C�e���ړ����x
};
