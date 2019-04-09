#pragma once
#include <Windows.h>
namespace console_n {
	// ����̨��
	// ����̨��Ϣ��ʵ�� 1. ���Ƶ�ǰ���ƴ��ڵı߽磬2.���洰�ڵ���Ϣ��3.��մ�����Ϣ��4�����������Ϣ��������
	class SnackConsole
	{
	public:
		// ��������ͨ������������������Ϣ start ���Ͻ���ʼ�㣬 end ���½ǽ����� 
		// borderSize �߿��ȣ�Ĭ�ϵ���1
		SnackConsole(COORD start,COORD end,int borderSize = 1);
		~SnackConsole();
		// ���ÿ���̨��������û�����ý��Ӹ����л�ȡ��������˵�Ϊnull ���쳣
		// Ҳ����˵������������ handle ���������һ��
		void setHandel(HANDLE handle);  
		// ��ȡ����̨��� 
		HANDLE getHandel() const;
		// �ж��Ƿ��п���̨���
		bool haveHandel() const;
		// ���ø�������
		void setParent(SnackConsole *parent);
		// ��ȡ��������
		SnackConsole * getParent() const;
		// �ж��Ƿ��и�������
		bool  haveParent() const;
	private :
		// ���
		COORD start; 
		//�յ�
		COORD end; 
		// ��������
		const SnackConsole *parent=NULL; 
		HANDLE handle = NULL;
		// �߿���
		int borderSize ; 
	
	};


}

