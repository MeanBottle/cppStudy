#pragma once
#include "gameNode.h"

class pixelCollisionScene : public gameNode
{
private:
	image* _forest;			//백그라운드 이미지
	//image* _mountain2;	//백그라운드 원본 이미지
	RECT _backgroundrc;		//백그라운드 원본 이미지 렉트
	image* _ball;			//공이미지
	RECT _rc;				//공 렉트

	float _x, _y;			//위치좌표
	int _probeY;			//픽셀충돌 탐지할 Y값
	int _probeX;			//픽셀충돌 탐지할 X값
	int _probeX2;			//픽셀충돌 탐지할 X값2
	int _probeY2;			//픽셀충돌 탐지할 Y값2
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	pixelCollisionScene() {}
	~pixelCollisionScene() {}
};

