#pragma once
class Stage : public IGameObject
{
public:
	Stage();
	~Stage();
	//�`��֐��B
	void Render(RenderContext& rc);

	//���f�������_�\�B        
	ModelRender modelRender;
	PhysicsStaticObject physicsStaticObject;
	Vector3 m_position;

};

