#pragma once
#include "singletonBase.h"
class camera : public singletonBase<camera>
{
private:
	RECT cameraRc;		//ī�޶� ��Ʈ
	POINTFLOAT _center;		//���� �߽����� �׸� ��Ʈ ����

public:
	RECT cameraMake(RECT rc);
	void SetBallCenter(POINTFLOAT center);
	RECT getBallCenter() { return cameraRc; }
	camera() {}
	~camera() {}
};