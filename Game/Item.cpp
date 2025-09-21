#include "stdafx.h"
#include "Item.h"

struct ItemSpawnPair {
    Vector3 start;
    Vector3 goal;
};

static std::vector<ItemSpawnPair> spawnPairs = {
    { { -1239.32f, -50.0f, -1450.31f }, { 1294.64f, -50.0f, 1423.91f } },
    { { 649.96f,   -50.0f, 1788.96f },  { -1899.03f, -50.0f, 205.41f } },
    { { 1921.11f,  -50.0f, -302.63f },  { -1894.63f, -50.0f, 284.36f } },
    { { 1831.24f,  -50.0f, -372.61f },  { 0.0f, -50.0f, -1937.72f } },
    { { 0.0f,      -50.0f, 1877.84f },  { -500.0f, -50.0f, -1800.0f } }
};

Item::Item()
{
    m_modelRender.Init("Assets/modelData/Item.tkm");
    Respawn();
}

Item::~Item() {}

void Item::Respawn()
{
    int index = rand() % spawnPairs.size();
    m_spawnPos = spawnPairs[index].start;
    m_goalPos = spawnPairs[index].goal;

    m_position = m_spawnPos;
    m_direction = m_goalPos - m_spawnPos;
    m_direction.Normalize();

    m_modelRender.SetPosition(m_position);
    m_modelRender.Update();

    m_isAlive = true;
    m_respawnTimer = 0;

    
}

void Item::OnPickup()
{
    m_isAlive = false;
    m_respawnTimer = m_respawnDelay;
}

void Item::Update()
{
    if (!m_isAlive) {
        if (m_respawnTimer > 0) {
            m_respawnTimer--;
            if (m_respawnTimer <= 0) {
                Respawn();
            }
        }
        return;
    }

    // ===== ˆÚ“®ˆ— =====
    m_position += m_direction * m_speed;
    m_modelRender.SetPosition(m_position);

    // ƒS[ƒ‹“ž’B‚µ‚½‚çÁ–Å
    if ((m_goalPos - m_position).Length() < 10.0f) {
        m_isAlive = false;
        m_respawnTimer = m_respawnDelay;
    }

    m_modelRender.Update();
}

void Item::Render(RenderContext& rc)
{
    if (!m_isAlive) return;
    m_modelRender.Draw(rc);
}
