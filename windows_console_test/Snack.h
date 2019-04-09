#pragma once
#include<string>
#include"SnackConsole.h"
namespace snack_n {
	// ̰����С��Ϸ���ߵĶ������ͣ�

// �ߵ����壬��Ƴ�һ�����ͣ�������Ӧ��һ������ö�٣�����һ��content ���ʵ����
//�ߵ�ͷ�������Ϊһ����������壬���з���ö�٣�����û��preve����
// ������������ ����ת ������ת��
// ���沿�����ö������
	enum SNACK_FACE_DIRECTION
	{
		UP, DOWN, LEFT, RIGHT
	};
	// �������������� next Ϊ����Ϊβ�ͣ�prev Ϊ����Ϊͷ��������Ϊ����
	// ǰ����ʱ����x+1 ����Y+1 ������
	// ǰ����ʱ���ж�ǰ��һ���ĳ����Ƿ���Լ���һ���������һ���Ļ����޸ĳ���ͬ������ǰ���һ��
	struct  SnackBody
	{
		// ����ö��
		SNACK_FACE_DIRECTION direction;
		// ����һ��
		SnackBody *next;
		// ǰ��һ��
		SnackBody *prev;
		// λ�� ͷ��Ϊ0
		int index;
		// x����
		int X;
		// Y����
		int Y;
	};

	class Snack
	{
	public:
		Snack(const console_n::SnackConsole &console);
		~Snack();
		// ��ת����
		void turnLeft();
		// ��ת����
		void turnRight();
		// �ж��Ƿ���
		bool isLive();
		// �����ٶ�( �ƻ��� 0--10)
		void setSpeed(int speed);
		// �ٶ�+1 ��10 ����
		void speedAdd();
		// �ٶ�-1 ��0 ����
		void speedSubtract();
		// �ƶ�(�����ٶ�,���� �����ƶ�)
		void move();
	private:
		// ָʾ��ǰ����(ͷ��)
		static SNACK_FACE_DIRECTION direction;
		const console_n::SnackConsole console;
	};


}
