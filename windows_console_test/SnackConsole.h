#pragma once
#include <Windows.h>
#include<iostream>
#include"console_tools.h"
namespace console_n {
	// ����̨��
	// ����̨��Ϣ��ʵ�� 1. ���Ƶ�ǰ���ƴ��ڵı߽磬2.���洰�ڵ���Ϣ��3.��մ�����Ϣ��4�����������Ϣ��������
	using std::cout;
	using std::endl;
	class SnackConsole
	{
	public:
		
		// ���ݿ�Ⱥ͸߶�����ʼ������
		// borderSize �߿��ȣ�Ĭ�ϵ���1
		// ���Ϊ���������ÿ�Ⱥ͸߶�Ϊ����
		SnackConsole(int width,int height,int borderSize = 1);
		~SnackConsole();

		// ��ȡ����̨��� ��������ϼ���������ȡ�ϼ������ģ������������ȡ������µģ�
		HANDLE getHandel() const;

		// ���ø�������
		void setParent(SnackConsole *parent);


		// �ж��Ƿ��и�������
		bool  haveParent() const;

		// ��ȡ����λ����Ϣ �Ӽ�����ռ�õĵط������Ҵ��� �߿���ַ����� �Ӽ������������Ϻ��£�������ҵ�˳�����
		COORD getNextStart() const;
		void setNextStart(short x, short y);

		// ����
		void draw();
	private :
		const int width;
		const int height;
		// ��� �������Ϊ�գ����Ϊ0��0 �������ѯ��������λ����+�߿��Ⱥ��������
		COORD start; 
		//�յ� ͬstart 
		COORD end; 
		// ָ����һ���Ӽ������λ�ã�������border��
		COORD nextStart;
		// ��������
		const SnackConsole *parent=NULL; 
		
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		// �߿���
		int borderSize ; 
		// ��Ⱥ͸߶ȵı�����׼���ڼ�����������ʱ��ʹ��
		int widthScale = 5;
		int heightScale = 5;

		void computeStartPoint();
		void computeEndPoint();
		void fillContent(char f_char,int fillNumber,int attr = BACKGROUND_RED);
	};


}

