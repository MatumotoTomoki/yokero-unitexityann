#pragma once
//プレイヤークラス。
class Player :public IGameObject
{
public:
	Player();
	~Player();
	//更新処理。
	void Update();
	//描画処理。
	void Render(RenderContext& rc);
	//移動処理。
	void Move();
	//回転処理。
	void Rotation();
	//ステート管理。
	void ManageState();
	//アニメーションの再生。
	void PlayAnimation();
	void AddSpeedBoost(float amount, int duration); // アイテム効果を受ける
	void TakeDamage(int damage);   // ダメージを受ける処理
	bool IsAlive() const { return m_life > 0; }
	float m_speedMultiplier = 1.0f;
	float m_speed = 5.0f;        // 通常速度
	float m_currentSpeed = 5.0f; // 今の速度（アイテムで変化）
	int m_speedBoostTimer = 0;   // 残りフレーム数
	//メンバー変数。
	ModelRender m_modelRender;//モデルレンダー。
	Vector3 m_position;//座標
	enum EnAnimationClip {//アニメーション。
		enAnimationClip_Idle,
		enAnimationClip_Run,
		enAnimationClip_Jump,
		enAnimationClip_Num,
	};
	AnimationClip m_animationClips[enAnimationClip_Num];//アニメーションクリップ。
	CharacterController m_characterController;//キャラクターコントローラー。
	Vector3 m_moveSpeed;//移動速度。
	Quaternion m_rotation;  //クォータニオン。
	int playerState = 0;//プレイヤーのステート（状態)
	int m_life = 3;      // 初期ライフ3
	int m_invincibleTimer = 0; // 無敵フレーム数
	FontRender m_lifeFont; // ライフ表示用
};