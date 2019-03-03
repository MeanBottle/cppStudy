#include "stdafx.h"
#include "mainGame.h"
//=============================================================
//	## �ʱ�ȭ ## init(void)
//=============================================================
HRESULT mainGame::init(void)
{
	gameNode::init(TRUE);
	//�̰����� �ʱ�ȭ�� �Ѵ�

	//������ ���ΰ��� Ŭ���� �ȿ����� ���鸸 ������ �Ѵ�
	//�׸��� ������ ������ ���ΰ��� ������ �ϸ� �ȴ�

	/*���߰�*/
	SCENEMANAGER->addScene("�׽�Ʈ��", new sceneTest);
	SCENEMANAGER->addScene("�ȼ��浹", new pixelCollisionScene);

	//����� ����
	SCENEMANAGER->loadScene("�ȼ��浹");

	return S_OK;
	//return S_OK; �Ʒ��� �ڵ尡 ������ �ȵ�!!!
}

//=============================================================
//	## ���� ## release(void)
//=============================================================
void mainGame::release(void)
{
	gameNode::release();
}

//=============================================================
//	## ������Ʈ ## update(void)
//=============================================================
void mainGame::update(void)
{
	gameNode::update();

	//���Ŵ��� ������Ʈ
	SCENEMANAGER->update();
	
}

//=============================================================
//	## ���� ## render(void)
//=============================================================
void mainGame::render(void)
{
	//��� �� ��Ʈ�� (�̰͵� ������ �׳� �α�)
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
//=============================================================

	//���Ŵ��� ����
	SCENEMANAGER->render();

//=============================================================
	//������� ������ HDC�� �׸��� (�̰͵� ������ �׳� �α�)
	this->getBackBuffer()->render(getHDC());
}

