#pragma once
#include<string>
#include<iostream>
// ����string ��Ҫʹ��
using namespace std;
class Persion
{
public:
	string name; 
	int age;
	static string countory;
	Persion();
	Persion(string name,int age);
	Persion(const Persion &persion);
	~Persion();
	friend void printName(Persion persion);
	// ���� ������ , ֮�����ʵ�� 
	void talkSelf(void);
	// ��������ʵ��
	void talkSelf_2(void) {
		cout << "�ҵ�������" << name << "�ҽ���" << age << "����" << endl;
	}
private :
	string code = "3203212155456456464";
	int *ptr;
};


class Student : public Persion {
public :
	string school;
	void talkSelf(void);
	Student operator+();
};

