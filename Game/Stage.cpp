#include "stdafx.h"
#include "Stage.h"

Stage::Stage()
{
	//�����蔻��
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	modelRender.Init("Assets/modelData/strs1.tkm");
	modelRender.Update();
	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix());

}
Stage::~Stage()
{

}

void Stage::Render(RenderContext& rc)
{
	//���f����`�悷��B

	modelRender.Draw(rc);
}