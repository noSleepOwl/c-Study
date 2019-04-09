#pragma once
#include<string>

// ̰����С��Ϸ���ߵĶ������ͣ�

// �ߵ����壬��Ƴ�һ�����ͣ�������Ӧ��һ������ö�٣�����һ��content ���ʵ����
//�ߵ�ͷ�������Ϊһ����������壬���з���ö�٣�����û��preve����
// ������������ ����ת ������ת��
// ���沿�����ö������
enum SNACK_FACE_DIRECTION
{
	UP,DOWN,LEFT,RIGHT
};
// �������������� next Ϊ����Ϊβ�ͣ�prev Ϊ����Ϊͷ��������Ϊ����
// ǰ����ʱ����x+1 ����Y+1 ������
// ǰ����ʱ���ж�ǰ��һ���ĳ����Ƿ���Լ���һ���������һ���Ļ����޸ĳ���ͬ������ǰ���һ��

struct  SnackBody
{
	SNACK_FACE_DIRECTION direction;
	SnackBody *next;
	SnackBody *prev;
	int index;
	int X;  // x λ��
	int Y; // y λ��
};

class Snack
{
public:
	Snack();
	~Snack();
	void turnLeft(); // ��ת����
	void turnRight();// ��ת����
	bool isLive();  // �ж��Ƿ���
};

