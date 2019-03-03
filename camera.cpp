#include "stdafx.h"
#include "camera.h"

RECT camera::cameraMake(RECT rc)
{
	
	RECT _temp;
	_temp.left = rc.left - cameraRc.left;
	_temp.right = rc.right - cameraRc.left;
	_temp.top = rc.top = cameraRc.top;
	_temp.bottom = rc.bottom - cameraRc.top;
	return _temp;
}

void camera::SetBallCenter(POINTFLOAT center)
{
	_center = center;
	cameraRc = RectMakeCenter(_center.x, _center.y, WINSIZEX, WINSIZEY);
	if (cameraRc.left < 0)
	{
		_center.x = WINSIZEX/2;

	}
	if (cameraRc.right > 640)
	{
		_center.x = 640 - WINSIZEX/2;
	}
	if (cameraRc.top < 0)
	{
		_center.y = WINSIZEY / 2;
	}
	if (cameraRc.bottom > 576)
	{
		_center.y = 576 - WINSIZEY / 2;

	}
	cameraRc = RectMakeCenter(_center.x, _center.y, WINSIZEX, WINSIZEY);
	
}
