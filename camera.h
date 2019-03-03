#pragma once
#include "singletonBase.h"
class camera : public singletonBase<camera>
{
private:
	RECT cameraRc;		//카메라 렉트
	POINTFLOAT _center;		//볼을 중심으로 그릴 렉트 선언

public:
	RECT cameraMake(RECT rc);
	void SetBallCenter(POINTFLOAT center);
	RECT getBallCenter() { return cameraRc; }
	camera() {}
	~camera() {}
};