#include "stdafx.h"
#include "pixelCollisionScene.h"

HRESULT pixelCollisionScene::init(void)
{
	//��׶��� �̹���
	_forest = IMAGEMANAGER->addImage("forest", "forest.bmp", 640, 576);
	//��׶���  �����̹���
	//_mountain2 = IMAGEMANAGER->addImage("mountain2", "mountain2.bmp", 640, 576);

	//��׶��� ��Ʈ
	_backgroundrc = RectMake(0, 0, WINSIZEX, WINSIZEY);

	//���̹���
	_ball = IMAGEMANAGER->addImage("ball", "ball.bmp", 10, 10, true, RGB(255, 0, 255));

	//�� ��ġ �ʱ�ȭ
	_x = WINSIZEX / 2;
	_y = WINSIZEY / 2;
	_rc = RectMakeCenter(_x, _y, _ball->getWidth(), _ball->getHeight());
	
	//y������ Ž��(���� �ϴܿ��� �˻���)
	_probeY = _y + _ball->getHeight() / 2;	//�ϴ�
	_probeX = _x + _ball->getWidth() / 2;	//����
	_probeX2 = _x - _ball->getWidth() / 2;	//����
	_probeY2 = _y - _ball->getHeight() / 2;	//���

	return S_OK;
}

void pixelCollisionScene::release(void)
{
}

void pixelCollisionScene::update(void)
{
	CA->SetBallCenter({ _x,_y });

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_x -= 3.0f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_x += 3.0f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_y -= 3.0f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_y += 3.0f;
	}

	//���� ��Ʈ�� �����̱�
	_rc = RectMakeCenter(_x, _y, _ball->getWidth(), _ball->getHeight());

	//y������ Ž��(���� �ϴ��� ������Ʈ)
	_probeY = _y + _ball->getHeight() / 2;
	_probeX = _x + _ball->getWidth() / 2;
	_probeY2 = _y - _ball->getHeight() / 2;
	_probeX2 = _x - _ball->getWidth() / 2;

	/*�̺κ��� �ȼ��浹�� �ٽ�*/
	//Ž���� Y���� ������ �����ط� ���ϴ� ��ŭ �˻縦 �Ѵ�
	//��
	for (int i = _probeY; i < _probeY + 3; i++)
	{
		COLORREF color = GetPixel(_forest->getMemDC(), _x, i);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);
	
		if ((r == 255 && g == 0 && b == 255))
		{
			_y = i - _ball->getHeight() / 2 - 3 ;
			break;
		}
	}
	//�� 
	for (int i = _probeY2; i < _probeY2 + 3; i++)
	{
		COLORREF color = GetPixel(_forest->getMemDC(), _x, i);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);
		if ((r == 255 && g == 0 && b == 255))
		{
			_y =i +_ball->getHeight() / 2 + 3;
			break;
		}
	}
	//��
	for (int i = _probeX; i < _probeX + 3; i++)
	{
		COLORREF color = GetPixel(_forest->getMemDC(), i, _y);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);
	
		if ((r == 255 && g == 0 && b == 255))
		{
			_x = i - _ball->getWidth() / 2 -3;
			break;
		}
	}	
	//��
	for (int i = _probeX2; i < _probeX2 + 3; i++)
	{
		COLORREF color = GetPixel(_forest->getMemDC(), i, _y);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int	b = GetBValue(color);
		if ((r == 255 && g == 0 && b == 255))
		{
			_x = i + _ball->getWidth() / 2 + 3;
			break;
		}
	
	}
	/*if (KEYMANAGER->isOnceKeyDown('1'))
	{
		SCENEMANAGER->loadScene("�׽�Ʈ��");
	}*/

}

void pixelCollisionScene::render(void)
{
	_forest->render(getMemDC(), _backgroundrc.left- CA->getBallCenter().left, _backgroundrc.top- CA->getBallCenter().top);
	
	if (KEYMANAGER->isToggleKey('A'))
	{
		//��׶��� ����
		//_mountain->render(getMemDC(), _backgroundrc.left - CA->getBallCenter().left, _backgroundrc.top - CA->getBallCenter().top);

		Rectangle(getMemDC(), _rc);

		////���� �簢�� ����
		//RECT rc = RectMakeCenter(_x, _probeY, 5, 5);
		//RECT rc1 = RectMakeCenter(_probeX, _y, 5, 5);
		//RECT rc2 = RectMakeCenter(_x, _probeY2, 5, 5);
		//RECT rc3 = RectMakeCenter(_probeX2, _y, 5, 5);
		////����
		//Rectangle(getMemDC(), rc);
		//Rectangle(getMemDC(), rc1);
		////�¿�
		//Rectangle(getMemDC(), rc2);
		//Rectangle(getMemDC(), rc3);

	}
	//�� �̹��� ����
	_ball->render(getMemDC(), _rc.left - CA->getBallCenter().left, _rc.top - CA->getBallCenter().top);

}
