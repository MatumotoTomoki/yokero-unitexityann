#include "stdafx.h"
#include "Enemy.h"

// �o����� (�X�^�[�g �� �S�[�� �̃y�A)
struct SpawnPair {
    Vector3 start;
    Vector3 goal;
};

static std::vector<SpawnPair> spawnPairs = {
    { { -1239.32f, -50.0f, -1450.31f }, { 1294.64f, -50.0f, 1423.91f } },
    { { 649.96f,   -50.0f, 1788.96f },  { -1899.03f, -50.0f, 205.41f } },
    { { 1921.11f,  -50.0f, -302.63f },  { -1894.63f, -50.0f, 284.36f } },
    { { 1831.24f,  -50.0f, -372.61f },  { 0.0f, -50.0f, -1937.72f } },
    { { 0.0f,      -50.0f, 1877.84f },  { -500.0f, -50.0f, -1800.0f } } // ���ǉ��y�A
};

Enemy::Enemy()
{
    // ���f���ǂݍ���
    m_modelRender.Init("Assets/modelData/Barry.tkm");
    m_modelRender.Update();

    // �����_���ɃX�^�[�g���S�[����I��
    int index = rand() % spawnPairs.size();
    m_spawnPos = spawnPairs[index].start;
    m_goalPos = spawnPairs[index].goal;

    // �����ʒu�Z�b�g
    m_position = m_spawnPos;

    // �S�[���������v�Z
    m_direction = m_goalPos - m_spawnPos;
    m_direction.Normalize();

    m_speed = 10.0f;
    m_isAlive = true;

    // ���f���Ɉʒu�𔽉f
    m_modelRender.SetPosition(m_position);
    m_characterController.Init(30.0f, 30.0f, m_position);
}

Enemy::~Enemy()
{
}

void Enemy::Rotation()
{
    // �G�l�~�[��180�x��]������
    m_rotation.SetRotationDegY(180.0f);
    m_modelRender.SetRotation(m_rotation);
}

void Enemy::Update()
{
    if (!m_isAlive) {
        // �V�������W�y�A��I��Ń��X�|�[��
        int index = rand() % spawnPairs.size();
        m_spawnPos = spawnPairs[index].start;
        m_goalPos = spawnPairs[index].goal;

        m_position = m_spawnPos;
        m_direction = m_goalPos - m_spawnPos;
        m_direction.Normalize();

        m_isAlive = true;
        return; // ���̃t���[���͏I��
    }

    // �ړ�����
    m_position += m_direction * m_speed;
    m_modelRender.SetPosition(m_position);

    // �S�[�����B�`�F�b�N
    if ((m_goalPos - m_position).Length() < 10.0f) {
        m_isAlive = false; // �� ���̃t���[���Ń��X�|�[��
    }

    m_modelRender.Update();
}


void Enemy::Render(RenderContext& rc)
{
    if (!m_isAlive) return;
    m_modelRender.Draw(rc);
}
