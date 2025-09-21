#pragma once
// �G�l�~�[�N���X

class Enemy : public IGameObject
{
public:
    Enemy();
    ~Enemy();

    // �X�V����
    void Update();
    // �`�揈��
    void Render(RenderContext& rc);
    // ��]����
    void Rotation();

    bool IsAlive() const { return m_isAlive; }
    const Vector3& GetPosition() const { return m_position; }
private:
    ModelRender m_modelRender;              // ���f�������_�[
    Vector3 m_position;                     // ���ݍ��W
    CharacterController m_characterController; // �L�����N�^�[�R���g���[���[
    Quaternion m_rotation;                  // ��]

    // --- �ړ��Ǘ� ---
    Vector3 m_spawnPos;     // �o���ʒu
    Vector3 m_goalPos;      // �S�[���ʒu
    Vector3 m_direction;    // �ړ�����
    float   m_speed;        // �ړ����x
    bool    m_isAlive;      // �����t���O
};
