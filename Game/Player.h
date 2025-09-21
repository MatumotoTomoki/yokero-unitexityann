#pragma once
//�v���C���[�N���X�B
class Player :public IGameObject
{
public:
	Player();
	~Player();
	//�X�V�����B
	void Update();
	//�`�揈���B
	void Render(RenderContext& rc);
	//�ړ������B
	void Move();
	//��]�����B
	void Rotation();
	//�X�e�[�g�Ǘ��B
	void ManageState();
	//�A�j���[�V�����̍Đ��B
	void PlayAnimation();
	void AddSpeedBoost(float amount, int duration); // �A�C�e�����ʂ��󂯂�
	void TakeDamage(int damage);   // �_���[�W���󂯂鏈��
	bool IsAlive() const { return m_life > 0; }
	float m_speedMultiplier = 1.0f;
	float m_speed = 5.0f;        // �ʏ푬�x
	float m_currentSpeed = 5.0f; // ���̑��x�i�A�C�e���ŕω��j
	int m_speedBoostTimer = 0;   // �c��t���[����
	//�����o�[�ϐ��B
	ModelRender m_modelRender;//���f�������_�[�B
	Vector3 m_position;//���W
	enum EnAnimationClip {//�A�j���[�V�����B
		enAnimationClip_Idle,
		enAnimationClip_Run,
		enAnimationClip_Jump,
		enAnimationClip_Num,
	};
	AnimationClip m_animationClips[enAnimationClip_Num];//�A�j���[�V�����N���b�v�B
	CharacterController m_characterController;//�L�����N�^�[�R���g���[���[�B
	Vector3 m_moveSpeed;//�ړ����x�B
	Quaternion m_rotation;  //�N�H�[�^�j�I���B
	int playerState = 0;//�v���C���[�̃X�e�[�g�i���)
	int m_life = 3;      // �������C�t3
	int m_invincibleTimer = 0; // ���G�t���[����
	FontRender m_lifeFont; // ���C�t�\���p
};