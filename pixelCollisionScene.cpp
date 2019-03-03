#include "stdafx.h"
#include "pixelCollisionScene.h"

HRESULT pixelCollisionScene::init(void)
{
	//백그라운드 이미지
	_forest = IMAGEMANAGER->addImage("forest", "forest.bmp", 640, 576);
	//백그라운드  원본이미지
	//_mountain2 = IMAGEMANAGER->addImage("mountain2", "mountain2.bmp", 640, 576);

	//백그라운드 렉트
	_backgroundrc = RectMake(0, 0, WINSIZEX, WINSIZEY);

	//공이미지
	_ball = IMAGEMANAGER->addImage("ball", "ball.bmp", 10, 10, true, RGB(255, 0, 255));

	//공 위치 초기화
	_x = WINSIZEX / 2;
	_y = WINSIZEY / 2;
	_rc = RectMakeCenter(_x, _y, _ball->getWidth(), _ball->getHeight());
	
	//y축으로 탐지(공의 하단에서 검사함)
	_probeY = _y + _ball->getHeight() / 2;	//하단
	_probeX = _x + _ball->getWidth() / 2;	//우측
	_probeX2 = _x - _ball->getWidth() / 2;	//좌측
	_probeY2 = _y - _ball->getHeight() / 2;	//상단

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

	//공의 렉트도 움직이기
	_rc = RectMakeCenter(_x, _y, _ball->getWidth(), _ball->getHeight());

	//y축으로 탐지(공의 하단의 작은렉트)
	_probeY = _y + _ball->getHeight() / 2;
	_probeX = _x + _ball->getWidth() / 2;
	_probeY2 = _y - _ball->getHeight() / 2;
	_probeX2 = _x - _ball->getWidth() / 2;

	/*이부분이 픽셀충돌의 핵심*/
	//탐지할 Y값의 범위를 위아해로 원하는 만큼 검사를 한다
	//하
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
	//상 
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
	//우
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
	//좌
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
		SCENEMANAGER->loadScene("테스트씬");
	}*/

}

void pixelCollisionScene::render(void)
{
	_forest->render(getMemDC(), _backgroundrc.left- CA->getBallCenter().left, _backgroundrc.top- CA->getBallCenter().top);
	
	if (KEYMANAGER->isToggleKey('A'))
	{
		//백그라운드 렌더
		//_mountain->render(getMemDC(), _backgroundrc.left - CA->getBallCenter().left, _backgroundrc.top - CA->getBallCenter().top);

		Rectangle(getMemDC(), _rc);

		////작은 사각형 렌더
		//RECT rc = RectMakeCenter(_x, _probeY, 5, 5);
		//RECT rc1 = RectMakeCenter(_probeX, _y, 5, 5);
		//RECT rc2 = RectMakeCenter(_x, _probeY2, 5, 5);
		//RECT rc3 = RectMakeCenter(_probeX2, _y, 5, 5);
		////오하
		//Rectangle(getMemDC(), rc);
		//Rectangle(getMemDC(), rc1);
		////좌우
		//Rectangle(getMemDC(), rc2);
		//Rectangle(getMemDC(), rc3);

	}
	//공 이미지 렌더
	_ball->render(getMemDC(), _rc.left - CA->getBallCenter().left, _rc.top - CA->getBallCenter().top);

}
