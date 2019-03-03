#pragma once
#include "gameNode.h"
#include "bullet.h"			//�̻��� Ŭ���� ����ϱ� ����
#include "progressBar.h"	//ü�¹� Ŭ������ ����ϱ� ����


//#include "enemyManager.h"
//���Ŵ��� ��ȣ�����ϱ� ���� Ŭ���� ���漱��
class enemyManager;

class player : public gameNode
{
private:
	image* _rocket;			//����(�÷��̾�) �̹���
	missile* _missile;		//�̻��� Ŭ����
	missileM1* _missileM1;	//�̻���M1 Ŭ����

	enemyManager* _em;		//�����Ҵ� �ϸ� �ȵȴ�!!!
	//���ΰ��ӿ��� ������ em�� ���⼭ �����Ҵ��ع��� em�� 
	//���� �ٸ� �޸��ּҶ� ���� ������ �� ������

	progressBar* _hpBar;		//ü�¹�
	float _maxHp, _currentHp;	//�ִ�ü��, ����ü��

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	//�̻���M1 �Ѿ� ����
	void removeMissileM1(int index);

	//�浹�Լ�
	void collision();

	//ü�¹� ������
	void hitDamage(float damage);

	//�÷��̾� �̹��� ��������
	image* getPlayerImg() { return _rocket; }
	
	//�̻���M1 Ŭ���� ��������
	missileM1* getMissileM1() { return _missileM1; }

	//��ȣ������ ���Ŵ��������͸� �ѱ� �����Լ�
	void setEMLink(enemyManager* em) { _em = em; }


	player() {}
	~player() {}
};
