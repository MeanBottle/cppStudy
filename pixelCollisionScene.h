#pragma once
#include "gameNode.h"

class pixelCollisionScene : public gameNode
{
private:
	image* _forest;			//��׶��� �̹���
	//image* _mountain2;	//��׶��� ���� �̹���
	RECT _backgroundrc;		//��׶��� ���� �̹��� ��Ʈ
	image* _ball;			//���̹���
	RECT _rc;				//�� ��Ʈ

	float _x, _y;			//��ġ��ǥ
	int _probeY;			//�ȼ��浹 Ž���� Y��
	int _probeX;			//�ȼ��浹 Ž���� X��
	int _probeX2;			//�ȼ��浹 Ž���� X��2
	int _probeY2;			//�ȼ��浹 Ž���� Y��2
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	pixelCollisionScene() {}
	~pixelCollisionScene() {}
};

