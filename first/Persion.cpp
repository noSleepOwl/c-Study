#include "pch.h"
#include "Persion.h"


string Persion::countory = "china";

Persion::Persion()
{
}

// ���ٵĽ��г�ʼ��
Persion::Persion(string name, int age):name(name),age(age)
{

}

Persion::Persion(const Persion & persion)
{
	ptr = new int;
	*ptr = *persion.ptr;
}

Persion::~Persion()
{
	cout << "Persion���������Ѿ�ִ��" << endl;
}

void Persion::talkSelf(void)
{
	cout << "�ҵ�������" << name << "�ҽ���" << age << "����" << endl;
	cout << "�ҵ����֤������:" <<code << endl;
}
/*��Ҫע����ǣ��ú����������κε��� ��ֻ��һ������*/
void printName(Persion persion)
{
	cout << persion.code << endl; // �˴���code Ϊ private ��
	// ��Ϊ��Ԫ���������Է��ʶ����ڲ���private  ��protected ���ε����Ժͷ�����
}

void Student::talkSelf(void)
{
	cout<< "����XXX" <<endl;
}

Student Student::operator+()
{
	
	return Student();
}
