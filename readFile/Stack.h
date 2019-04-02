#pragma once
#include<vector> // ����������
#include<stdexcept>  // ��׼�쳣

using namespace std;

template <class T> 
class Stack
{
public:
	void push(T const& element); // ��ջ
	void pop(); // ɾ������
	T pop()const; // ���ض�ջ����Ԫ��
	bool isEmpty() const;  // �Ƿ�Ϊ�� �� Ϊ�շ���true
	Stack(const Stack &stack);
	Stack();
private:
	vector<T> elements; // Ԫ��
};

