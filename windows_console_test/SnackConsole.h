#pragma once
#include <Windows.h>
namespace console_n {
	// ����̨��
	// ����̨��Ϣ��ʵ�� 1. ���Ƶ�ǰ���ƴ��ڵı߽磬2.���洰�ڵ���Ϣ��3.��մ�����Ϣ��4�����������Ϣ��������
	class SnackConsole
	{
	public:
		// ���ݿ�Ⱥ͸߶�����ʼ������
		// borderSize �߿��ȣ�Ĭ�ϵ���1
		SnackConsole(int width,int height,int borderSize = 1);
		~SnackConsole();

		// ��ȡ����̨��� ��������ϼ���������ȡ�ϼ������ģ������������ȡ������µģ�
		HANDLE getHandel() const;

		// ���ø�������
		void setParent(SnackConsole *parent);

		// ��ȡ��������
		SnackConsole * getParent() const;

		// �ж��Ƿ��и�������
		bool  haveParent() const;

		// ��ȡ����λ����Ϣ
		SMALL_RECT getUnwanted() const; 

	private :
		// ��� �������Ϊ�գ����Ϊ0��0 �������ѯ��������λ����+�߿��Ⱥ��������
		COORD start; 
		//�յ� ͬstart 
		COORD end; 
		// ��������
		const SnackConsole *parent=NULL; 
		HANDLE handle = NULL;
		// �߿���
		int borderSize ; 
	
	};


}

